#include "SUTestEdit.h"
#include "ui_SUTestEdit.h"
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include "db_code/QDBCheckBox.h"
#include "qtestsuite_shareddefs.h"

struct SUTestAnswersUI
{
    QHBoxLayout    *pHLayout;
    QVBoxLayout    *pVLayout;
    QDBCheckBox    *pIsRightCheck;
    QDBCheckBox    *pDeleteButton;
    QDBCheckBox    *pSetAnswerPictureButton;
    QSpacerItem    *pSpacer;
    QPlainTextEdit *pAnswerEdit;
    QScrollArea    *pScrollArea;
    QLabel         *pPicture;

    SUTestAnswersUI() :
        pHLayout(NULL),
        pVLayout(NULL),
        pIsRightCheck(NULL),
        pDeleteButton(NULL),
        pSetAnswerPictureButton(NULL),
        pSpacer(NULL),
        pAnswerEdit(NULL),
        pScrollArea(NULL),
        pPicture(NULL)
    {}
};

SUTestAnswersUI SUanswersControls[ QTESTSUITE_MAX_ANS ];

QString questionPicturePath;



SUTestEdit::SUTestEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUTestEdit)
{
    ui->setupUi(this);
}

SUTestEdit::~SUTestEdit()
{
    delete ui;
}

void SUTestEdit::updateUI()
{
    curQuestionNum = 0;
    selfUpdateUI();
    if( curTest )
    {
        ui->label->setText( stdstr_to_qstr( curTest->testName.value() ) );
    }
}

void SUTestEdit::selfUpdateUI()
{
    if( !curTest )
    {
        QMessageBox::warning( NULL, "QTestSuite",
                              QString::fromLocal8Bit("Ошибка программы."),
                              QMessageBox::Ok, QMessageBox::Ok );
        emit GoToSUTestsList();
        return;
    }

    try
    {
        testQuestions = curTest->questions().get().orderBy( TestSuite::TestQuestion::QuestionNum ).all();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        return;
    }

    int totalQ = testQuestions.size();
    if( !totalQ ) // no questions - create first
    {
        try
        {
            TestSuite::TestQuestion newQuestion( *pDB );
            newQuestion.questionNum = 1;
            newQuestion.questionText = "";
            newQuestion.update();

            curTest->questions().link( newQuestion );
            testQuestions.push_back( newQuestion );

            curQuestionNum = 0;
            totalQ = 1;

            //QMessageBox::information( NULL, "QTestSuite", "Created first question.", QMessageBox::Ok, QMessageBox::Ok );
        }
        catch( Except e )
        {
            QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
            return;
        }

        ui->pushButton_2->setEnabled( false ); // prev
        ui->pushButton_3->setEnabled( false ); // next
    }
    else // 1 or more questions
    {
        ui->pushButton_2->setEnabled( true ); // prev
        ui->pushButton_3->setEnabled( true ); // next

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
    }

    ui->label_2->setText( QString::fromLocal8Bit( "Вопрос %1 / %2" ).arg( curQuestionNum + 1 ).arg( totalQ ) );
    ui->plainTextEdit->setPlainText( decipher( testQuestions[ curQuestionNum ].questionText.value() ) );

    questionPicturePath = decipher( testQuestions[ curQuestionNum ].questionPicture.value() );
    if( questionPicturePath.length() )
    {
        ui->checkBoxQuestionPicture->setChecked( true );
        ui->questionPicture->setVisible( true );
        ui->scrollArea->setVisible( true );
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
        ui->checkBoxQuestionPicture->setChecked( false );
        ui->questionPicture->setVisible( false );
        ui->scrollArea->setVisible( false );
    }

    selfUpdateAnswers();
}

void SUTestEdit::selfUpdateAnswers()
{
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

    for( int i = 0; i < QTESTSUITE_MAX_ANS; ++i ) // remove all
    {        
        if( SUanswersControls[i].pHLayout )
        {
            SUanswersControls[i].pHLayout->removeItem( SUanswersControls[i].pVLayout );
            SUanswersControls[i].pHLayout->removeWidget( SUanswersControls[i].pAnswerEdit );
            SUanswersControls[i].pHLayout->removeWidget( SUanswersControls[i].pScrollArea );
            ui->verticalLayout_10->removeItem( SUanswersControls[i].pHLayout );
            delete SUanswersControls[i].pHLayout;
            SUanswersControls[i].pHLayout = NULL;
        }
        if( SUanswersControls[i].pVLayout )
        {
            SUanswersControls[i].pVLayout->removeWidget( SUanswersControls[i].pIsRightCheck );
            SUanswersControls[i].pVLayout->removeWidget( SUanswersControls[i].pDeleteButton );
            SUanswersControls[i].pVLayout->removeWidget( SUanswersControls[i].pSetAnswerPictureButton );
            SUanswersControls[i].pVLayout->removeItem( SUanswersControls[i].pSpacer );
            delete SUanswersControls[i].pVLayout;
            SUanswersControls[i].pVLayout = NULL;
        }
        if( SUanswersControls[i].pIsRightCheck )
        {
            delete SUanswersControls[i].pIsRightCheck;
            SUanswersControls[i].pIsRightCheck = NULL;
        }        
        if( SUanswersControls[i].pDeleteButton )
        {
            QObject::disconnect( SUanswersControls[i].pDeleteButton, SIGNAL(clickedNum(int)), this, SLOT(deleteAnswer(int)) );
            delete SUanswersControls[i].pDeleteButton;
            SUanswersControls[i].pDeleteButton = NULL;
        }
        if( SUanswersControls[i].pSetAnswerPictureButton )
        {
            QObject::disconnect( SUanswersControls[i].pSetAnswerPictureButton, SIGNAL(clickedNum(int)), this, SLOT(setAnswerPicture(int)) );
            delete SUanswersControls[i].pSetAnswerPictureButton;
            SUanswersControls[i].pSetAnswerPictureButton = NULL;
        }
        if( SUanswersControls[i].pSpacer )
        {
            delete SUanswersControls[i].pSpacer;
            SUanswersControls[i].pSpacer = NULL;
        }
        if( SUanswersControls[i].pAnswerEdit )
        {
            delete SUanswersControls[i].pAnswerEdit;
            SUanswersControls[i].pAnswerEdit = NULL;
        }
        if( SUanswersControls[i].pPicture )
        {
            delete SUanswersControls[i].pPicture;
            SUanswersControls[i].pPicture = NULL;
        }
        if( SUanswersControls[i].pScrollArea )
        {
            SUanswersControls[i].pScrollArea->takeWidget();
            delete SUanswersControls[i].pScrollArea;
            SUanswersControls[i].pScrollArea = NULL;
        }
    }

    for( int i = 0; i < totalAns; ++i )
    {
        SUanswersControls[i].pIsRightCheck = new QDBCheckBox( NULL, i, QString::fromLocal8Bit("Правильный"), QRect( 0,0,0,0 ) );
        SUanswersControls[i].pIsRightCheck->setChecked( testAnswers[i].isRight.value() );

        SUanswersControls[i].pDeleteButton = new QDBCheckBox( NULL, i, QString::fromLocal8Bit("Удалить"), QRect( 0,0,0,0 ) );
        SUanswersControls[i].pDeleteButton->setTristate( true );
        SUanswersControls[i].pDeleteButton->setCheckState( Qt::PartiallyChecked );
        QObject::connect( SUanswersControls[i].pDeleteButton, SIGNAL(clickedNum(int)), this, SLOT(deleteAnswer(int)) );

        SUanswersControls[i].pSetAnswerPictureButton = new QDBCheckBox( NULL, i, QString::fromLocal8Bit("Изображение"), QRect( 0,0,0,0 ) );
        SUanswersControls[i].pSetAnswerPictureButton->setTristate( true );
        SUanswersControls[i].pSetAnswerPictureButton->setCheckState( Qt::PartiallyChecked );
        QObject::connect( SUanswersControls[i].pSetAnswerPictureButton, SIGNAL(clickedNum(int)), this, SLOT(setAnswerPicture(int)) );

        SUanswersControls[i].pSpacer = new QSpacerItem(10,10,QSizePolicy::Minimum, QSizePolicy::Minimum);
        SUanswersControls[i].pSpacer->changeSize( 5, 5, QSizePolicy::Ignored, QSizePolicy::Expanding );

        SUanswersControls[i].pAnswerEdit = new QPlainTextEdit( decipher( testAnswers[i].answerText.value() ), NULL );
        SUanswersControls[i].pAnswerEdit->setGeometry( QRect( 0,0,0,0 ) );

        SUanswersControls[i].pPicture = new QLabel( NULL );
        SUanswersControls[i].pPicture->setVisible( false );

        SUanswersControls[i].pScrollArea = new QScrollArea( NULL );
        SUanswersControls[i].pScrollArea->setVisible( false );
        SUanswersControls[i].pScrollArea->setWidgetResizable( true );
        SUanswersControls[i].pScrollArea->setWidget( SUanswersControls[i].pPicture );

        QString picturePath = decipher( testAnswers[i].answerPicture.value() );
        if( picturePath.length() )
        {
            SUanswersControls[i].pAnswerEdit->setPlainText(picturePath);
            SUanswersControls[i].pAnswerEdit->setVisible( false );
            SUanswersControls[i].pScrollArea->setVisible( true );
            SUanswersControls[i].pPicture->setVisible( true );
            QPixmap pixmap( picturePath );
            if( pixmap.isNull() )
            {
                SUanswersControls[i].pPicture->setText( QString::fromLocal8Bit("< Не удалось загрузить изображение >") );
            }
            else
            {
                SUanswersControls[i].pPicture->setPixmap( pixmap );
            }
        }

        SUanswersControls[i].pVLayout = new QVBoxLayout();
        SUanswersControls[i].pVLayout->addWidget( SUanswersControls[i].pIsRightCheck );
        SUanswersControls[i].pVLayout->addWidget( SUanswersControls[i].pDeleteButton );
        SUanswersControls[i].pVLayout->addWidget( SUanswersControls[i].pSetAnswerPictureButton );
        SUanswersControls[i].pVLayout->addItem( SUanswersControls[i].pSpacer );

        SUanswersControls[i].pHLayout = new QHBoxLayout();
        SUanswersControls[i].pHLayout->addItem( SUanswersControls[i].pVLayout );
        SUanswersControls[i].pHLayout->addWidget( SUanswersControls[i].pAnswerEdit );
        SUanswersControls[i].pHLayout->addWidget( SUanswersControls[i].pScrollArea );

        ui->verticalLayout_10->addLayout( SUanswersControls[i].pHLayout );
    }
}

void SUTestEdit::saveChanges()
{
    testQuestions[ curQuestionNum ].questionText = cipher( ui->plainTextEdit->toPlainText() );
    testQuestions[ curQuestionNum ].questionPicture = "";
    if( questionPicturePath.length() && ui->checkBoxQuestionPicture->isChecked() )
    {
        testQuestions[ curQuestionNum ].questionPicture = cipher( questionPicturePath );
    }

    testQuestions[ curQuestionNum ].update();

    int totalAns = testAnswers.size();
    totalAns = totalAns > QTESTSUITE_MAX_ANS ? QTESTSUITE_MAX_ANS : totalAns;

    try
    {
        for( int i = 0; i < totalAns; ++i )
        {
            testAnswers[i].answerNum = i;            
            testAnswers[i].isRight = SUanswersControls[i].pIsRightCheck->isChecked();

            if( SUanswersControls[i].pAnswerEdit->isVisible() )
            {
                testAnswers[i].answerText = cipher( SUanswersControls[i].pAnswerEdit->toPlainText() );
                testAnswers[i].answerPicture = cipher( QString("\0") );
            }
            else // picture path
            {
                testAnswers[i].answerText = cipher( QString("\0") );
                testAnswers[i].answerPicture = cipher( SUanswersControls[i].pAnswerEdit->toPlainText() );
            }

            testAnswers[i].update();
        }
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
    }
}

void SUTestEdit::on_pushButton_clicked() // back to tests
{
    saveChanges();
    emit GoToSUTestsList();
}

void SUTestEdit::on_pushButton_2_clicked() // prev
{
    saveChanges();
    --curQuestionNum;
    selfUpdateUI();
}

void SUTestEdit::on_pushButton_3_clicked() // next
{
    saveChanges();
    ++curQuestionNum;
    selfUpdateUI();
}

void SUTestEdit::on_pushButton_4_clicked() // add q
{
    saveChanges();

    try
    {
        int newNum = testQuestions.size();

        TestSuite::TestQuestion newQuestion( *pDB );
        newQuestion.questionNum = newNum; // to the end
        newQuestion.questionText = "";
        newQuestion.update();

        curTest->questions().link( newQuestion );
        //testQuestions.insert( testQuestions.end(), newQuestion );

        curQuestionNum = newNum;

        selfUpdateUI();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
    }
}

void SUTestEdit::on_pushButton_5_clicked() // delete q
{
    if( QMessageBox( QString::fromLocal8Bit("QTestSuite"),
                     QString::fromLocal8Bit("Вы уверены, что хотите удалить вопрос?"),
                     QMessageBox::Question, QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel ).exec()
            != QMessageBox::Yes )
    {
        return;
    }

    try
    {
        curTest->questions().unlink( testQuestions[ curQuestionNum ] );
        testQuestions[ curQuestionNum ].del();

        if( testQuestions.size() > 1 )
        {
            testQuestions.erase( testQuestions.begin() + curQuestionNum );

            int total = testQuestions.size();
            for( int i = 0; i < total; ++i )
            {
                testQuestions[ i ].questionNum = i;
                testQuestions[ i ].update();
            }
        }

        selfUpdateUI();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
    }
}

void SUTestEdit::on_pushButton_6_clicked() // add answer
{
    saveChanges();

    try
    {
        int totalAns = testAnswers.size();

        TestSuite::TestAnswer newAnswer( *pDB );
        newAnswer.answerNum = totalAns;
        newAnswer.answerText = "";
        newAnswer.update();

        testQuestions[ curQuestionNum ].answers().link( newAnswer );

        selfUpdateAnswers();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
    }
}

void SUTestEdit::deleteAnswer( int num ) // delete answer
{
    if( SUanswersControls[num].pDeleteButton )
    {
        SUanswersControls[num].pDeleteButton->setTristate( true );
        SUanswersControls[num].pDeleteButton->setCheckState( Qt::PartiallyChecked );
    }

    if( QMessageBox( QString::fromLocal8Bit("QTestSuite"),
                     QString::fromLocal8Bit("Вы уверены, что хотите удалить ответ?"),
                     QMessageBox::Question, QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel ).exec()
            != QMessageBox::Yes )
    {
        return;
    }

    saveChanges();

    try
    {
        testQuestions[ curQuestionNum ].answers().unlink( testAnswers[num] );
        testAnswers[num].del();

        if( testAnswers.size() > 1 )
        {
            testAnswers.erase( testAnswers.begin() + num );

            int total = testAnswers.size();
            for( int i = 0; i < total; ++i )
            {
                testAnswers[ i ].answerNum = i;
                testAnswers[ i ].update();
            }
        }

        selfUpdateAnswers();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
    }
}

void SUTestEdit::setAnswerPicture( int num ) // set picture
{
    if( !SUanswersControls[num].pAnswerEdit ||
            !SUanswersControls[num].pPicture ||
            !SUanswersControls[num].pSetAnswerPictureButton )
        return;

    QString picturePath = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit("Добавить изображение"), QDir::currentPath() );

    SUanswersControls[num].pSetAnswerPictureButton->setTristate( true );
    SUanswersControls[num].pSetAnswerPictureButton->setCheckState( Qt::PartiallyChecked );

    if( picturePath.isEmpty() )
        return;

    QPixmap pixmap(picturePath);
    if( pixmap.isNull() )
    {
        QMessageBox::information(this, "QTestSuite", QString::fromLocal8Bit("Не удалось открыть изображение:\n%1").arg(picturePath));
        return;
    }

    QDir dir( QDir::currentPath() );
    SUanswersControls[num].pAnswerEdit->setPlainText( dir.relativeFilePath(picturePath) );
    SUanswersControls[num].pAnswerEdit->setVisible( false );

    SUanswersControls[num].pScrollArea->setVisible( true );
    SUanswersControls[num].pPicture->setVisible( true );
    SUanswersControls[num].pPicture->setPixmap(pixmap);
}

void SUTestEdit::on_checkBoxQuestionPicture_clicked(bool checked)
{
    if( !checked )
    {
        ui->questionPicture->setVisible( false );
        ui->scrollArea->setVisible( false );
        questionPicturePath = "";
        return;
    }

    QString picturePath = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit("Добавить изображение"), QDir::currentPath() );

    if( picturePath.isEmpty() )
    {
        ui->checkBoxQuestionPicture->setChecked( false );
        return;
    }

    QPixmap pixmap(picturePath);
    if( pixmap.isNull() )
    {
        QMessageBox::information(this, "QTestSuite", QString::fromLocal8Bit("Не удалось открыть изображение:\n%1").arg(picturePath));
        ui->checkBoxQuestionPicture->setChecked( false );
        return;
    }

    QDir dir( QDir::currentPath() );
    questionPicturePath = dir.relativeFilePath(picturePath);

    ui->questionPicture->setVisible( true );
    ui->scrollArea->setVisible( true );
    ui->questionPicture->setPixmap(pixmap);
}
