import lxml.etree as etree
from lxml.etree import XSLT,fromstring
import os, sys, string, stat
from os.path import exists, join
from os import pathsep
from string import split
import shutil
from datetime import datetime
import getopt

def usage():
    print "Usage: python Formatter.py [--enable-LCOVCoverage]"

def search_file(filename, search_path):
   """Given a search path, find file
   """
   file_found = 0
   paths = string.split(search_path, pathsep)
   for path in paths:
      print path, filename
      if exists(join(path, filename)):
          file_found = 1
          break
   if file_found:
      return abspath(join(path, filename))
   else:
      return None

def run(param):
   #read xml file
   scriptsDir = os.getcwd()
   os.chdir("../../")
   baseDir = os.getcwd()
   qaResultsDir = baseDir + "/QAResults/";
   xmlDir = baseDir + "/QAResults/xml"

   if not os.path.exists(xmlDir):
     print "Xml Directory not present"
     sys.exit(1)
    
   htmlDir = baseDir + "/QAResults/html"

   if not os.path.exists(htmlDir):
     os.makedirs(htmlDir)
   if not os.path.exists(htmlDir+ "/Styles"):  
     os.makedirs(htmlDir + "/Styles")

   if(os.path.exists(htmlDir + "/Styles")):
     shutil.rmtree(htmlDir + "/Styles")
     shutil.copytree(scriptsDir + "/Styles",htmlDir + "/Styles/")
     if(os.path.exists(htmlDir+ "/Styles/.svn")):
       for root, dirs, files in os.walk(htmlDir + "/Styles/.svn", topdown=False):
         for name in files:
             filename = os.path.join(root, name)
             os.chmod(filename, stat.S_IWUSR)
             os.remove(filename)
         for name in dirs:
             os.rmdir(os.path.join(root, name))
       os.chmod(htmlDir + "/Styles/.svn", stat.S_IWUSR)
       os.rmdir(htmlDir + "/Styles/.svn")
     
   xmlList=os.listdir(xmlDir)
   htmlList=[file.replace(".xml", ".html") for file in os.listdir(xmlDir)]

   ruleLinksString = ""
   for link in htmlList:
     if(link != "index.html" and link != "Styles"):
       ruleLinksString = ruleLinksString + "<li><a href=\"" + link + "\">" + link[:link.find(".")] + "</a></li>\n"

   xsltH = """<xsl:stylesheet version="2.0"
           xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
   <xsl:output indent="yes"/>
   <xsl:template name="break">
           <xsl:param name="text"/>
           <xsl:choose>
                   <xsl:when test="contains($text, '&#xa;')">
                           <xsl:value-of select="substring-before($text, '&#xa;')"/>
                           <br/>
                           <xsl:call-template name="break">
                                   <xsl:with-param name="text" select="substring-after($text,'&#xa;')"/>
                           </xsl:call-template>
                   </xsl:when>
                   <xsl:otherwise>
                   <xsl:value-of select="$text"/>
                   </xsl:otherwise>
           </xsl:choose>
   </xsl:template>
   <xsl:template match="/">"""

   xsltT = """
   </xsl:template>
   </xsl:stylesheet>
   """

   headString = "".join(open(htmlDir + "/Styles/head.temp"))
   headString = headString.replace("@@@_PUBLISH_DATE_@@@", str( datetime.now().date()))
   centerString = "".join(open(htmlDir + "/Styles/center.temp"))
   tailString = "".join(open(htmlDir + "/Styles/tail.temp"))
   
   #check for external scripting
   if(param['LCOVCoverage']):
      #generateExternalLink
      
      externalScriptDirectory = scriptsDir + "/ExternalScripts"
      os.chdir(externalScriptDirectory)
      os.system("python " + externalScriptDirectory + "/LCOVCoveragePublish.py")
      pos = headString.find("@@@_EXTERNAL_TOOLS_REPORT_@@@")-1
      
      os.chdir(scriptsDir);
      headString = headString[:pos] + "<li><a href=\"../externalLCOVCoverage/index.html\">LCOV Coverage</a></li>" + headString[pos:]

   #remove placeholder for external scripting
   headString = headString.replace("@@@_EXTERNAL_TOOLS_REPORT_@@@", "")


   result = True
   for xmlFile in xmlList:
     try:
       filename = os.path.splitext(xmlFile)[0]
       print "Formatting in HTML " + filename
       #with lxml parse the file
       f = open(xmlDir + "/" + xmlFile,'r')
       xml = fromstring(str(f.read()))

       #with lxml create html
       searchF = filename  + ".xslt"
       absPathXslt = ""
       for top, dirs, files in os.walk('./'):
         for nm in files:
           if(nm == searchF):
             absPathXslt = os.path.join(top, nm)

       fileXslt = open(absPathXslt, 'r') 
       #print xsltH + headString + centerString + str(fileXslt.read()) + tailString + xsltT
       xsl=  fromstring(xsltH + headString + ruleLinksString + centerString + str(fileXslt.read()) + tailString + xsltT) 
       style = XSLT(xsl)
       result = style.apply(xml)
           
       #print htmlDir + filename + ".html"
       html = open(htmlDir + "/" + filename + ".html", 'w')
       print >> html , style.tostring(result)
     except Exception, e:
       result = False
       print "!!!!!!Bad Formatted XML on ", filename , "!!!!!!!"
       print e
       os.chdir(scriptsDir)
       
   #if(result == true):
   print "PUBLISH SUCCESSFUL"
   
   index = open(htmlDir + "/index.html", 'w')
   
   
   introduction = """
   <h1>introduction</h1>
           <!-- **** INSERT PAGE CONTENT HERE **** -->
             <h2>Quality Assurance System</h2>
           <p> 
           The system is composed by several components and it works as a state machine. In order to complete the entire cycle which terminates with the publishing of the QA Results over internet, the needed steps are the following:
           <ul>
           <li> Build Documentation<br/> Each rule needs a source directory in which extracts information from a specified file types. Most part of QA scripts takes advantage from doxygen XML output that is created as first step. A script can also base its execution over another kind of source directory like code directory, and even extract information discriminating files using regular-expression.

             At present there are three source information used by scripts: doxygen xml output of the code without Tests and with Tests, Maf3 source directory.

             Operativelly after installing doxygen 1.5.9 in your computer, you need to run build_doc.bat for windows , or build_doc.sh for Unix like system. They'll be created two directories named Doc and DocWithTests in the same path.</li>
           <li>Generate python scripts<br/> GeneratorQA.py must be launched to create all the scripts based on RuleGroups and Rules inside the last.

             This script checks RuleGroups contained in Rules directory, and create for every RuleGroup a correspondent script with all the rules defined inside. Each RuleGroup and each Rule inside a rulegroup need an initialization file in order to handle parameters. Generally the initialization file of a RuleGroup contain the file type checked and the source directory, while the rule initialization file contains parameter which depends by the rule itself.

             Additionally GeneratorQA.py creates a file with the list of generated scripts.</li>
           <li>Execute generated scripts<br/> ScriptsLauncher.py fulfils the work of executing each generated script. The results are written in a bunch of files in QAResults directory at the root level of the local repository. These are subdivided into a number of files equals to the total number of rule.</li>
           <li>Publish the results<br/> On Parabuild the mechanism described above is present in Linux Server and Windows Server while only on Linux one is present the publication of the results. The publication is only the results of moving result files in a directory that is visible using Apache server.</li>

           </p>
   """
   index.write("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">")
   index.write(headString)
   index.write(ruleLinksString)
   index.write(centerString)
   index.write(introduction)
   index.write(tailString)
   index.close()

   

   os.chdir(scriptsDir)

def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], "l", ["enable-LCOVCoverage",])
    except getopt.GetoptError:
        usage()
        sys.exit(2)
        
    LCOVCoverageFlag = False
    for o, a in opts:
        if o in ("-l", "--enable-LCOVCoverage"):
            LCOVCoverageFlag = True
        else:
            assert False, "unhandled option"

    param = {'LCOVCoverage':LCOVCoverageFlag}
    run(param)


if __name__ == "__main__":
  main()


