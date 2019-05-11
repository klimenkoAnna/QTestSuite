#ifndef SUSTUDENTINFO_H
#define SUSTUDENTINFO_H

#include <QDialog>

namespace Ui {
class SUStudentInfo;
}

class SUStudentInfo : public QDialog
{
    Q_OBJECT

signals:
    void GoToSUTestResults();

public:
    explicit SUStudentInfo(QWidget *parent = 0);
    ~SUStudentInfo();

private slots:
    void updateUI();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::SUStudentInfo *ui;
};

#endif // SUSTUDENTINFO_H
