#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QStateMachine>
#include "suaddtest.h"
#include "SUTestsList.h"
#include "SUTestEdit.h"
#include "SUTestResults.h"
#include "SUStudResults.h"
#include "SUStudentInfo.h"
#include "qtestsuite_shareddefs.h"
#include <QTextCodec>
#include <locale.h>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("CP1251"));
    setlocale(LC_ALL, "ru_RU.KOI8-R");
    setlocale(LC_NUMERIC, "C");
    try
    {
        TestSuiteDB db("sqlite3", "database=TestSuite.db");
        db.verbose = false; // verbosity, prints queries to cerr if true
        if( db.needsUpgrade() )
        {
            db.upgrade();
        }
        pDB = &db;
        db.begin();

        QStringList paths = QCoreApplication::libraryPaths();
        paths.append(".");
        paths.append("platforms");
        QCoreApplication::setLibraryPaths(paths);

        QApplication a(argc, argv);
        SUTestsList       w5;
        SUTestEdit        w6;
        SUTestResults     w7;
        SUStudResults     w8;
        SUStudentInfo     w9;

        //---------------------------

        QStateMachine suiteStates;
        QState s_SUTestsList, s_SUTestEdit, s_SUTestResults, s_SUStudResults, s_SUStudentInfo;

        s_SUTestsList  .addTransition( &w5, SIGNAL( GoToSUTestEdit() ),     &s_SUTestEdit );      // test select  --> edit test
        s_SUTestEdit   .addTransition( &w6, SIGNAL( GoToSUTestsList() ),    &s_SUTestsList );     //              <--

        s_SUTestsList  .addTransition( &w5, SIGNAL( GoToSUTestResults() ),  &s_SUTestResults );   // test select  --> test results
        s_SUTestResults.addTransition( &w7, SIGNAL( GoToSUTestsLits() ),    &s_SUTestsList );     //              <--

        s_SUTestResults.addTransition( &w7, SIGNAL( GoToSUStudResults() ),  &s_SUStudResults );   // test results --> student results
        s_SUStudResults.addTransition( &w8, SIGNAL( GoToSUTestResults() ),  &s_SUTestResults );   //              <--
        s_SUTestResults.addTransition( &w7, SIGNAL( GoToSUStudentInfo() ),  &s_SUStudentInfo);
        s_SUStudentInfo.addTransition( &w9, SIGNAL( GoToSUTestResults() ),  &s_SUTestResults);

        QObject::connect( &s_SUTestsList,   SIGNAL( exited()  ), &w5, SLOT( hide() ) );
        QObject::connect( &s_SUTestsList,   SIGNAL( entered() ), &w5, SLOT( show() ) );
        QObject::connect( &s_SUTestsList,   SIGNAL( entered() ), &w5, SLOT( updateUI() ) );

        QObject::connect( &s_SUTestEdit,    SIGNAL( exited()  ), &w6, SLOT( hide() ) );
        QObject::connect( &s_SUTestEdit,    SIGNAL( entered() ), &w6, SLOT( show() ) );
        QObject::connect( &s_SUTestEdit,    SIGNAL( entered() ), &w6, SLOT( updateUI() ) );

        QObject::connect( &s_SUTestResults, SIGNAL( exited()  ), &w7, SLOT( hide() ) );
        QObject::connect( &s_SUTestResults, SIGNAL( entered() ), &w7, SLOT( show() ) );
        QObject::connect( &s_SUTestResults, SIGNAL( entered() ), &w7, SLOT( updateUI() ) );

        QObject::connect( &s_SUStudResults, SIGNAL( exited()  ), &w8, SLOT( hide() ) );
        QObject::connect( &s_SUStudResults, SIGNAL( entered() ), &w8, SLOT( show() ) );
        QObject::connect( &s_SUStudResults, SIGNAL( entered() ), &w8, SLOT( updateUI() ) );


        QObject::connect( &s_SUStudentInfo, SIGNAL( exited()  ), &w9, SLOT( hide() ) );
        QObject::connect( &s_SUStudentInfo, SIGNAL( entered() ), &w9, SLOT( show() ) );
        QObject::connect( &s_SUStudentInfo, SIGNAL( entered() ), &w9, SLOT( updateUI() ) );

        suiteStates.addState( &s_SUTestsList );
        suiteStates.addState( &s_SUTestEdit );
        suiteStates.addState( &s_SUTestResults );
        suiteStates.addState( &s_SUStudResults );
        suiteStates.addState( &s_SUStudentInfo );

        suiteStates.setInitialState( &s_SUTestsList );
        suiteStates.start();

        //---------------------------

        if( curStud )
            delete curStud;
        if( curTest )
            delete curTest;

        db.commit();
        return a.exec();
    }
    catch( Except e )
    {
        cerr << e << endl;
        QMessageBox::critical( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        return 0;
    }
}
