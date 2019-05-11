/********************************************************************************
** Form generated from reading UI file 'SUTestEdit.ui'
**
** Created: Fri 4. Jan 14:39:11 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUTESTEDIT_H
#define UI_SUTESTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SUTestEdit
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QCheckBox *checkBoxQuestionPicture;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *questionPicture;
    QFrame *line_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *line_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QPushButton *pushButton_6;
    QFrame *line;

    void setupUi(QDialog *SUTestEdit)
    {
        if (SUTestEdit->objectName().isEmpty())
            SUTestEdit->setObjectName(QString::fromUtf8("SUTestEdit"));
        SUTestEdit->resize(500, 300);
        gridLayout_2 = new QGridLayout(SUTestEdit);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label = new QLabel(SUTestEdit);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_10->addWidget(label);

        label_2 = new QLabel(SUTestEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_10->addWidget(label_2);

        plainTextEdit = new QPlainTextEdit(SUTestEdit);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_10->addWidget(plainTextEdit);

        checkBoxQuestionPicture = new QCheckBox(SUTestEdit);
        checkBoxQuestionPicture->setObjectName(QString::fromUtf8("checkBoxQuestionPicture"));

        verticalLayout_10->addWidget(checkBoxQuestionPicture);

        scrollArea = new QScrollArea(SUTestEdit);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 354, 57));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        questionPicture = new QLabel(scrollAreaWidgetContents);
        questionPicture->setObjectName(QString::fromUtf8("questionPicture"));

        gridLayout->addWidget(questionPicture, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_10->addWidget(scrollArea);

        line_3 = new QFrame(SUTestEdit);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_3);


        gridLayout_2->addLayout(verticalLayout_10, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(SUTestEdit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(SUTestEdit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(SUTestEdit);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        line_2 = new QFrame(SUTestEdit);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        pushButton_4 = new QPushButton(SUTestEdit);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(SUTestEdit);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_3 = new QLabel(SUTestEdit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setWordWrap(true);

        verticalLayout->addWidget(label_3);

        pushButton_6 = new QPushButton(SUTestEdit);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 1, 1);

        line = new QFrame(SUTestEdit);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 1, 1, 1);


        retranslateUi(SUTestEdit);

        QMetaObject::connectSlotsByName(SUTestEdit);
    } // setupUi

    void retranslateUi(QDialog *SUTestEdit)
    {
        SUTestEdit->setWindowTitle(QApplication::translate("SUTestEdit", "QTestSuite", 0));
        label->setText(QApplication::translate("SUTestEdit", "TextLabel", 0));
        label_2->setText(QApplication::translate("SUTestEdit", "TextLabel", 0));
        plainTextEdit->setPlainText(QString());
        checkBoxQuestionPicture->setText(QApplication::translate("SUTestEdit", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\272 \320\262\320\276\320\277\321\200\320\276\321\201\321\203", 0));
        questionPicture->setText(QApplication::translate("SUTestEdit", "questionPicture", 0));
        pushButton->setText(QApplication::translate("SUTestEdit", "\320\235\320\260\320\267\320\260\320\264 \320\272 \321\202\320\265\321\201\321\202\320\260\320\274", 0));
        pushButton_2->setText(QApplication::translate("SUTestEdit", "<<<", 0));
        pushButton_3->setText(QApplication::translate("SUTestEdit", ">>>", 0));
        pushButton_4->setText(QApplication::translate("SUTestEdit", "+ \320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\276\320\277\321\200\320\276\321\201", 0));
        pushButton_5->setText(QApplication::translate("SUTestEdit", "\342\200\223 \320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\320\276\320\277\321\200\320\276\321\201", 0));
        label_3->setText(QApplication::translate("SUTestEdit", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">\320\237\321\200\320\270 \320\276\321\202\321\201\321\203\321\202\321\201\321\202\320\262\320\270\320\270 \320\276\321\202\320\262\320\265\321\202\320\276\320\262 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\321\203 \320\261\321\203\320\264\320\265\321\202 \320\277\321\200\320\265\320\264\320\273\320\276\320\266\320\265\320\275\320\276 \320\275\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \321\201\320\262\320\276\320\271 \320\276\321\202\320\262\320\265\321\202</span></p></body></h"
                        "tml>", 0));
        pushButton_6->setText(QApplication::translate("SUTestEdit", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\321\202\320\262\320\265\321\202", 0));
    } // retranslateUi

};

namespace Ui {
    class SUTestEdit: public Ui_SUTestEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUTESTEDIT_H
