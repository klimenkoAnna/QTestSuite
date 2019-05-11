#include "SUTestsList.h"
#include "ui_SUTestsList.h"
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QInputDialog>
#include "qtestsuite_shareddefs.h"

SUTestsList::SUTestsList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUTestsList)
{
    ui->setupUi(this);
}

SUTestsList::~SUTestsList()
{
    delete ui;
}

void SUTestsList::updateUI()
{
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

    ui->listWidget->clear();

    std::vector <TestSuite::Test>::iterator it = tests.begin();
    for( ; it != tests.end(); ++it )
    {
        new QListWidgetItem( stdstr_to_qstr( (*it).testName.value() ), ui->listWidget );
    }
}

void SUTestsList::on_pushButton_clicked() // view results
{
   //???????? ???????????
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
        emit GoToSUTestResults();
    }
    catch( Except e )
    {
    }
}

void SUTestsList::on_pushButton_2_clicked() // edit test
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
        emit GoToSUTestEdit();//<--------------------
    }
    catch( Except e )
    {
    }
}

void SUTestsList::on_pushButton_3_clicked() // add test
{
    bool ok;
    std::string testName = qstr_to_stdstr( QInputDialog::getText( this,
                                                                  QString::fromLocal8Bit("Введите название теста"),
                                                                  QString::fromLocal8Bit("Название теста:"),
                                                                  QLineEdit::Normal, "", &ok ) );
    if( !ok || testName.empty() )
    {
        return;
    }

    try
    {
        TestSuite::Test test = select <Test>( *pDB, Test::TestName == testName ).one();
        QMessageBox::warning( NULL, "QTestSuite",
                              QString::fromLocal8Bit("???? ? ????? ????????? ??? ??????????."),
                              QMessageBox::Ok, QMessageBox::Ok );
    }
    catch( Except e )
    {
        try
        {
            TestSuite::Test test( *pDB );
            test.testName = testName;
            test.update();
        }
        catch( Except e )
        {
            QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
            return;
        }
    }

    updateUI();
}

void SUTestsList::on_pushButton_4_clicked() // remove test
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if( !item )
    {
        return;
    }

    if( QMessageBox( QString::fromLocal8Bit("QTestSuite"),
                     QString::fromLocal8Bit("?? ???????, ??? ?????? ??????? ?????\n\n??? ?????? ??? ?????????? ?????????."),
                     QMessageBox::Question, QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel ).exec()
            != QMessageBox::Yes )
    {
        return;
    }

    if( QMessageBox( QString::fromLocal8Bit("QTestSuite"),
                     QString::fromLocal8Bit("?? ????? ??????? ? ?????\n\n???????? ???????? ??????????."),
                     QMessageBox::Question, QMessageBox::Yes, QMessageBox::No, 0 ).exec()
            != QMessageBox::Yes )
    {
        return;
    }

    try
    {
        TestSuite::Test test = select <Test>( *pDB, Test::TestName == qstr_to_stdstr( item->text() ) ).one();
        test.questions().del();
        test.students().del();
        test.del();
        /// TODO: delete properly
        updateUI();
    }
    catch( Except e )
    {
    }
}

void SUTestsList::on_pushButton_5_clicked() // rename test
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if( !item )
    {
        return;
    }

    bool ok;
    std::string newName = qstr_to_stdstr( QInputDialog::getText( this,
                                                                 QString::fromLocal8Bit("??????? ????? ????????"),
                                                                 QString::fromLocal8Bit("????? ????????:"),
                                                                 QLineEdit::Normal, item->text(), &ok ) );
    if( !ok || newName.empty() )
    {
        return;
    }

    try
    {
        TestSuite::Test test = select <Test>( *pDB, Test::TestName == qstr_to_stdstr( item->text() ) ).one();
        test.testName = newName;
        test.update();
    }
    catch( Except e )
    {
    }

    updateUI();
}
