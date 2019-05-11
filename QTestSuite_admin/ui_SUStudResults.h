/********************************************************************************
** Form generated from reading UI file 'SUStudResults.ui'
**
** Created: Tue 25. Dec 00:19:32 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSTUDRESULTS_H
#define UI_SUSTUDRESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SUStudResults
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_1;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_2a;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *SUStudResults)
    {
        if (SUStudResults->objectName().isEmpty())
            SUStudResults->setObjectName(QString::fromUtf8("SUStudResults"));
        SUStudResults->resize(500, 300);
        gridLayout_2 = new QGridLayout(SUStudResults);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout_1"));
        verticalLayout_1->setSizeConstraint(QLayout::SetMinimumSize);
        label_1 = new QLabel(SUStudResults);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);
        label_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_1->addWidget(label_1);

        label_2 = new QLabel(SUStudResults);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_1->addWidget(label_2);

        label_3 = new QLabel(SUStudResults);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setScaledContents(false);
        label_3->setWordWrap(true);

        verticalLayout_1->addWidget(label_3);

        label_4 = new QLabel(SUStudResults);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_1->addWidget(label_4);


        verticalLayout->addLayout(verticalLayout_1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_2a = new QVBoxLayout();
        verticalLayout_2a->setObjectName(QString::fromUtf8("verticalLayout_2a"));

        horizontalLayout_3->addLayout(verticalLayout_2a);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(SUStudResults);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(SUStudResults);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(SUStudResults);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SUStudResults);

        QMetaObject::connectSlotsByName(SUStudResults);
    } // setupUi

    void retranslateUi(QDialog *SUStudResults)
    {
        SUStudResults->setWindowTitle(QApplication::translate("SUStudResults", "QTestSuite", 0));
        label_1->setText(QApplication::translate("SUStudResults", "TextLabel", 0));
        label_2->setText(QApplication::translate("SUStudResults", "TextLabel", 0));
        label_3->setText(QApplication::translate("SUStudResults", "TextLabel", 0));
        label_4->setText(QApplication::translate("SUStudResults", "TextLabel", 0));
        pushButton_2->setText(QApplication::translate("SUStudResults", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271", 0));
        pushButton_3->setText(QApplication::translate("SUStudResults", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271", 0));
        pushButton->setText(QApplication::translate("SUStudResults", "\320\232\320\276 \320\262\321\201\320\265\320\274 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\260\320\274", 0));
    } // retranslateUi

};

namespace Ui {
    class SUStudResults: public Ui_SUStudResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSTUDRESULTS_H
