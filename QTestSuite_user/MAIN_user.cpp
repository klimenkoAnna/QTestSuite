#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QStateMachine>
#include "MainWindow.h"
#include "TestSelectWindow.h"
#include "TestWindow.h"
#include "TestResultsWindow.h"
#include "qtestsuite_shareddefs.h"

int main(int argc, char *argv[])
{
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
        MainWindow        w1;
        TestSelectWindow  w2;
        TestWindow        w3;
        TestResultsWindow w4;

        //---------------------------

        QStateMachine suiteStates;
        QState s_Main, s_TestSelect, s_Test, s_TestResuls;

        s_Main            .addTransition( &w1, SIGNAL( GoToTestSelectWnd() ),  &s_TestSelect );        // student/user login    --> test select
        s_TestSelect      .addTransition( &w2, SIGNAL( GoToTestWnd() ),        &s_Test );              // test select           --> test
        s_Test            .addTransition( &w3, SIGNAL( GoToTestResultsWnd() ), &s_TestResuls );        // test                  --> results
        s_Test            .addTransition( &w3, SIGNAL( GoToTestSelectWnd() ),  &s_TestSelect );        // test                  --> test select (error)
        s_TestResuls      .addTransition( &w4, SIGNAL( GoToLoginWnd() ),       &s_Main );              // results               --> login


        QObject::connect( &s_Main,          SIGNAL( exited()  ), &w1, SLOT( hide() ) );           //сигнал exited() объекта s_Main связывается со слотом объекта w1
        QObject::connect( &s_Main,          SIGNAL( entered() ), &w1, SLOT( show() ) );
        QObject::connect( &s_Main,          SIGNAL( entered() ), &w1, SLOT( updateUI() ) );

        QObject::connect( &s_TestSelect,    SIGNAL( exited()  ), &w2, SLOT( hide() ) );
        QObject::connect( &s_TestSelect,    SIGNAL( entered() ), &w2, SLOT( show() ) );
        QObject::connect( &s_TestSelect,    SIGNAL( entered() ), &w2, SLOT( updateUI() ) );

        QObject::connect( &s_Test,          SIGNAL( exited()  ), &w3, SLOT( hide() ) );
        QObject::connect( &s_Test,          SIGNAL( entered() ), &w3, SLOT( show() ) );
        QObject::connect( &s_Test,          SIGNAL( entered() ), &w3, SLOT( updateUI() ) );

        QObject::connect( &s_TestResuls,    SIGNAL( exited()  ), &w4, SLOT( hide() ) );
        QObject::connect( &s_TestResuls,    SIGNAL( entered() ), &w4, SLOT( show() ) );
        QObject::connect( &s_TestResuls,    SIGNAL( entered() ), &w4, SLOT( updateUI() ) );

        suiteStates.addState( &s_Main );
        suiteStates.addState( &s_TestSelect );
        suiteStates.addState( &s_Test );
        suiteStates.addState( &s_TestResuls );

        suiteStates.setInitialState( &s_Main );
        suiteStates.start();

        //---------------------------

        w1.show();

        int exec = a.exec();

        if( curStud )
            delete curStud;
        if( curTest )
            delete curTest;

        db.commit();

        return exec;
    }
    catch( Except e )
    {
        cerr << e << endl;
        QMessageBox::critical( NULL, "QTestSuite", e.what(), QMessageBox::Ok, QMessageBox::Ok );
        return 0;
    }
}
