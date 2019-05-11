/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Tue 25. Dec 00:19:22 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QLabel *label;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 300);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setMaximumSize(QSize(51, 20));

        horizontalLayout->addWidget(lineEdit_3);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout->addWidget(lineEdit_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QTestSuite", 0));
        action->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\260\320\264\320\274\320\270\320\275/\321\201\321\202\321\203\320\264\320\265\320\275\321\202", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\260", 0));
        lineEdit_3->setInputMask(QApplication::translate("MainWindow", "9999; ", 0));
        lineEdit_3->setText(QApplication::translate("MainWindow", "1234", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0));
        lineEdit_4->setInputMask(QApplication::translate("MainWindow", ">aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa; ", 0));
        lineEdit_4->setText(QApplication::translate("MainWindow", "ME", 0));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">* \320\235\320\260\320\277\320\270\321\201\320\260\320\275\320\270\320\265 </span><span style=\" font-size:8pt; font-weight:600;\">\320\270\320\274\320\265\320\275\320\270</span><span style=\" font-size:8pt;\"> \320\270\320\273\320\270 \320\270\320\275\320\270\321\206\320\270\320\260\320\273\320\276\320\262 </span><span style=\" font-size:8pt; font-weight:600;\">\320\275\320\265</span><span style=\" font-size:8pt;\"> \320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\320\276.</span></p>\n"
"<p"
                        " style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">* \320\237\320\276\320\273\320\275</span><span style=\" font-size:8pt; font-weight:600;\">\320\276\320\265 \321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\217 </span><span style=\" font-size:8pt;\">\321\204\320\260\320\274\320\270\320\273\320\270\321\217 (+\320\270\320\274\321\217) \320\262 \321\200\320\260\320\267\320\275\321\213\321\205 \321\202\320\265\321\201\321\202\320\260\321\205 </span><span style=\" font-size:8pt; font-weight:600;\">\320\275\320\265</span><span style=\" font-size:8pt;\"> \320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\320\276.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">* </span><span style=\" font-size:8pt; font-weight:6"
                        "00;\">\320\222\321\200\320\265\320\274\321\217</span><span style=\" font-size:8pt;\"> \320\275\320\260\321\207\320\260\320\273\320\260 \321\202\320\265\321\201\321\202\320\260 \320\267\320\260\320\277\320\270\321\201\321\213\320\262\320\260\320\265\321\202\321\201\321\217.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">* </span><span style=\" font-size:8pt; font-weight:600;\">\320\236\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\265\320\275\320\275\320\276\321\201\321\202\321\214</span><span style=\" font-size:8pt;\"> \320\277\321\200\320\270:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\260) \320\275\320\265\320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\274 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275"
                        "\320\270\320\270 \320\264\320\260\320\275\320\275\321\213\321\205 \320\277\320\276\320\273\320\265\320\271;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\261) \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\270 \320\275\320\260\320\277\320\270\321\201\320\260\320\275\320\270\321\217 \320\277\320\276\320\273\321\217  \321\204\320\260\320\274\320\270\320\273\320\270\321\217 (+\320\270\320\274\321\217) \321\201 \321\206\320\265\320\273\321\214\321\216 \320\277\320\276\320\262\321\202\320\276\321\200\320\275\320\276\320\263\320\276 \320\277\321\200\320\276\321\205\320\276\320\266\320\264\320\265\320\275\320\270\321\217 \321\202\320\265\321\201\321\202\320\260</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- \320\273\320\265\320\266\320\270\321\202 \320"
                        "\275\320\260 </span><span style=\" font-size:8pt; font-weight:600;\">\321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\265</span><span style=\" font-size:8pt;\">.</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\225\320\240\320\225\320\231\320\242\320\230 \320\232 \320\222\320\253\320\221\320\236\320\240\320\243 \320\242\320\225\320\241\320\242\320\220", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
