#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QtWidgets/QDialog>

namespace Ui {
class TestWindow;
}

class TestWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit TestWindow(QWidget *parent = 0);
    ~TestWindow();

private:
    void selfUpdateUI();
    void saveChanges();

signals:
    void GoToTestResultsWnd();
    void GoToTestSelectWnd();

private slots:
    void updateUI();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TestWindow *ui;
};

#endif // TESTWINDOW_H
