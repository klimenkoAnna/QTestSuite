#ifndef SUSTUDRESULTS_H
#define SUSTUDRESULTS_H

#include <QtWidgets/QDialog>

namespace Ui {
class SUStudResults;
}

class SUStudResults : public QDialog
{
    Q_OBJECT
    
public:
    explicit SUStudResults(QWidget *parent = 0);
    ~SUStudResults();

private:
    void selfUpdateUI();

signals:
    void GoToSUTestResults();
    
private slots:
    void updateUI();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SUStudResults *ui;
};

#endif // SUSTUDRESULTS_H
