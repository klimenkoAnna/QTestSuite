#ifndef testsuitedb_hpp
#define testsuitedb_hpp
#include "litesql.hpp"
namespace TestSuite {
class Test;
class TestQuestion;
class TestAnswer;
class Student;
class StudentAnswer;
class StudentCustomAnswer;
class TestTestQuestionRelation {
public:
    class Row {
    public:
        litesql::Field<int> testQuestion;
        litesql::Field<int> test;
        Row(const litesql::Database& db, const litesql::Record& rec=litesql::Record());
    };
    static const std::string table__;
    static const litesql::FieldType Test;
    static const litesql::FieldType TestQuestion;
    static void link(const litesql::Database& db, const TestSuite::Test& o0, const TestSuite::TestQuestion& o1);
    static void unlink(const litesql::Database& db, const TestSuite::Test& o0, const TestSuite::TestQuestion& o1);
    static void del(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    static litesql::DataSource<TestTestQuestionRelation::Row> getRows(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    template <class T> static litesql::DataSource<T> get(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
;
;
};
class StudentTestRelation {
public:
    class Row {
    public:
        litesql::Field<int> test;
        litesql::Field<int> student;
        Row(const litesql::Database& db, const litesql::Record& rec=litesql::Record());
    };
    static const std::string table__;
    static const litesql::FieldType Student;
    static const litesql::FieldType Test;
    static void link(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::Test& o1);
    static void unlink(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::Test& o1);
    static void del(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    static litesql::DataSource<StudentTestRelation::Row> getRows(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    template <class T> static litesql::DataSource<T> get(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
;
;
};
class StudentAnswerTestRelation {
public:
    class Row {
    public:
        litesql::Field<int> test;
        litesql::Field<int> studentAnswer;
        Row(const litesql::Database& db, const litesql::Record& rec=litesql::Record());
    };
    static const std::string table__;
    static const litesql::FieldType StudentAnswer;
    static const litesql::FieldType Test;
    static void link(const litesql::Database& db, const TestSuite::StudentAnswer& o0, const TestSuite::Test& o1);
    static void unlink(const litesql::Database& db, const TestSuite::StudentAnswer& o0, const TestSuite::Test& o1);
    static void del(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    static litesql::DataSource<StudentAnswerTestRelation::Row> getRows(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    template <class T> static litesql::DataSource<T> get(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
;
;
};
class StudentCustomAnswerTestRelation {
public:
    class Row {
    public:
        litesql::Field<int> test;
        litesql::Field<int> studentCustomAnswer;
        Row(const litesql::Database& db, const litesql::Record& rec=litesql::Record());
    };
    static const std::string table__;
    static const litesql::FieldType StudentCustomAnswer;
    static const litesql::FieldType Test;
    static void link(const litesql::Database& db, const TestSuite::StudentCustomAnswer& o0, const TestSuite::Test& o1);
    static void unlink(const litesql::Database& db, const TestSuite::StudentCustomAnswer& o0, const TestSuite::Test& o1);
    static void del(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    static litesql::DataSource<StudentCustomAnswerTestRelation::Row> getRows(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    template <class T> static litesql::DataSource<T> get(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
;
;
};
class TestAnswerTestQuestionRelation {
public:
    class Row {
    public:
        litesql::Field<int> testQuestion;
        litesql::Field<int> testAnswer;
        Row(const litesql::Database& db, const litesql::Record& rec=litesql::Record());
    };
    static const std::string table__;
    static const litesql::FieldType TestAnswer;
    static const litesql::FieldType TestQuestion;
    static void link(const litesql::Database& db, const TestSuite::TestAnswer& o0, const TestSuite::TestQuestion& o1);
    static void unlink(const litesql::Database& db, const TestSuite::TestAnswer& o0, const TestSuite::TestQuestion& o1);
    static void del(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    static litesql::DataSource<TestAnswerTestQuestionRelation::Row> getRows(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    template <class T> static litesql::DataSource<T> get(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
;
;
};
class StudentStudentAnswerRelation {
public:
    class Row {
    public:
        litesql::Field<int> studentAnswer;
        litesql::Field<int> student;
        Row(const litesql::Database& db, const litesql::Record& rec=litesql::Record());
    };
    static const std::string table__;
    static const litesql::FieldType Student;
    static const litesql::FieldType StudentAnswer;
    static void link(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::StudentAnswer& o1);
    static void unlink(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::StudentAnswer& o1);
    static void del(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    static litesql::DataSource<StudentStudentAnswerRelation::Row> getRows(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    template <class T> static litesql::DataSource<T> get(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
;
;
};
class StudentStudentCustomAnswerRelation {
public:
    class Row {
    public:
        litesql::Field<int> studentCustomAnswer;
        litesql::Field<int> student;
        Row(const litesql::Database& db, const litesql::Record& rec=litesql::Record());
    };
    static const std::string table__;
    static const litesql::FieldType Student;
    static const litesql::FieldType StudentCustomAnswer;
    static void link(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::StudentCustomAnswer& o1);
    static void unlink(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::StudentCustomAnswer& o1);
    static void del(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    static litesql::DataSource<StudentStudentCustomAnswerRelation::Row> getRows(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr());
    template <class T> static litesql::DataSource<T> get(const litesql::Database& db, const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
;
;
};
class Test : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    class QuestionsHandle : public litesql::RelationHandle<Test> {
    public:
        QuestionsHandle(const Test& owner);
        void link(const TestQuestion& o0);
        void unlink(const TestQuestion& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<TestQuestion> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<TestTestQuestionRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    class StudentsHandle : public litesql::RelationHandle<Test> {
    public:
        StudentsHandle(const Test& owner);
        void link(const Student& o0);
        void unlink(const Student& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<Student> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentTestRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    class StudentAnswersHandle : public litesql::RelationHandle<Test> {
    public:
        StudentAnswersHandle(const Test& owner);
        void link(const StudentAnswer& o0);
        void unlink(const StudentAnswer& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<StudentAnswer> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentAnswerTestRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    class StudentCustomAnswersHandle : public litesql::RelationHandle<Test> {
    public:
        StudentCustomAnswersHandle(const Test& owner);
        void link(const StudentCustomAnswer& o0);
        void unlink(const StudentCustomAnswer& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<StudentCustomAnswer> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentCustomAnswerTestRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType TestName;
    litesql::Field<std::string> testName;
protected:
    void defaults();
public:
    Test(const litesql::Database& db);
    Test(const litesql::Database& db, const litesql::Record& rec);
    Test(const Test& obj);
    const Test& operator=(const Test& obj);
    Test::QuestionsHandle questions();
    Test::StudentsHandle students();
    Test::StudentAnswersHandle studentAnswers();
    Test::StudentCustomAnswersHandle studentCustomAnswers();
protected:
    std::string insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs);
    void create();
    virtual void addUpdates(Updates& updates);
    virtual void addIDUpdates(Updates& updates);
public:
    static void getFieldTypes(std::vector<litesql::FieldType>& ftypes);
protected:
    virtual void delRecord();
    virtual void delRelations();
public:
    virtual void update();
    virtual void del();
    virtual bool typeIsCorrect();
    std::auto_ptr<Test> upcast();
    std::auto_ptr<Test> upcastCopy();
};
std::ostream & operator<<(std::ostream& os, Test o);
class TestQuestion : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    class TestHandle : public litesql::RelationHandle<TestQuestion> {
    public:
        TestHandle(const TestQuestion& owner);
        void link(const Test& o0);
        void unlink(const Test& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<Test> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<TestTestQuestionRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    class AnswersHandle : public litesql::RelationHandle<TestQuestion> {
    public:
        AnswersHandle(const TestQuestion& owner);
        void link(const TestAnswer& o0);
        void unlink(const TestAnswer& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<TestAnswer> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<TestAnswerTestQuestionRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType QuestionNum;
    litesql::Field<int> questionNum;
    static const litesql::FieldType QuestionText;
    litesql::Field<std::string> questionText;
    static const litesql::FieldType QuestionPicture;
    litesql::Field<std::string> questionPicture;
    static const litesql::FieldType QuestionFormula;
    litesql::Field<std::string> questionFormula;
protected:
    void defaults();
public:
    TestQuestion(const litesql::Database& db);
    TestQuestion(const litesql::Database& db, const litesql::Record& rec);
    TestQuestion(const TestQuestion& obj);
    const TestQuestion& operator=(const TestQuestion& obj);
    TestQuestion::TestHandle test();
    TestQuestion::AnswersHandle answers();
protected:
    std::string insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs);
    void create();
    virtual void addUpdates(Updates& updates);
    virtual void addIDUpdates(Updates& updates);
public:
    static void getFieldTypes(std::vector<litesql::FieldType>& ftypes);
protected:
    virtual void delRecord();
    virtual void delRelations();
public:
    virtual void update();
    virtual void del();
    virtual bool typeIsCorrect();
    std::auto_ptr<TestQuestion> upcast();
    std::auto_ptr<TestQuestion> upcastCopy();
};
std::ostream & operator<<(std::ostream& os, TestQuestion o);
class TestAnswer : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    class QuestionHandle : public litesql::RelationHandle<TestAnswer> {
    public:
        QuestionHandle(const TestAnswer& owner);
        void link(const TestQuestion& o0);
        void unlink(const TestQuestion& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<TestQuestion> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<TestAnswerTestQuestionRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType AnswerNum;
    litesql::Field<int> answerNum;
    static const litesql::FieldType AnswerText;
    litesql::Field<std::string> answerText;
    static const litesql::FieldType AnswerPicture;
    litesql::Field<std::string> answerPicture;
    static const litesql::FieldType AnswerFormula;
    litesql::Field<std::string> answerFormula;
    static const litesql::FieldType IsRight;
    litesql::Field<bool> isRight;
protected:
    void defaults();
public:
    TestAnswer(const litesql::Database& db);
    TestAnswer(const litesql::Database& db, const litesql::Record& rec);
    TestAnswer(const TestAnswer& obj);
    const TestAnswer& operator=(const TestAnswer& obj);
    TestAnswer::QuestionHandle question();
protected:
    std::string insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs);
    void create();
    virtual void addUpdates(Updates& updates);
    virtual void addIDUpdates(Updates& updates);
public:
    static void getFieldTypes(std::vector<litesql::FieldType>& ftypes);
protected:
    virtual void delRecord();
    virtual void delRelations();
public:
    virtual void update();
    virtual void del();
    virtual bool typeIsCorrect();
    std::auto_ptr<TestAnswer> upcast();
    std::auto_ptr<TestAnswer> upcastCopy();
};
std::ostream & operator<<(std::ostream& os, TestAnswer o);
class Student : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    class TestHandle : public litesql::RelationHandle<Student> {
    public:
        TestHandle(const Student& owner);
        void link(const Test& o0);
        void unlink(const Test& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<Test> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentTestRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    class AnswersHandle : public litesql::RelationHandle<Student> {
    public:
        AnswersHandle(const Student& owner);
        void link(const StudentAnswer& o0);
        void unlink(const StudentAnswer& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<StudentAnswer> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentStudentAnswerRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    class CustomAnswerHandle : public litesql::RelationHandle<Student> {
    public:
        CustomAnswerHandle(const Student& owner);
        void link(const StudentCustomAnswer& o0);
        void unlink(const StudentCustomAnswer& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<StudentCustomAnswer> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentStudentCustomAnswerRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType GroupNum;
    litesql::Field<int> groupNum;
    static const litesql::FieldType Surname;
    litesql::Field<std::string> surname;
    static const litesql::FieldType NumClasses;
    litesql::Field<int> numClasses;
    static const litesql::FieldType VisitedClasses;
    litesql::Field<int> visitedClasses;
    static const litesql::FieldType Bonuses;
    litesql::Field<int> bonuses;
    static const litesql::FieldType Presentation;
    litesql::Field<int> presentation;
    static const litesql::FieldType Score;
    litesql::Field<int> score;
    static const litesql::FieldType Checked;
    litesql::Field<int> checked;
protected:
    void defaults();
public:
    Student(const litesql::Database& db);
    Student(const litesql::Database& db, const litesql::Record& rec);
    Student(const Student& obj);
    const Student& operator=(const Student& obj);
    Student::TestHandle test();
    Student::AnswersHandle answers();
    Student::CustomAnswerHandle customAnswer();
protected:
    std::string insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs);
    void create();
    virtual void addUpdates(Updates& updates);
    virtual void addIDUpdates(Updates& updates);
public:
    static void getFieldTypes(std::vector<litesql::FieldType>& ftypes);
protected:
    virtual void delRecord();
    virtual void delRelations();
public:
    virtual void update();
    virtual void del();
    virtual bool typeIsCorrect();
    std::auto_ptr<Student> upcast();
    std::auto_ptr<Student> upcastCopy();
};
std::ostream & operator<<(std::ostream& os, Student o);
class StudentAnswer : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    class TestHandle : public litesql::RelationHandle<StudentAnswer> {
    public:
        TestHandle(const StudentAnswer& owner);
        void link(const Test& o0);
        void unlink(const Test& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<Test> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentAnswerTestRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    class StudentHandle : public litesql::RelationHandle<StudentAnswer> {
    public:
        StudentHandle(const StudentAnswer& owner);
        void link(const Student& o0);
        void unlink(const Student& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<Student> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentStudentAnswerRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType QuestionNum;
    litesql::Field<int> questionNum;
    static const litesql::FieldType AnswerNum;
    litesql::Field<int> answerNum;
    static const litesql::FieldType Selected;
    litesql::Field<bool> selected;
protected:
    void defaults();
public:
    StudentAnswer(const litesql::Database& db);
    StudentAnswer(const litesql::Database& db, const litesql::Record& rec);
    StudentAnswer(const StudentAnswer& obj);
    const StudentAnswer& operator=(const StudentAnswer& obj);
    StudentAnswer::TestHandle test();
    StudentAnswer::StudentHandle student();
protected:
    std::string insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs);
    void create();
    virtual void addUpdates(Updates& updates);
    virtual void addIDUpdates(Updates& updates);
public:
    static void getFieldTypes(std::vector<litesql::FieldType>& ftypes);
protected:
    virtual void delRecord();
    virtual void delRelations();
public:
    virtual void update();
    virtual void del();
    virtual bool typeIsCorrect();
    std::auto_ptr<StudentAnswer> upcast();
    std::auto_ptr<StudentAnswer> upcastCopy();
};
std::ostream & operator<<(std::ostream& os, StudentAnswer o);
class StudentCustomAnswer : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    class TestHandle : public litesql::RelationHandle<StudentCustomAnswer> {
    public:
        TestHandle(const StudentCustomAnswer& owner);
        void link(const Test& o0);
        void unlink(const Test& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<Test> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentCustomAnswerTestRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    class StudentHandle : public litesql::RelationHandle<StudentCustomAnswer> {
    public:
        StudentHandle(const StudentCustomAnswer& owner);
        void link(const Student& o0);
        void unlink(const Student& o0);
        void del(const litesql::Expr& expr=litesql::Expr());
        litesql::DataSource<Student> get(const litesql::Expr& expr=litesql::Expr(), const litesql::Expr& srcExpr=litesql::Expr());
        litesql::DataSource<StudentStudentCustomAnswerRelation::Row> getRows(const litesql::Expr& expr=litesql::Expr());
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType QuestionNum;
    litesql::Field<int> questionNum;
    static const litesql::FieldType CustomAnswer;
    litesql::Field<std::string> customAnswer;
    static const litesql::FieldType Score;
    litesql::Field<int> score;
protected:
    void defaults();
public:
    StudentCustomAnswer(const litesql::Database& db);
    StudentCustomAnswer(const litesql::Database& db, const litesql::Record& rec);
    StudentCustomAnswer(const StudentCustomAnswer& obj);
    const StudentCustomAnswer& operator=(const StudentCustomAnswer& obj);
    StudentCustomAnswer::TestHandle test();
    StudentCustomAnswer::StudentHandle student();
protected:
    std::string insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs);
    void create();
    virtual void addUpdates(Updates& updates);
    virtual void addIDUpdates(Updates& updates);
public:
    static void getFieldTypes(std::vector<litesql::FieldType>& ftypes);
protected:
    virtual void delRecord();
    virtual void delRelations();
public:
    virtual void update();
    virtual void del();
    virtual bool typeIsCorrect();
    std::auto_ptr<StudentCustomAnswer> upcast();
    std::auto_ptr<StudentCustomAnswer> upcastCopy();
};
std::ostream & operator<<(std::ostream& os, StudentCustomAnswer o);
class TestSuiteDB : public litesql::Database {
public:
    TestSuiteDB(std::string backendType, std::string connInfo);
protected:
    virtual std::vector<litesql::Database::SchemaItem> getSchema() const;
    static void initialize();
};
}
#endif
