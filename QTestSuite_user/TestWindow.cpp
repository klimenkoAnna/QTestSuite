#include "TestWindow.h"
#include "ui_TestWindow.h"
#include <QtWidgets/QMessageBox>
#include "db_code/QDBCheckBox.h"
#include "qtestsuite_shareddefs.h"

struct TestAnswersUI
{
    QDBCheckBox *pAnswerCheck;
    QLabel      *pAnswerText;
    int          answerNumber;

    TestAnswersUI() :
        pAnswerCheck(NULL),
        pAnswerText(NULL),
        answerNumber(0)
    {}
};

TestAnswersUI studAnswersControls[ QTESTSUITE_MAX_ANS ];



TestWindow::TestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::updateUI()
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

    ui->pushButton->setEnabled( false ); // finish

    ui->label->setText( QString( "%1 - %2\n%3" )
                        .arg( curStud->groupNum.value() )
                        .arg( stdstr_to_qstr( curStud->surname.value() ) )
                        .arg( stdstr_to_qstr( curTest->testName.value() ) ) );


    int totalQ = testQuestions.size();
    if( totalQ < 2 ) // no questions - create first
    {
        QMessageBox::warning( NULL, "QTestSuite",
                              QString::fromLocal8Bit("Недостаточно вопросов."),
                              QMessageBox::Ok, QMessageBox::Ok );
        emit GoToTestSelectWnd();
        return;
    }

    selfUpdateUI();
}

void TestWindow::selfUpdateUI()
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
        ui->pushButton  ->setEnabled( true ); // finish
    }

    ui->label_3->setText( QString::fromLocal8Bit( "Вопрос %1 (из %2)" )
                          .arg( curQuestionNum + 1 )
                          .arg( totalQ ) );
    ui->label_4->setText( decipher( testQuestions[ curQuestionNum ].questionText.value() ) );

    QString questionPicturePath = decipher( testQuestions[ curQuestionNum ].questionPicture.value() );
    if( questionPicturePath.length() )
    {
        ui->questionPicture->setVisible( true );
        QPixmap pixmap( questionPicturePath );
        if( pixmap.isNull() )
        {
            ui->questionPicture->setText( QString::fromLocal8Bit("< Не удалось загрузить изображение >") );
        }
        else
        {
            ui->questionPicture->setPixmap( pixmap );
        }
    }
    else
    {
        ui->questionPicture->setVisible( false );
    }

    ui->plainTextEdit->clear();

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



    for( int i = 0; i < QTESTSUITE_MAX_ANS; ++i )
    {
        ui->verticalLayout_5->removeWidget( studAnswersControls[i].pAnswerCheck );
        ui->verticalLayout_2->removeWidget( studAnswersControls[i].pAnswerText );

        if( studAnswersControls[i].pAnswerCheck )
        {
            delete studAnswersControls[i].pAnswerCheck;
            studAnswersControls[i].pAnswerCheck = NULL;
        }
        if( studAnswersControls[i].pAnswerText )
        {
            delete studAnswersControls[i].pAnswerText;
            studAnswersControls[i].pAnswerText = NULL;
        }
    }



    if( totalAns )
    {
        ui->plainTextEdit->setVisible( false );
        ui->verticalSpacer->changeSize( 5, 5, QSizePolicy::Expanding, QSizePolicy::Expanding );

        for( int i = 0; i < totalAns; ++i )
        {                       
            if( !studAnswersControls[i].pAnswerCheck )
            {
                studAnswersControls[i].pAnswerCheck = new QDBCheckBox( NULL, i, QString(), QRect( 0, 0, 0, 0 ) );
            }
            if( !studAnswersControls[i].pAnswerText )
            {
                studAnswersControls[i].pAnswerText = new QLabel( QString(), NULL );                
            }

            studAnswersControls[i].pAnswerCheck->setChecked( false );
            studAnswersControls[i].answerNumber = i;

            QString picturePath = decipher( testAnswers[i].answerPicture.value() );
            if( picturePath.length() )
            {
                QPixmap pixmap( picturePath );
                if( pixmap.isNull() )
                {
                    studAnswersControls[i].pAnswerText->setText( QString::fromLocal8Bit("< Не удалось загрузить изображение >") );
                }
                else
                {
                    studAnswersControls[i].pAnswerText->setPixmap( pixmap );
                }
            }
            else
            {
                studAnswersControls[i].pAnswerText->setWordWrap(true);
                studAnswersControls[i].pAnswerText->setText( decipher( testAnswers[i].answerText.value() ) );
            }
        }

        try
        {
            std::vector <TestSuite::StudentAnswer> studAns =
                    intersect( curStud->answers().get( TestSuite::StudentAnswer::QuestionNum == curQuestionNum ),
                               curTest->studentAnswers().get( TestSuite::StudentAnswer::QuestionNum == curQuestionNum ) )
                    .orderBy( TestSuite::StudentAnswer::AnswerNum )
                    .all();

            std::vector <TestSuite::StudentAnswer>::iterator it = studAns.begin();

            for( int i = 0; it < studAns.end() && i < totalAns; ++it, ++i )
            {
                studAnswersControls[ i ].pAnswerCheck->setChecked( (*it).selected.value() );
                //studAnswersControls[ (*it).answerNum ].pAnswerCheck->setChecked( (*it).selected.value() );
            }
        }
        catch( Except e )
        {
        }

        std::random_shuffle(studAnswersControls, studAnswersControls + totalAns);

        for( int i = 0; i < totalAns; ++i )
        {
            ui->verticalLayout_5->addWidget( studAnswersControls[i].pAnswerCheck );
            ui->verticalLayout_2->addWidget( studAnswersControls[i].pAnswerText );
        }
    }
    else
    {
        ui->plainTextEdit->setVisible( true );
        ui->verticalSpacer->changeSize( 5, 5, QSizePolicy::Expanding, QSizePolicy::Fixed );

        try
        {
            TestSuite::StudentCustomAnswer customAns =
                    curStud->customAnswer().get( TestSuite::StudentCustomAnswer::QuestionNum == curQuestionNum ).one();
            ui->plainTextEdit->setPlainText( stdstr_to_qstr( customAns.customAnswer.value() ) );
        }
        catch( Except e )
        {
            ui->plainTextEdit->clear();
        }
    }

}

void TestWindow::saveChanges()
{
    int totalAns = testAnswers.size();
    totalAns = totalAns > QTESTSUITE_MAX_ANS ? QTESTSUITE_MAX_ANS : totalAns;

    if( totalAns )
    {
        try
        {
            std::vector <TestSuite::StudentAnswer> studAns =
                    intersect( curStud->answers().get( TestSuite::StudentAnswer::QuestionNum == curQuestionNum ),
                               curTest->studentAnswers().get( TestSuite::StudentAnswer::QuestionNum == curQuestionNum ) )
                    .orderBy( TestSuite::StudentAnswer::AnswerNum ).all();

            int i = 0;
            if( studAns.size() )
            {
                std::vector <TestSuite::StudentAnswer>::iterator it = studAns.begin();
                for( ; it < studAns.end() && i < totalAns; ++it, ++i )
                {
                    (*it).questionNum = curQuestionNum;
                    (*it).answerNum = studAnswersControls[i].answerNumber;
                    (*it).selected = studAnswersControls[i].pAnswerCheck->isChecked();

                    (*it).update();                    
                }
            }

            for( ; i < totalAns; ++i )
            {
                TestSuite::StudentAnswer ans( *pDB );

                ans.questionNum = curQuestionNum;
                ans.answerNum = studAnswersControls[i].answerNumber;
                ans.selected = studAnswersControls[i].pAnswerCheck->isChecked();

                ans.update();                
                curStud->answers().link( ans );
                curTest->studentAnswers().link( ans );
            }
        }
        catch( Except e )
        {
            QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        }
    }
    else
    {
        try
        {
            TestSuite::StudentCustomAnswer customAns =
                    curStud->customAnswer().get( TestSuite::StudentCustomAnswer::QuestionNum == curQuestionNum ).one();
            customAns.customAnswer = qstr_to_stdstr( ui->plainTextEdit->toPlainText() );
            customAns.questionNum = curQuestionNum;
            customAns.update();
        }
        catch( Except e )
        {
            TestSuite::StudentCustomAnswer customAns( *pDB );
            customAns.customAnswer = qstr_to_stdstr( ui->plainTextEdit->toPlainText() );
            customAns.questionNum = curQuestionNum;
            customAns.update();

            curStud->customAnswer().link( customAns );
        }
    }
}

void TestWindow::on_pushButton_clicked() // finish
{
    if( QMessageBox( QString::fromLocal8Bit("QTestSuite"),
                     QString::fromLocal8Bit("Вы уверены, что хотите закончить тест?"),
                     QMessageBox::Question, QMessageBox::Yes, QMessageBox::No, 0 ).exec()
            != QMessageBox::Yes )
    {
        return;
    }

    saveChanges();
    emit GoToTestResultsWnd();
}

void TestWindow::on_pushButton_2_clicked() // prev
{
    saveChanges();
    --curQuestionNum;
    selfUpdateUI();
}

void TestWindow::on_pushButton_3_clicked() // next
{
    saveChanges();
    ++curQuestionNum;
    selfUpdateUI();
}
