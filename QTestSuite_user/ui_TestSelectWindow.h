/********************************************************************************
** Form generated from reading UI file 'TestSelectWindow.ui'
**
** Created: Tue 25. Dec 00:19:22 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSELECTWINDOW_H
#define UI_TESTSELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TestSelectWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *TestSelectWindow)
    {
        if (TestSelectWindow->objectName().isEmpty())
            TestSelectWindow->setObjectName(QString::fromUtf8("TestSelectWindow"));
        TestSelectWindow->resize(500, 300);
        gridLayout = new QGridLayout(TestSelectWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(TestSelectWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(TestSelectWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(TestSelectWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(TestSelectWindow);

        QMetaObject::connectSlotsByName(TestSelectWindow);
    } // setupUi

    void retranslateUi(QDialog *TestSelectWindow)
    {
        TestSelectWindow->setWindowTitle(QApplication::translate("TestSelectWindow", "QTestSuite", 0));
        label->setText(QApplication::translate("TestSelectWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("TestSelectWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\202\320\265\321\201\321\202", 0));
    } // retranslateUi

};

namespace Ui {
    class TestSelectWindow: public Ui_TestSelectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSELECTWINDOW_H
