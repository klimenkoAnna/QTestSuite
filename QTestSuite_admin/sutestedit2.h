#ifndef SUTESTEDIT2_H
#define SUTESTEDIT2_H

#include <QDialog>

namespace Ui {
class SUTestEdit2;
}

class SUTestEdit2 : public QDialog
{
    Q_OBJECT

public:
    explicit SUTestEdit2(QWidget *parent = 0);
    ~SUTestEdit2();

private:
    Ui::SUTestEdit2 *ui;
};

#endif // SUTESTEDIT2_H
