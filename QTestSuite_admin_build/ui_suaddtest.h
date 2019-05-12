/********************************************************************************
** Form generated from reading UI file 'suaddtest.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUADDTEST_H
#define UI_SUADDTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SUAddTest
{
public:
    QPushButton *SaveButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *OkButton;
    QPushButton *CloseButton;

    void setupUi(QDialog *SUAddTest)
    {
        if (SUAddTest->objectName().isEmpty())
            SUAddTest->setObjectName(QStringLiteral("SUAddTest"));
        SUAddTest->resize(549, 360);
        SaveButton = new QPushButton(SUAddTest);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(350, 310, 75, 23));
        widget = new QWidget(SUAddTest);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 206, 55));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        OkButton = new QPushButton(widget);
        OkButton->setObjectName(QStringLiteral("OkButton"));

        horizontalLayout_2->addWidget(OkButton);

        CloseButton = new QPushButton(widget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));

        horizontalLayout_2->addWidget(CloseButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(SUAddTest);
        QObject::connect(OkButton, SIGNAL(clicked()), SUAddTest, SLOT(accept()));
        QObject::connect(CloseButton, SIGNAL(clicked()), SUAddTest, SLOT(reject()));

        QMetaObject::connectSlotsByName(SUAddTest);
    } // setupUi

    void retranslateUi(QDialog *SUAddTest)
    {
        SUAddTest->setWindowTitle(QApplication::translate("SUAddTest", "Dialog", 0));
        SaveButton->setText(QApplication::translate("SUAddTest", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        label->setText(QApplication::translate("SUAddTest", "Enter text", 0));
        OkButton->setText(QApplication::translate("SUAddTest", "OK", 0));
        CloseButton->setText(QApplication::translate("SUAddTest", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SUAddTest: public Ui_SUAddTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUADDTEST_H
