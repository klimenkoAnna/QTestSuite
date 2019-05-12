/********************************************************************************
** Form generated from reading UI file 'sutestedit1.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUTESTEDIT1_H
#define UI_SUTESTEDIT1_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SUTestEdit1
{
public:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *Themelabel;
    QListWidget *themelistWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *AddThemeButton;
    QPushButton *DelThemeButton;
    QPushButton *RenameThemeButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *SUTestEdit1)
    {
        if (SUTestEdit1->objectName().isEmpty())
            SUTestEdit1->setObjectName(QStringLiteral("SUTestEdit1"));
        SUTestEdit1->resize(549, 239);
        saveButton = new QPushButton(SUTestEdit1);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(330, 190, 75, 23));
        cancelButton = new QPushButton(SUTestEdit1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(410, 190, 75, 23));
        pushButton = new QPushButton(SUTestEdit1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 160, 101, 23));
        pushButton_2 = new QPushButton(SUTestEdit1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 160, 111, 23));
        widget = new QWidget(SUTestEdit1);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 20, 431, 131));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Themelabel = new QLabel(widget);
        Themelabel->setObjectName(QStringLiteral("Themelabel"));

        gridLayout->addWidget(Themelabel, 0, 0, 1, 1);

        themelistWidget = new QListWidget(widget);
        themelistWidget->setObjectName(QStringLiteral("themelistWidget"));

        gridLayout->addWidget(themelistWidget, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        AddThemeButton = new QPushButton(widget);
        AddThemeButton->setObjectName(QStringLiteral("AddThemeButton"));

        verticalLayout->addWidget(AddThemeButton);

        DelThemeButton = new QPushButton(widget);
        DelThemeButton->setObjectName(QStringLiteral("DelThemeButton"));

        verticalLayout->addWidget(DelThemeButton);

        RenameThemeButton = new QPushButton(widget);
        RenameThemeButton->setObjectName(QStringLiteral("RenameThemeButton"));

        verticalLayout->addWidget(RenameThemeButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);


        retranslateUi(SUTestEdit1);

        QMetaObject::connectSlotsByName(SUTestEdit1);
    } // setupUi

    void retranslateUi(QDialog *SUTestEdit1)
    {
        SUTestEdit1->setWindowTitle(QApplication::translate("SUTestEdit1", "Dialog", 0));
        saveButton->setText(QApplication::translate("SUTestEdit1", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        cancelButton->setText(QApplication::translate("SUTestEdit1", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        pushButton->setText(QApplication::translate("SUTestEdit1", "\320\232 \321\201\320\277\320\270\321\201\320\272\321\203 \321\202\320\265\321\201\321\202\320\276\320\262", 0));
        pushButton_2->setText(QApplication::translate("SUTestEdit1", "\320\232 \321\201\320\277\320\270\321\201\320\272\321\203 \320\262\320\276\320\277\321\200\320\276\321\201\320\276\320\262", 0));
        Themelabel->setText(QApplication::translate("SUTestEdit1", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\202\320\265\320\274", 0));
        AddThemeButton->setText(QApplication::translate("SUTestEdit1", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\265\320\274\321\203", 0));
        DelThemeButton->setText(QApplication::translate("SUTestEdit1", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\265\320\274\321\203", 0));
        RenameThemeButton->setText(QApplication::translate("SUTestEdit1", "\320\237\320\265\321\200\320\265\320\270\320\274\320\265\320\275\320\276\320\262\320\260\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class SUTestEdit1: public Ui_SUTestEdit1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUTESTEDIT1_H
