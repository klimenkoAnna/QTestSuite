#include "SUStudentInfo.h"
#include "ui_SUStudentInfo.h"
#include <QtWidgets/QMessageBox>
#include "db_code/QDBCheckBox.h"
#include "qtestsuite_shareddefs.h"
#include "QDebug"

//-----------------------------------------------------------

#include "clipscpp.h"
char* sClipsRulesFile1 = "/clips_test_results_rules.clp";

SUStudentInfo::SUStudentInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUStudentInfo)
{
    ui->setupUi(this);
}

SUStudentInfo::~SUStudentInfo()
{
    delete ui;
}
void SUStudentInfo::updateUI()
{
    curQuestionNum = 0;
    if( !curStud || !curTest )
    {
        throw Except( "Ошибка программы." );
    }

    try
    {
        curTest->students().link( *curStud );
    }
    catch( Except e )
    {
        QMessageBox::warning( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        return;
    }
    ui->label_7->setText( QString( "%1" )
                          .arg( curStud->groupNum.value() ) );
    ui->label_8->setText( QString( "%1" )
                          .arg( stdstr_to_qstr( curStud->surname.value() ) ) );
    ui->label_9->setText( QString( "%1" )
                          .arg(curStud->numClasses.value() ) );
    ui->lineEdit->setText( QString( "%1" )
                           .arg( curStud->visitedClasses.value() ) );
    ui->lineEdit_2->setText( QString( "%1" )
                             .arg( curStud->bonuses.value() ) );
    ui->lineEdit_3->setText( QString( "%1" )
                             .arg( curStud->presentation.value() ) );
}
void AddScoresData1(int minScore, int maxScore, int maxPossibleScore, int groupNum, std::string surname,
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
void SUStudentInfo::on_pushButton_clicked() // finish
{
    emit GoToSUTestResults();
}

void SUStudentInfo::on_pushButton_2_clicked() // finish
{
    updateData(false,true,true);
}

void SUStudentInfo::on_label_9_textChanged(const QString &arg1)
{
    updateData(true,false,true);
}

void SUStudentInfo::on_lineEdit_textChanged(const QString &arg1)
{
   updateData(true,false,true);
}

void SUStudentInfo::on_lineEdit_2_textChanged(const QString &arg1)
{
    updateData(true,false,true);
}

void SUStudentInfo::on_lineEdit_3_textChanged(const QString &arg1)
{
    updateData(true,false,true);
}

void SUStudentInfo::updateData(bool setScore, bool updStudent, bool scoreFromSpinBox){
    int classes = 0;
    int visitedClasses = 0;
    int bonuses = 0;
    int presentation = 0;
    try
    {
        classes = ui->label_9->text().toInt();
        visitedClasses = ui->lineEdit->text().toInt();
        bonuses = ui->lineEdit_2->text().toInt();
        presentation = ui->lineEdit_3->text().toInt();
    }
    catch(...)
    {
        QMessageBox::warning( NULL, "QTestSuite",
                              QString::fromLocal8Bit("Неправильный число посещений."),
                              QMessageBox::Ok, QMessageBox::Ok );
        return;
    }
    try
    {
        Student stud = select<Student>( *pDB,
                                        Student::GroupNum == curStud->groupNum.value() &&
                                        Student::Surname == curStud->surname.value()).one();
        stud.numClasses = classes;
        stud.visitedClasses = visitedClasses;
        stud.bonuses = bonuses;
        stud.presentation = presentation;
        stud.update();

    }
    catch( Except e )
    {
        curStud = new Student( *pDB );
        curStud->groupNum = curStud->groupNum.value();
        curStud->surname = curStud->surname.value();
        curStud->numClasses = curStud->numClasses.value();
        curStud->visitedClasses = curStud->visitedClasses.value();
        curStud->bonuses = curStud->bonuses.value();
        curStud->presentation = curStud->presentation.value();
        curStud->update();
    }


    Student stud = select<Student>( *pDB,
                                    Student::GroupNum == curStud->groupNum.value() &&
                                    Student::Surname == curStud->surname.value()).one();
    ClipsStdoutRouter router;
    Clips::ClipsCPPEnv env;
    env.Load(sClipsRulesFile1);
    env.AddRouter("ClipsStdoutRouter", 10, &router);
    int minScore = 0;
    int maxScore = 0;
    int maxPossibleScore = 0;
    getScores( minScore, maxScore, maxPossibleScore ); // uses testQuestions[], curStud

    qDebug()<<"Min:"<<minScore<<"Max:"<<minScore<<"MaxPossible:"<<maxPossibleScore;

    router.emptyBuffer();
    env.Reset();
    AddScoresData1(minScore,
                   maxScore,
                   maxPossibleScore,
                   stud.groupNum,
                   stud.surname,
                   stud.numClasses,
                   stud.visitedClasses,
                   stud.bonuses,
                   stud.presentation
                   );
    env.Run(-1);
    QString rr = router.getBuffer();
    int score=ui->spinBox->value();

    if (!rr.isEmpty() && !scoreFromSpinBox)score = rr.at(11).digitValue();

    stud.score = score;
    stud.checked = 1;

    if (setScore) ui->spinBox->setValue(score);
    if (updStudent) stud.update();

    ui->label_11->setText(router.getBuffer());
}
