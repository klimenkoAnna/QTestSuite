#include "SUTestResults.h"
#include "ui_SUTestResults.h"
#include <QtWidgets/QMessageBox>
#include "qtestsuite_shareddefs.h"

//-----------------------------------------------------------

#include "clipscpp.h"

char* sClipsRulesFile = "/clips_test_results_rules.clp";

    void AddScoresData(int minScore, int maxScore, int maxPossibleScore, int groupNum, std::string surname,
                       int numClasses, int visitedClasses, int bonuses, int presentation)
    {
        void *templatePtr = FindDeftemplate("scoresData");
        if (templatePtr == NULL) return;

        void *newFact = CreateFact(templatePtr);
        if (newFact == NULL) return;

        DATA_OBJECT value;

        value.type = FLOAT;
        value.value = AddDouble((double)minScore);
        PutFactSlot(newFact,"minScore",&value);

        value.type = FLOAT;
        value.value = AddDouble((double)maxScore);
        PutFactSlot(newFact,"maxScore",&value);

        value.type = FLOAT;
        value.value = AddDouble((double)maxPossibleScore);
        PutFactSlot(newFact,"maxPossibleScore",&value);

        value.type = INTEGER;
        value.value = AddLong(groupNum);
        PutFactSlot(newFact,"groupNum",&value);

        value.type = SYMBOL;
        value.value = AddSymbol((char*)surname.c_str());
        PutFactSlot(newFact,"surname",&value);

        value.type = INTEGER;
        value.value = AddLong(numClasses);
        PutFactSlot(newFact,"numClasses",&value);

        value.type = INTEGER;
        value.value = AddLong(visitedClasses);
        PutFactSlot(newFact,"visitedClasses",&value);

        value.type = INTEGER;
        value.value = AddLong(bonuses);
        PutFactSlot(newFact,"bonuses",&value);

        value.type = INTEGER;
        value.value = AddLong(presentation);
        PutFactSlot(newFact,"presentation",&value);

        //AssignFactSlotDefaults(newFact);

        //EnvAssert(GetCurrentEnvironment(),newFact);
        Assert(newFact);
    }

//-----------------------------------------------------------

SUTestResults::SUTestResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUTestResults)
{
    ui->setupUi(this);
}

SUTestResults::~SUTestResults()
{
    delete ui;
}


void SUTestResults::updateUI()
{
    if( !curTest )
    {
        throw Except( "?????? ?????????." );
    }

    std::vector <TestSuite::Student> students;

    try
    {
        students = curTest->students().get().all();
        testQuestions = curTest->questions().get().orderBy( TestSuite::TestQuestion::QuestionNum ).all();
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        return;
    }

    ui->label->setText( QString( "%1" ).arg( stdstr_to_qstr( curTest->testName.value() ) ) );

    ui->tableWidget->clear();

    if( !students.size() )
    {
        QMessageBox::warning( NULL, "QTestSuite",
                              QString::fromLocal8Bit( "У теста нет результатов." ),
                              QMessageBox::Ok, QMessageBox::Ok );
        emit GoToSUTestsLits();
        return;
    }

    if( curStud )
    {
        delete curStud;
        curStud = NULL;
    }

    int studCount = students.size();
    ui->tableWidget->setRowCount( studCount );

    ClipsStdoutRouter router;
    Clips::ClipsCPPEnv env;
    env.Load(sClipsRulesFile);
    env.AddRouter("ClipsStdoutRouter", 10, &router);

    for( int i = 0; i < studCount; ++i )
    {
        TestSuite::Student stud = students[i];

        curStud = &stud;
        int minScore = 0;
        int maxScore = 0;
        int maxPossibleScore = 0;
        getScores( minScore, maxScore, maxPossibleScore ); // uses testQuestions[], curStud

        router.emptyBuffer();
        env.Reset();
        AddScoresData(minScore, maxScore, maxPossibleScore,
                      stud.groupNum.value(), stud.surname.value(), stud.numClasses.value(),stud.visitedClasses.value(),
                      stud.bonuses.value(),
                      stud.presentation.value());
        env.Run(-1);

        QTableWidgetItem *itemGroup  = new QTableWidgetItem( QString("%1").arg( stud.groupNum.value() ) );
        QTableWidgetItem *itemName   = new QTableWidgetItem( QString("%1").arg( stdstr_to_qstr( curStud->surname.value() ) ) );
        QTableWidgetItem *itemResult = new QTableWidgetItem( QString::fromLocal8Bit("от %1 до %2").arg(minScore).arg(maxScore) );
        QTableWidgetItem *itemClipsResult = new QTableWidgetItem( router.getBuffer() );
        ui->tableWidget->setItem( i, 0, itemGroup  );
        ui->tableWidget->setItem( i, 1, itemName   );
        ui->tableWidget->setItem( i, 2, itemResult );
        ui->tableWidget->setItem( i, 3, itemClipsResult );

        curStud = NULL;
    }


    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setColumnWidth( 0, ui->tableWidget->columnWidth(0) + 15 );
    ui->tableWidget->setColumnWidth( 1, ui->tableWidget->columnWidth(1) + 15 );
    ui->tableWidget->setColumnWidth( 2, ui->tableWidget->columnWidth(2) + 15 );
    ui->tableWidget->setColumnWidth( 3, ui->tableWidget->columnWidth(3) + 15 );
}

void SUTestResults::on_pushButton_clicked() // back
{
    emit GoToSUTestsLits();
}

void SUTestResults::on_pushButton_2_clicked()
{
    QList<QTableWidgetItem *> list = ui->tableWidget->selectedItems();
    if( !list.size() )
    {
        return;
    }

    if( curStud )
    {
        delete curStud;
        curStud = NULL;
    }

    try
    {
        TestSuite::Student stud =  intersect<Student>( select <Student>( *pDB,
                                                                         Student::GroupNum == qstr_to_stdstr( list[0]->text() ) &&
                                                                         Student::Surname == qstr_to_stdstr( list[1]->text() ) ),
                                                       curTest->students().get() ).one();
        curStud = new TestSuite::Student( stud );

        emit GoToSUStudResults();
    }
    catch( Except e )
    {
    }
}

void SUTestResults::on_pushButton_3_clicked() // back
{
    QList<QTableWidgetItem *> list = ui->tableWidget->selectedItems();
    if( !list.size() )
    {
        return;
    }

    if( curStud )
    {
        delete curStud;
        curStud = NULL;
    }

    try
    {
        TestSuite::Student stud =  intersect<Student>( select <Student>( *pDB,
                                                                         Student::GroupNum == qstr_to_stdstr( list[0]->text() ) &&
                                                                         Student::Surname == qstr_to_stdstr( list[1]->text() ) ),
                                                       curTest->students().get() ).one();
        curStud = new TestSuite::Student( stud );
        std::cout << "Before sustudent";
        emit GoToSUStudentInfo();
    }
    catch( Except e )
    {
    }
}
