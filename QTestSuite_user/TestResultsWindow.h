#ifndef TESTRESULTSWINDOW_H
#define TESTRESULTSWINDOW_H

#include <QtWidgets/QDialog>

namespace Ui {
class TestResultsWindow;
}

class TestResultsWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit TestResultsWindow(QWidget *parent = 0);
    ~TestResultsWindow();

signals:
    void GoToLoginWnd();
    
private slots:
    void updateUI();

    void on_pushButton_clicked();

private:
    Ui::TestResultsWindow *ui;
};

#endif // TESTRESULTSWINDOW_H
