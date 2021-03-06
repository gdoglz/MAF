/*
 *  mafTextEditorWidget.cpp
 *  mafGUI
 *
 *  Created by Daniele Giunchi on 14/01/11.
 *  Copyright 2010 B3C. All rights reserved.
 *
 *  See Licence at: http://tiny.cc/QXJ4D
 *
 */

#include "mafTextEditWidget.h"
#include <QHBoxLayout>

using namespace mafGUI;

mafTextEditWidget::mafTextEditWidget(QWidget *parent): QWidget(parent), m_TextEditor(NULL), m_Highlighter(NULL) {
    initialize();
}

mafTextEditWidget::mafTextEditWidget(QSyntaxHighlighter *highlighter, QWidget *parent): QWidget(parent), m_TextEditor(NULL), m_Highlighter(highlighter) {
   initialize();
}

void mafTextEditWidget::initialize() {
    QVBoxLayout *hboxLayout = new QVBoxLayout( this );
    hboxLayout->setMargin(0);

    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    m_TextEditor = new QTextEdit(this);
    m_TextEditor->setFont(font);

    if(m_Highlighter) {
        m_Highlighter->setDocument(m_TextEditor->document());
    }

    //sample test
    m_TextEditor->setText("vme Path New! Don't hate us, matrix users. It turns out that the driver reported in millimeters, rather than the VRPN stated standard of meters. One of the users noticed this, so I've changed version 2.27 to be compliant to the standard. The good news is that it now matches all of the other trackers. The bad news is that you'll need to change your code if you relied on it being in mm.New! Version 7.27 switched to the new InterSense libraries. Previous versions used the old ones. The new code that was submitted is not backwards compatible with the old libraries. So you can (and must) upgrade your Intersense libraries for the new version");
    hboxLayout->addWidget(m_TextEditor);
}

mafTextEditWidget::~mafTextEditWidget() {
    delete m_TextEditor;
}

void mafTextEditWidget::setHighlighter(QSyntaxHighlighter *highlighter) {
    REQUIRE(highlighter);
    m_Highlighter->setDocument(m_TextEditor->document());
}

void mafTextEditWidget::enableEditing(bool enable) {
    m_TextEditor->setReadOnly(!enable);
}

void mafTextEditWidget::loadDictionaryFromCSV(const mafString &csvFile) {
    ///read from a csv file
}
