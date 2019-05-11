#ifndef SUADDTEST_H
#define SUADDTEST_H

#include <QDialog>

namespace Ui {
class SUAddTest;
}

class SUAddTest : public QDialog
{
    Q_OBJECT

public:
    explicit SUAddTest(QWidget *parent = 0);
    ~SUAddTest();

private:
    Ui::SUAddTest *ui;
private slots:
    void OkEnabled();
    void on_SaveButton_clicked();
};

#endif // SUADDTEST_H
