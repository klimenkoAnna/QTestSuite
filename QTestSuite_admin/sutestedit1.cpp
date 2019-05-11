#include "sutestedit1.h"
#include "ui_sutestedit1.h"

SUTestEdit1::SUTestEdit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUTestEdit1)
{
    ui->setupUi(this);
}

SUTestEdit1::~SUTestEdit1()
{
    delete ui;
}
