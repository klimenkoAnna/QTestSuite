#include "suaddtest.h"
#include "ui_suaddtest.h"
#include <QtWidgets/QMessageBox>
#include "clipscpp.h"
#include <QRegExpValidator>



/*char* sClipsRulesFile1 = "clips_test_results_rules.clp";

void AddScoresData1(int minScore, int maxScore, int maxPossibleScore, int groupNum, std::string surname)
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

    //AssignFactSlotDefaults(newFact);

    //EnvAssert(GetCurrentEnvironment(),newFact);
    Assert(newFact);
}*/

SUAddTest::SUAddTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SUAddTest)
{
    ui->setupUi(this);
    ui->OkButton->setEnabled(false);
    QRegExp exp("[a-zA-Z]{1,5}[1-9]{1}[0-9]{0,3}");
    ui->lineEdit->setValidator(new QRegExpValidator(exp,this));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(OkEnabled()));
}

void SUAddTest::OkEnabled()
{
    ui->OkButton->setEnabled(ui->lineEdit->hasAcceptableInput());

}

SUAddTest::~SUAddTest()
{
    delete ui;
}


void SUAddTest::on_SaveButton_clicked()
{
    Clips::ClipsCPPEnv theEnv;

       // For load to work, the CLIPS file must be in the
       // the same directory as the executable, otherwise
       // the full path should be specified.
       theEnv.Load("hello.clp");

      /* theEnv.build("(defrule hello"
                    "   =>"
                    "  (printout t \"Hello World.\" crlf)"
                    "  (printout t \"Hit return to end.\" crlf)"
                    "  (readline))");*/

       theEnv.Reset();
       theEnv.Run(-1);
}
