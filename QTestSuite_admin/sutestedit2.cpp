#include "sutestedit2.h"
#include "ui_sutestedit2.h"

SUTestEdit2::SUTestEdit2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUTestEdit2)
{
    ui->setupUi(this);
}

SUTestEdit2::~SUTestEdit2()
{
    delete ui;
}
