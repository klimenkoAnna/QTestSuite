#include "TestSelectWindow.h"
#include "ui_TestSelectWindow.h"
#include <QtWidgets/QMessageBox>
#include "qtestsuite_shareddefs.h"

TestSelectWindow::TestSelectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestSelectWindow)
{
    ui->setupUi(this);
}

TestSelectWindow::~TestSelectWindow()
{
    delete ui;
}

void TestSelectWindow::updateUI()
{
    if( !curStud )
    {
        throw Except( "Ошибка программы." );
    }

    std::vector <TestSuite::Test> tests;

    try
    {
        tests = select<TestSuite::Test>( *pDB ).all();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        return;
    }

    #if QTESTSUITE_HIDE_FINISHED_TESTS

    for( int i = 0; i < tests.size(); ++i )
    {
        // erase tests that were done already.
        try
        {
            tests[i].students().get( TestSuite::Student::Surname == curStud->surname ).one();
            // here: we didn't fail == student already made this test, remove it.
            tests.erase( tests.begin() + i );
            continue;
        }
        catch( Except e )
        {
            // here: we failed == there were no such test done.
        }
    }

    #endif

    ui->listWidget->clear();

    std::vector <TestSuite::Test>::iterator it = tests.begin();
    for( ; it != tests.end(); ++it )
    {
        new QListWidgetItem( stdstr_to_qstr( (*it).testName.value() ), ui->listWidget );
    }

    ui->label->setText( QString( "%1 - %2" )
                        .arg( curStud->groupNum.value() )
                        .arg( stdstr_to_qstr( curStud->surname.value() ) ) );

    if( !tests.size() )
    {
        QMessageBox::warning( NULL, "QTestSuite",
                              QString::fromLocal8Bit( "Нет тестов." ),
                              QMessageBox::Ok, QMessageBox::Ok );
    }
}

void TestSelectWindow::on_pushButton_clicked() // begin test
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if( !item )
    {
        return;
    }

    if( curTest )
    {
        delete curTest;
        curTest = NULL;
    }

    try
    {
        TestSuite::Test test = select <Test>( *pDB, Test::TestName == qstr_to_stdstr( item->text() ) ).one();
        curTest = new TestSuite::Test( test );

        if( QMessageBox( QString::fromLocal8Bit("QTestSuite"),
                         QString::fromLocal8Bit("Вы уверены, что хотите начать тест?"),
                         QMessageBox::Question, QMessageBox::Yes, QMessageBox::No, 0 ).exec()
                != QMessageBox::Yes )
        {
            return;
        }

        emit GoToTestWnd();
    }
    catch( Except e )
    {
    }
}
