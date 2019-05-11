#ifndef TESTSELECTWINDOW_H
#define TESTSELECTWINDOW_H

#include <QtWidgets/QDialog>

namespace Ui {
class TestSelectWindow;
}

class TestSelectWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit TestSelectWindow(QWidget *parent = 0);
    ~TestSelectWindow();

signals:
    void GoToTestWnd();
    
private slots:
    void updateUI();

    void on_pushButton_clicked();

private:
    Ui::TestSelectWindow *ui;
};

#endif // TESTSELECTWINDOW_H
