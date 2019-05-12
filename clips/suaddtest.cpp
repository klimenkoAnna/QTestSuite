#include "suaddtest.h"
#include "ui_suaddtest.h"

SUAddTest::SUAddTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUAddTest)
{
    ui->setupUi(this);
}

SUAddTest::~SUAddTest()
{
    delete ui;
}
