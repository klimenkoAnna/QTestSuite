/********************************************************************************
** Form generated from reading UI file 'SUTestResults.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUTESTRESULTS_H
#define UI_SUTESTRESULTS_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SUTestResults
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *SUTestResults)
    {
        if (SUTestResults->objectName().isEmpty())
            SUTestResults->setObjectName(QStringLiteral("SUTestResults"));
        SUTestResults->resize(500, 300);
        gridLayout = new QGridLayout(SUTestResults);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SUTestResults);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(SUTestResults);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(341, 0));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(SUTestResults);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(SUTestResults);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(SUTestResults);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SUTestResults);

        QMetaObject::connectSlotsByName(SUTestResults);
    } // setupUi

    void retranslateUi(QDialog *SUTestResults)
    {
        SUTestResults->setWindowTitle(QApplication::translate("SUTestResults", "QTestSuite", 0));
        label->setText(QApplication::translate("SUTestResults", "TextLabel", 0));
        pushButton->setText(QApplication::translate("SUTestResults", "\320\235\320\260\320\267\320\260\320\264 \320\272 \321\202\320\265\321\201\321\202\320\260\320\274", 0));
        pushButton_2->setText(QApplication::translate("SUTestResults", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\276\321\202\320\262\320\265\321\202\321\213", 0));
        pushButton_3->setText(QApplication::translate("SUTestResults", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", 0));
    } // retranslateUi

};

namespace Ui {
    class SUTestResults: public Ui_SUTestResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUTESTRESULTS_H
