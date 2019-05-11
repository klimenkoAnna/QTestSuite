#include "TestResultsWindow.h"
#include "ui_TestResultsWindow.h"
#include "qtestsuite_shareddefs.h"

TestResultsWindow::TestResultsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestResultsWindow)
{
    ui->setupUi(this);
}

TestResultsWindow::~TestResultsWindow()
{
    delete ui;
}


void TestResultsWindow::updateUI()
{
    int minScore = 0;
    int maxScore = 0;
    int maxPossibleScore = 0;
    getScores( minScore, maxScore, maxPossibleScore );

    ui->label->setText( QString::fromLocal8Bit( "%1 - %2\n%3\nРезультат: от %4 до %5*\n(из возможных %6)\n\n* Письменные ответы будут проверены преподавателем." )
                .arg( curStud->groupNum.value() )
                .arg( stdstr_to_qstr( curStud->surname.value() ) )
                .arg( stdstr_to_qstr( curTest->testName.value() ) )
                .arg(minScore).arg(maxScore).arg(maxPossibleScore) );
}

void TestResultsWindow::on_pushButton_clicked()
{
    emit GoToLoginWnd();
}


