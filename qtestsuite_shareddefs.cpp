#include "qtestsuite_shareddefs.h"

//char* sSecretPhrase = "QTestSuite"; // the cipher
char sSecretPhrase[] = "QTestSuite";
TestSuiteDB *pDB = NULL;
Student *curStud = NULL;
TestSuite::Test *curTest = NULL;
int curQuestionNum = 0;
std::vector <TestSuite::TestQuestion> testQuestions;
std::vector <TestSuite::TestAnswer>   testAnswers;

//---------------------------------------------------

#include <QtWidgets/QMessageBox>

char* str_xor( const char* str, int str_len, const char* key, int key_len )
{
    char *res = new char[str_len+1];
    memset (res, 0, str_len);

    int k = key_len;
    for( int i = 0; i < str_len; ++i )
    {
        if( str[i] == 28 || str[i] == 1 )
        {
            res[i] = ( str[i]-1 ) ^ key[--k];
            continue;
        }

        res[i] = str[i] ^ key[--k];

        if( res[i] == 27 || res[i] == 0 ) // if we ciphered into some shit - fix it
        {
            ++res[i];
        }

        k = k <= 0 ? key_len : k;
    }

    res[str_len] = '\0';
    return res;
}

//---------------------------------------------------

QString stdstr_to_qstr( std::string text )
{
    return QString::fromLocal8Bit( text.c_str() );
}

QString decipher( std::string ciphertext )
{
    const char* str = ciphertext.c_str();
    char *ptext = str_xor( str, ciphertext.length(), sSecretPhrase, strlen(sSecretPhrase) );
    QString qstr_ret = QString::fromLocal8Bit( ptext );
    delete ptext;
    return qstr_ret;
}

//---------------------------------------------------

std::string qstr_to_stdstr( QString text )
{
    QByteArray ba = text.toLocal8Bit();
    const char *c_str2 = ba.data();
    return std::string( c_str2 );
}

std::string cipher( QString plaintext )
{
    QByteArray ba = plaintext.toLocal8Bit();
    char *ctext = str_xor( ba.data(), plaintext.length(), sSecretPhrase, strlen(sSecretPhrase) );
    std::string str_ret( ctext );
    delete ctext;
    return str_ret;
}

//---------------------------------------------------

void getScores( int &minScore, int &maxScore, int &maxPossibleScore )
{
    if( !curTest || !curStud )
    {
        throw Except( "Ошибка программы." );
    }

    testQuestions = curTest->questions().get().orderBy( TestSuite::TestQuestion::QuestionNum ).all();
    int totalQuestions = testQuestions.size();
    minScore = 0;
    maxScore = 0;
    maxPossibleScore = 0;
    std::vector <TestSuite::StudentAnswer> studAns;

    for( int i = 0; i < totalQuestions; ++i )
    {
        //TestSuite::TestQuestion q = testQuestions[i];
        //testAnswers = q.answers().get().orderBy( TestSuite::TestAnswer::AnswerNum ).all();

        testAnswers = testQuestions[i].answers().get().orderBy( TestSuite::TestAnswer::AnswerNum ).all();

        //studAns = curStud->answers().get( TestSuite::StudentAnswer::QuestionNum == i ).orderBy( TestSuite::StudentAnswer::AnswerNum ).all();
        studAns = intersect( curStud->answers().get( TestSuite::StudentAnswer::QuestionNum == i ),
                             curTest->studentAnswers().get( TestSuite::StudentAnswer::QuestionNum == i ) )
                .orderBy( TestSuite::StudentAnswer::AnswerNum ).all();

        int totalQuestionAnswers1 = studAns.size();
        int totalQuestionAnswers  = testAnswers.size();

#if 1
        if( totalQuestionAnswers )
        {
            int matched = 0;
            for( int j = 0; j < totalQuestionAnswers && j < totalQuestionAnswers1; ++j )
            {
                if( testAnswers[j].isRight.value() == studAns[j].selected.value() )
                {
                    ++matched;
                }
            }
            if( matched == totalQuestionAnswers )
            {
                minScore     += QTESTSUITE_STD_ANSWER_WORTH;
                maxScore     += QTESTSUITE_STD_ANSWER_WORTH;
            }
            maxPossibleScore += QTESTSUITE_STD_ANSWER_WORTH;
        }
        else // custom answer
        {
            StudentCustomAnswer sca = curStud->customAnswer().get(TestSuite::StudentCustomAnswer::QuestionNum == i).one();
            minScore         += sca.score;
            maxScore         += QTESTSUITE_CUSTOM_ANSWER_WORTH;
            maxPossibleScore += QTESTSUITE_CUSTOM_ANSWER_WORTH;
        }
#else
        std::cerr << studAns.size() << " " << testAnswers.size() << endl;
#endif
    }
}
