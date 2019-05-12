/********************************************************************************
** Form generated from reading UI file 'sutestedit2.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUTESTEDIT2_H
#define UI_SUTESTEDIT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SUTestEdit2
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QPushButton *pushButton_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QTextEdit *textEdit;
    QWidget *widget2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_3;
    QLineEdit *lineEdit_3;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *SUTestEdit2)
    {
        if (SUTestEdit2->objectName().isEmpty())
            SUTestEdit2->setObjectName(QStringLiteral("SUTestEdit2"));
        SUTestEdit2->resize(520, 403);
        layoutWidget = new QWidget(SUTestEdit2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 90, 441, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);

        label_4 = new QLabel(SUTestEdit2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 200, 241, 16));
        pushButton_6 = new QPushButton(SUTestEdit2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(380, 350, 91, 23));
        widget = new QWidget(SUTestEdit2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 60, 441, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        widget1 = new QWidget(SUTestEdit2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 120, 441, 64));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        textEdit = new QTextEdit(widget1);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_3->addWidget(textEdit);

        widget2 = new QWidget(SUTestEdit2);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(30, 230, 441, 52));
        gridLayout = new QGridLayout(widget2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox = new QCheckBox(widget2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_4->addWidget(checkBox);

        lineEdit = new QLineEdit(widget2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkBox_2 = new QCheckBox(widget2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_5->addWidget(checkBox_2);

        lineEdit_2 = new QLineEdit(widget2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_5->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout_5, 0, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkBox_4 = new QCheckBox(widget2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_7->addWidget(checkBox_4);

        lineEdit_4 = new QLineEdit(widget2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_7->addWidget(lineEdit_4);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        checkBox_3 = new QCheckBox(widget2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_6->addWidget(checkBox_3);

        lineEdit_3 = new QLineEdit(widget2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_6->addWidget(lineEdit_3);


        gridLayout->addLayout(horizontalLayout_6, 1, 1, 1, 1);

        widget3 = new QWidget(SUTestEdit2);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(410, 30, 61, 25));
        horizontalLayout_8 = new QHBoxLayout(widget3);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_8->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_8->addWidget(pushButton_2);

        widget4 = new QWidget(SUTestEdit2);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(190, 320, 281, 25));
        horizontalLayout_9 = new QHBoxLayout(widget4);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(widget4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_9->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_9->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_9->addWidget(pushButton_5);

        label->raise();
        comboBox->raise();
        layoutWidget->raise();
        label_3->raise();
        textEdit->raise();
        label_4->raise();
        lineEdit->raise();
        checkBox->raise();
        lineEdit_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();

        retranslateUi(SUTestEdit2);

        QMetaObject::connectSlotsByName(SUTestEdit2);
    } // setupUi

    void retranslateUi(QDialog *SUTestEdit2)
    {
        SUTestEdit2->setWindowTitle(QApplication::translate("SUTestEdit2", "Dialog", 0));
        label_2->setText(QApplication::translate("SUTestEdit2", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", 0));
        label_4->setText(QApplication::translate("SUTestEdit2", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\321\213 \320\276\321\202\320\262\320\265\321\202\320\260 \320\270 \320\276\321\202\320\274\320\265\321\202\321\214\321\202\320\265 \320\262\320\265\321\200\320\275\321\213\320\271", 0));
        pushButton_6->setText(QApplication::translate("SUTestEdit2", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        label->setText(QApplication::translate("SUTestEdit2", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\265\320\274\321\203", 0));
        label_3->setText(QApplication::translate("SUTestEdit2", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\276\320\277\321\200\320\276\321\201", 0));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        checkBox_4->setText(QString());
        checkBox_3->setText(QString());
        pushButton->setText(QApplication::translate("SUTestEdit2", "<<", 0));
        pushButton_2->setText(QApplication::translate("SUTestEdit2", ">>", 0));
        pushButton_3->setText(QApplication::translate("SUTestEdit2", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        pushButton_4->setText(QApplication::translate("SUTestEdit2", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        pushButton_5->setText(QApplication::translate("SUTestEdit2", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262\321\201\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class SUTestEdit2: public Ui_SUTestEdit2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUTESTEDIT2_H
