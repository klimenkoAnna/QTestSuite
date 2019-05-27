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

    void on_label_9_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    void updateData(bool setScore,bool updStudent,bool scoreFromSpinBox);
    Ui::SUStudentInfo *ui;
};

#endif // SUSTUDENTINFO_H
