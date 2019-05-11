#ifndef SUTESTRESULTS_H
#define SUTESTRESULTS_H

#include <QtWidgets/QDialog>

namespace Ui {
class SUTestResults;
}

class SUTestResults : public QDialog
{
    Q_OBJECT
    
public:
    explicit SUTestResults(QWidget *parent = 0);
    ~SUTestResults();

signals:
    void GoToSUStudentInfo();
    void GoToSUTestsLits();
    void GoToSUStudResults();

private slots:
    void updateUI();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::SUTestResults *ui;
};

#endif // SUTESTRESULTS_H
