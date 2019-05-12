#ifndef qtestsuite_shareddefs_h
#define qtestsuite_shareddefs_h

//#pragma warning(disable: 4100)

#include <QString>
#include "db_code\_TestSuiteDB.hpp"

using namespace litesql;
using namespace TestSuite;

#define QTESTSUITE_MAX_ANS              10
#define QTESTSUITE_SALT_LEN             8
#define QTESTSUITE_STD_ANSWER_WORTH     1
#define QTESTSUITE_CUSTOM_ANSWER_WORTH  2
#define QTESTSUITE_HIDE_FINISHED_TESTS  1 /// TODO: set

//extern char* sSecretPhrase;  // the cipher
extern char sSecretPhrase[];  // the cipher

extern TestSuiteDB *pDB;
extern Student *curStud;
extern TestSuite::Test *curTest;
extern int curQuestionNum;
extern std::vector <TestSuite::TestQuestion> testQuestions;
extern std::vector <TestSuite::TestAnswer>   testAnswers;

extern QString stdstr_to_qstr( std::string text );
extern QString decipher( std::string ciphertext );
extern std::string qstr_to_stdstr( QString text );
extern std::string cipher( QString plaintext );

extern void getScores( int &minScore, int &maxScore, int &maxPossibleScore );

#endif
