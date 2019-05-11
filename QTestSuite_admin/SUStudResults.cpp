#include "SUStudResults.h"
#include "ui_SUStudResults.h"
#include <QtWidgets/QMessageBox>
#include "db_code/QDBCheckBox.h"
#include "qtestsuite_shareddefs.h"

QDBCheckBox* SUstudAnswersControls[ QTESTSUITE_MAX_ANS ];
QDBCheckBox* SUrightAnswersControls[ QTESTSUITE_MAX_ANS ];



SUStudResults::SUStudResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUStudResults)
{
    ui->setupUi(this);
}

SUStudResults::~SUStudResults()
{
    delete ui;
}

void SUStudResults::updateUI()
{
    curQuestionNum = 0;
    if( !curStud || !curTest )
    {
        throw Except( "Ошибка программы." );
    }

    try
    {
        curTest->students().link( *curStud );
        testQuestions = curTest->questions().get().orderBy( TestSuite::TestQuestion::QuestionNum ).all();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        return;
    }

    ui->label_1->setText( QString( "%1 - %2\n%3" )
                        .arg( curStud->groupNum.value() )
                        .arg( stdstr_to_qstr( curStud->surname.value() ) )
                        .arg( stdstr_to_qstr( curTest->testName.value() ) ) );

    int totalQ = testQuestions.size();
    if( totalQ < 2 ) // no questions - create first
    {
        QMessageBox::warning( NULL, "QTestSuite",
                              QString::fromLocal8Bit("Недостаточно вопросов."),
                              QMessageBox::Ok, QMessageBox::Ok );
        emit GoToSUTestResults();
        return;
    }

    selfUpdateUI();
}

void SUStudResults::selfUpdateUI()
{
    int totalQ = testQuestions.size();

    ui->pushButton_2->setEnabled( true );  // prev
    ui->pushButton_3->setEnabled( true );  // next

    if( curQuestionNum <= 0 ) // first
    {
        curQuestionNum = 0;
        ui->pushButton_2->setEnabled( false ); // prev
    }
    if( curQuestionNum >= totalQ-1 ) // last
    {
        curQuestionNum = totalQ-1;
        ui->pushButton_3->setEnabled( false ); // next
    }

    ui->label_2->setText( QString::fromLocal8Bit( "Вопрос %1 (из %2)" )
                          .arg( curQuestionNum + 1 )
                          .arg( totalQ ) );
    ui->label_3->setText( decipher( testQuestions[ curQuestionNum ].questionText.value() ) );

    ui->label_4->clear();

    // answers

    try
    {
        testAnswers = testQuestions[ curQuestionNum ].answers().get().orderBy( TestSuite::TestAnswer::AnswerNum ).all();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        return;
    }

    int totalAns = testAnswers.size();
    totalAns = totalAns > QTESTSUITE_MAX_ANS ? QTESTSUITE_MAX_ANS : totalAns;

    if( totalAns )
    {

        ui->label_4->setVisible( false );

        for( int i = totalAns; i < QTESTSUITE_MAX_ANS; ++i )
        {
            if( SUstudAnswersControls[i]  )
            {
                ui->verticalLayout_2->removeWidget( SUstudAnswersControls[i] );
                delete SUstudAnswersControls[i];
                SUstudAnswersControls[i] = NULL;
            }
            if( SUrightAnswersControls[i]  )
            {
                ui->verticalLayout_2a->removeWidget( SUrightAnswersControls[i] );
                delete SUrightAnswersControls[i];
                SUrightAnswersControls[i] = NULL;
            }
        }

        for( int i = 0; i < totalAns; ++i )
        {
            if( !SUstudAnswersControls[i] )
            {
                SUstudAnswersControls[i] = new QDBCheckBox( NULL, i, QString(), QRect( 0, 0, 0, 0 ) );
                ui->verticalLayout_2->addWidget( SUstudAnswersControls[i] );
            }

            if( !SUrightAnswersControls[i] )
            {
                SUrightAnswersControls[i] = new QDBCheckBox( NULL, i, QString(), QRect( 0, 0, 0, 0 ) );
                ui->verticalLayout_2a->addWidget( SUrightAnswersControls[i] );
            }

            SUstudAnswersControls[i]->setText( decipher( testAnswers[i].answerText.value() ) );
            SUstudAnswersControls[i]->setChecked( false );
            SUrightAnswersControls[i]->setText( QString::fromLocal8Bit( "ответ" ) );
            SUrightAnswersControls[i]->setChecked( false );
        }

        try
        {
            //std::vector <TestSuite::StudentAnswer> studAns =
            //        curStud->answers().get( TestSuite::StudentAnswer::QuestionNum == curQuestionNum )
            //        .orderBy( TestSuite::StudentAnswer::AnswerNum ).all();

            std::vector <TestSuite::StudentAnswer> studAns =
                    intersect( curStud->answers().get( TestSuite::StudentAnswer::QuestionNum == curQuestionNum ),
                               curTest->studentAnswers().get( TestSuite::StudentAnswer::QuestionNum == curQuestionNum ) )
                    .orderBy( TestSuite::StudentAnswer::AnswerNum ).all();

            std::vector <TestSuite::StudentAnswer>::iterator it = studAns.begin();
            for( int i = 0; it < studAns.end() && i < totalAns; ++it, ++i )
            {
                SUstudAnswersControls[i]->setChecked( (*it).selected.value() );
            }

            testAnswers = testQuestions[curQuestionNum].answers().get().orderBy( TestSuite::TestAnswer::AnswerNum ).all();

            std::vector <TestSuite::TestAnswer>::iterator it2 = testAnswers.begin();
            for( int i = 0; it2 < testAnswers.end() && i < totalAns; ++it2, ++i )
            {
                SUrightAnswersControls[i]->setChecked( (*it2).isRight.value() );
            }
        }
        catch( Except e )
        {
        }
    }
    else
    {
        ui->label_4->setVisible( true );

        for( int i = 0; i < QTESTSUITE_MAX_ANS; ++i )
        {
            if( SUstudAnswersControls[i]  )
            {
                ui->verticalLayout_2->removeWidget( SUstudAnswersControls[i] );
                delete SUstudAnswersControls[i];
                SUstudAnswersControls[i] = NULL;
            }
            if( SUrightAnswersControls[i]  )
            {
                ui->verticalLayout_2a->removeWidget( SUrightAnswersControls[i] );
                delete SUrightAnswersControls[i];
                SUrightAnswersControls[i] = NULL;
            }
        }

        try
        {
            TestSuite::StudentCustomAnswer customAns =
                    curStud->customAnswer().get( TestSuite::StudentCustomAnswer::QuestionNum == curQuestionNum ).one();
            ui->label_4->setText( stdstr_to_qstr( customAns.customAnswer.value() ) );
        }
        catch( Except e )
        {
            ui->label_4->clear();
        }
    }

}

void SUStudResults::on_pushButton_clicked() // finish
{
    emit GoToSUTestResults();
}


void SUStudResults::on_pushButton_2_clicked() // prev
{
    --curQuestionNum;
    selfUpdateUI();
}

void SUStudResults::on_pushButton_3_clicked() // next
{
    ++curQuestionNum;
    selfUpdateUI();
}
