#-------------------------------------------------
#
# Project created by QtCreator 2012-09-08T20:04:36
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = QTestSuite
TEMPLATE = app


SOURCES +=\
    ../db_code/updatequery.cpp \
    ../db_code/string.cpp \
    ../db_code/sqlite3_backend.cpp \
    ../db_code/split.cpp \
    ../db_code/selectquery.cpp \
    ../db_code/postgresql.cpp \
    ../db_code/persistent.cpp \
    ../db_code/odbc_backend.cpp \
    ../db_code/ocilib_backend.cpp \
    ../db_code/mysql.cpp \
    ../db_code/field.cpp \
    ../db_code/expr.cpp \
    ../db_code/datetime.cpp \
    ../db_code/datasource.cpp \
    ../db_code/database.cpp \
    ../db_code/compatibility.cpp \
    ../db_code/backend.cpp \
    ../db_code/sqlite3.c \
    ../qtestsuite_shareddefs.cpp \
    TestWindow.cpp \
    MAIN_user.cpp \
    TestSelectWindow.cpp \
    MainWindow.cpp \
    TestResultsWindow.cpp \
    ../db_code/_TestSuiteDB.cpp \
    ../db_code/QDBCheckBox.cpp

HEADERS  += \
    ../db_code/TestSuiteDB.hpp \
    ../db_code/litesql.hpp \
    ../db_code/config.h \
    ../db_code/litesql/utils.hpp \
    ../db_code/litesql/updatequery.hpp \
    ../db_code/litesql/types.hpp \
    ../db_code/litesql/string.hpp \
    ../db_code/litesql/split.hpp \
    ../db_code/litesql/selectquery.hpp \
    ../db_code/litesql/relation.hpp \
    ../db_code/litesql/persistent.hpp \
    ../db_code/litesql/operations.hpp \
    ../db_code/litesql/field.hpp \
    ../db_code/litesql/expr.hpp \
    ../db_code/litesql/except.hpp \
    ../db_code/litesql/datetime.hpp \
    ../db_code/litesql/datasource.hpp \
    ../db_code/litesql/database.hpp \
    ../db_code/litesql/cursor.hpp \
    ../db_code/litesql/counted_ptr.hpp \
    ../db_code/litesql/commontypes.h \
    ../db_code/litesql/backend.hpp \
    ../db_code/sqlite3ext.h \
    ../db_code/sqlite3.hpp \
    ../db_code/sqlite3.h \
    ../db_code/postgresql.hpp \
    ../db_code/odbc_backend.hpp \
    ../db_code/ocilib_backend.hpp \
    ../db_code/mysql.hpp \
    ../db_code/compatibility.hpp \
    ../qtestsuite_shareddefs.h \
    TestWindow.h \
    TestSelectWindow.h \
    MainWindow.h \
    TestResultsWindow.h \
    ../db_code/_TestSuiteDB.hpp \
    ../db_code/QDBCheckBox.h

FORMS    += \
    TestWindow.ui \
    TestSelectWindow.ui \
    MainWindow.ui \
    TestResultsWindow.ui

OTHER_FILES +=

INCLUDEPATH += $$PWD/..
INCLUDEPATH += $$PWD/../db_code
INCLUDEPATH += $$PWD/../qtmmlwidget
DEPENDPATH += $$PWD/../qtmmlwidget
