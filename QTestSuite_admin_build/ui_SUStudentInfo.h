/********************************************************************************
** Form generated from reading UI file 'SUStudentInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSTUDENTINFO_H
#define UI_SUSTUDENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SUStudentInfo
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_11;

    void setupUi(QDialog *SUStudentInfo)
    {
        if (SUStudentInfo->objectName().isEmpty())
            SUStudentInfo->setObjectName(QStringLiteral("SUStudentInfo"));
        SUStudentInfo->resize(400, 300);
        gridLayout = new QGridLayout(SUStudentInfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(SUStudentInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 7, 0, 1, 1);

        lineEdit_3 = new QLineEdit(SUStudentInfo);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 5, 1, 1, 1);

        lineEdit = new QLineEdit(SUStudentInfo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 3, 1, 1, 1);

        label_8 = new QLabel(SUStudentInfo);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        label_10 = new QLabel(SUStudentInfo);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        label_7 = new QLabel(SUStudentInfo);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_9 = new QLabel(SUStudentInfo);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 2, 1, 1, 1);

        label_6 = new QLabel(SUStudentInfo);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(SUStudentInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(SUStudentInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(SUStudentInfo);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 4, 1, 1, 1);

        label_4 = new QLabel(SUStudentInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(SUStudentInfo);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(SUStudentInfo);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(SUStudentInfo);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 1, 1, 1);

        label_11 = new QLabel(SUStudentInfo);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_11->setWordWrap(true);

        gridLayout->addWidget(label_11, 6, 1, 1, 1);


        retranslateUi(SUStudentInfo);

        QMetaObject::connectSlotsByName(SUStudentInfo);
    } // setupUi

    void retranslateUi(QDialog *SUStudentInfo)
    {
        SUStudentInfo->setWindowTitle(QApplication::translate("SUStudentInfo", "Dialog", 0));
        pushButton->setText(QApplication::translate("SUStudentInfo", "\320\235\320\260\320\267\320\260\320\264", 0));
        label_8->setText(QApplication::translate("SUStudentInfo", "TextLabel", 0));
        label_10->setText(QApplication::translate("SUStudentInfo", "\320\234\320\275\320\265\320\275\320\270\320\265 CLIPS:", 0));
        label_7->setText(QApplication::translate("SUStudentInfo", "TextLabel", 0));
        label_9->setText(QApplication::translate("SUStudentInfo", "TextLabel", 0));
        label_6->setText(QApplication::translate("SUStudentInfo", "\320\237\321\200\320\265\320\267\320\265\320\275\321\202\320\260\321\206\320\270\321\217", 0));
        label_2->setText(QApplication::translate("SUStudentInfo", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0));
        label_3->setText(QApplication::translate("SUStudentInfo", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\260\320\275\321\217\321\202\320\270\320\271", 0));
        label_4->setText(QApplication::translate("SUStudentInfo", "\320\237\320\276\321\201\320\265\321\211\320\265\320\275\320\275\321\213\321\205 \320\267\320\260\320\275\321\217\321\202\320\270\320\271", 0));
        label->setText(QApplication::translate("SUStudentInfo", "\320\223\321\200\321\203\320\277\320\277\320\260", 0));
        label_5->setText(QApplication::translate("SUStudentInfo", "\320\220\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\321\214", 0));
        pushButton_2->setText(QApplication::translate("SUStudentInfo", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        label_11->setText(QApplication::translate("SUStudentInfo", "\320\227\320\264\320\265\321\201\321\214 \320\261\321\203\320\264\320\265\321\202 \320\274\320\275\320\265\320\275\320\270\320\265 CLIPS", 0));
    } // retranslateUi

};

namespace Ui {
    class SUStudentInfo: public Ui_SUStudentInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSTUDENTINFO_H
