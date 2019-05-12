/********************************************************************************
** Form generated from reading UI file 'TestResultsWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTRESULTSWINDOW_H
#define UI_TESTRESULTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TestResultsWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *TestResultsWindow)
    {
        if (TestResultsWindow->objectName().isEmpty())
            TestResultsWindow->setObjectName(QStringLiteral("TestResultsWindow"));
        TestResultsWindow->resize(300, 150);
        gridLayout = new QGridLayout(TestResultsWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(TestResultsWindow);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(TestResultsWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(TestResultsWindow);

        QMetaObject::connectSlotsByName(TestResultsWindow);
    } // setupUi

    void retranslateUi(QDialog *TestResultsWindow)
    {
        TestResultsWindow->setWindowTitle(QApplication::translate("TestResultsWindow", "QTestSuite", 0));
        label->setText(QApplication::translate("TestResultsWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("TestResultsWindow", "\320\222\321\213\320\271\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class TestResultsWindow: public Ui_TestResultsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTRESULTSWINDOW_H
