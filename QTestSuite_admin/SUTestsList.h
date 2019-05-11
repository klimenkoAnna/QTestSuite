#ifndef SUTESTSLIST_H
#define SUTESTSLIST_H

#include <QtWidgets/QDialog>

namespace Ui {
class SUTestsList;
}

class SUTestsList : public QDialog
{
    Q_OBJECT

public:
    explicit SUTestsList(QWidget *parent = 0);
    ~SUTestsList();

signals:
    void GoToSUTestResults();
    void GoToSUTestEdit();
    void GoToLoginWnd();

private slots:
    void updateUI();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::SUTestsList *ui;
};

#endif // SUTESTSLIST_H
