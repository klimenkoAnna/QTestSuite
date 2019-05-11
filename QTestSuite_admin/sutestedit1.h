#ifndef SUTESTEDIT1_H
#define SUTESTEDIT1_H

#include <QDialog>

namespace Ui {
class SUTestEdit1;
}

class SUTestEdit1 : public QDialog
{
    Q_OBJECT

public:
    explicit SUTestEdit1(QWidget *parent = 0);
    ~SUTestEdit1();

private:
    Ui::SUTestEdit1 *ui;
};

#endif // SUTESTEDIT1_H
