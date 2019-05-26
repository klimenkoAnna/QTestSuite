#include "_TestSuiteDB.hpp"
namespace TestSuite {
using namespace litesql;
TestTestQuestionRelation::Row::Row(const litesql::Database& db, const litesql::Record& rec)
         : testQuestion(TestTestQuestionRelation::TestQuestion), test(TestTestQuestionRelation::Test) {
    switch(rec.size()) {
    case 2:
        testQuestion = rec[1];
    case 1:
        test = rec[0];
    }
}
const std::string TestTestQuestionRelation::table__("Test_TestQuestion_");
const litesql::FieldType TestTestQuestionRelation::Test("Test1_",A_field_type_integer,table__);
const litesql::FieldType TestTestQuestionRelation::TestQuestion("TestQuestion2_",A_field_type_integer,table__);
void TestTestQuestionRelation::link(const litesql::Database& db, const TestSuite::Test& o0, const TestSuite::TestQuestion& o1) {
    Record values;
    Split fields;
    fields.push_back(Test.name());
    values.push_back(o0.id);
    fields.push_back(TestQuestion.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void TestTestQuestionRelation::unlink(const litesql::Database& db, const TestSuite::Test& o0, const TestSuite::TestQuestion& o1) {
    db.delete_(table__, (Test == o0.id && TestQuestion == o1.id));
}
void TestTestQuestionRelation::del(const litesql::Database& db, const litesql::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<TestTestQuestionRelation::Row> TestTestQuestionRelation::getRows(const litesql::Database& db, const litesql::Expr& expr) {
    SelectQuery sel;
    sel.result(Test.fullName());
    sel.result(TestQuestion.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<TestTestQuestionRelation::Row>(db, sel);
}
template <> litesql::DataSource<TestSuite::Test> TestTestQuestionRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Test.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::Test>(db, TestSuite::Test::Id.in(sel) && expr);
}
template <> litesql::DataSource<TestSuite::TestQuestion> TestTestQuestionRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(TestQuestion.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::TestQuestion>(db, TestSuite::TestQuestion::Id.in(sel) && expr);
}
StudentTestRelation::Row::Row(const litesql::Database& db, const litesql::Record& rec)
         : test(StudentTestRelation::Test), student(StudentTestRelation::Student) {
    switch(rec.size()) {
    case 2:
        test = rec[1];
    case 1:
        student = rec[0];
    }
}
const std::string StudentTestRelation::table__("Student_Test_");
const litesql::FieldType StudentTestRelation::Student("Student1_",A_field_type_integer,table__);
const litesql::FieldType StudentTestRelation::Test("Test2_",A_field_type_integer,table__);
void StudentTestRelation::link(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::Test& o1) {
    Record values;
    Split fields;
    fields.push_back(Student.name());
    values.push_back(o0.id);
    fields.push_back(Test.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void StudentTestRelation::unlink(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::Test& o1) {
    db.delete_(table__, (Student == o0.id && Test == o1.id));
}
void StudentTestRelation::del(const litesql::Database& db, const litesql::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<StudentTestRelation::Row> StudentTestRelation::getRows(const litesql::Database& db, const litesql::Expr& expr) {
    SelectQuery sel;
    sel.result(Student.fullName());
    sel.result(Test.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<StudentTestRelation::Row>(db, sel);
}
template <> litesql::DataSource<TestSuite::Student> StudentTestRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Student.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::Student>(db, TestSuite::Student::Id.in(sel) && expr);
}
template <> litesql::DataSource<TestSuite::Test> StudentTestRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Test.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::Test>(db, TestSuite::Test::Id.in(sel) && expr);
}
StudentAnswerTestRelation::Row::Row(const litesql::Database& db, const litesql::Record& rec)
         : test(StudentAnswerTestRelation::Test), studentAnswer(StudentAnswerTestRelation::StudentAnswer) {
    switch(rec.size()) {
    case 2:
        test = rec[1];
    case 1:
        studentAnswer = rec[0];
    }
}
const std::string StudentAnswerTestRelation::table__("StudentAnswer_Test_");
const litesql::FieldType StudentAnswerTestRelation::StudentAnswer("StudentAnswer1_",A_field_type_integer,table__);
const litesql::FieldType StudentAnswerTestRelation::Test("Test2_",A_field_type_integer,table__);
void StudentAnswerTestRelation::link(const litesql::Database& db, const TestSuite::StudentAnswer& o0, const TestSuite::Test& o1) {
    Record values;
    Split fields;
    fields.push_back(StudentAnswer.name());
    values.push_back(o0.id);
    fields.push_back(Test.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void StudentAnswerTestRelation::unlink(const litesql::Database& db, const TestSuite::StudentAnswer& o0, const TestSuite::Test& o1) {
    db.delete_(table__, (StudentAnswer == o0.id && Test == o1.id));
}
void StudentAnswerTestRelation::del(const litesql::Database& db, const litesql::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<StudentAnswerTestRelation::Row> StudentAnswerTestRelation::getRows(const litesql::Database& db, const litesql::Expr& expr) {
    SelectQuery sel;
    sel.result(StudentAnswer.fullName());
    sel.result(Test.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<StudentAnswerTestRelation::Row>(db, sel);
}
template <> litesql::DataSource<TestSuite::StudentAnswer> StudentAnswerTestRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(StudentAnswer.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::StudentAnswer>(db, TestSuite::StudentAnswer::Id.in(sel) && expr);
}
template <> litesql::DataSource<TestSuite::Test> StudentAnswerTestRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Test.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::Test>(db, TestSuite::Test::Id.in(sel) && expr);
}
StudentCustomAnswerTestRelation::Row::Row(const litesql::Database& db, const litesql::Record& rec)
         : test(StudentCustomAnswerTestRelation::Test), studentCustomAnswer(StudentCustomAnswerTestRelation::StudentCustomAnswer) {
    switch(rec.size()) {
    case 2:
        test = rec[1];
    case 1:
        studentCustomAnswer = rec[0];
    }
}
const std::string StudentCustomAnswerTestRelation::table__("StudentCustomAnswer_Test_");
const litesql::FieldType StudentCustomAnswerTestRelation::StudentCustomAnswer("StudentCustomAnswer1_",A_field_type_integer,table__);
const litesql::FieldType StudentCustomAnswerTestRelation::Test("Test2_",A_field_type_integer,table__);
void StudentCustomAnswerTestRelation::link(const litesql::Database& db, const TestSuite::StudentCustomAnswer& o0, const TestSuite::Test& o1) {
    Record values;
    Split fields;
    fields.push_back(StudentCustomAnswer.name());
    values.push_back(o0.id);
    fields.push_back(Test.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void StudentCustomAnswerTestRelation::unlink(const litesql::Database& db, const TestSuite::StudentCustomAnswer& o0, const TestSuite::Test& o1) {
    db.delete_(table__, (StudentCustomAnswer == o0.id && Test == o1.id));
}
void StudentCustomAnswerTestRelation::del(const litesql::Database& db, const litesql::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<StudentCustomAnswerTestRelation::Row> StudentCustomAnswerTestRelation::getRows(const litesql::Database& db, const litesql::Expr& expr) {
    SelectQuery sel;
    sel.result(StudentCustomAnswer.fullName());
    sel.result(Test.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<StudentCustomAnswerTestRelation::Row>(db, sel);
}
template <> litesql::DataSource<TestSuite::StudentCustomAnswer> StudentCustomAnswerTestRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(StudentCustomAnswer.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::StudentCustomAnswer>(db, TestSuite::StudentCustomAnswer::Id.in(sel) && expr);
}
template <> litesql::DataSource<TestSuite::Test> StudentCustomAnswerTestRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Test.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::Test>(db, TestSuite::Test::Id.in(sel) && expr);
}
TestAnswerTestQuestionRelation::Row::Row(const litesql::Database& db, const litesql::Record& rec)
         : testQuestion(TestAnswerTestQuestionRelation::TestQuestion), testAnswer(TestAnswerTestQuestionRelation::TestAnswer) {
    switch(rec.size()) {
    case 2:
        testQuestion = rec[1];
    case 1:
        testAnswer = rec[0];
    }
}
const std::string TestAnswerTestQuestionRelation::table__("TestAnswer_TestQuestion_");
const litesql::FieldType TestAnswerTestQuestionRelation::TestAnswer("TestAnswer1_",A_field_type_integer,table__);
const litesql::FieldType TestAnswerTestQuestionRelation::TestQuestion("TestQuestion2_",A_field_type_integer,table__);
void TestAnswerTestQuestionRelation::link(const litesql::Database& db, const TestSuite::TestAnswer& o0, const TestSuite::TestQuestion& o1) {
    Record values;
    Split fields;
    fields.push_back(TestAnswer.name());
    values.push_back(o0.id);
    fields.push_back(TestQuestion.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void TestAnswerTestQuestionRelation::unlink(const litesql::Database& db, const TestSuite::TestAnswer& o0, const TestSuite::TestQuestion& o1) {
    db.delete_(table__, (TestAnswer == o0.id && TestQuestion == o1.id));
}
void TestAnswerTestQuestionRelation::del(const litesql::Database& db, const litesql::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<TestAnswerTestQuestionRelation::Row> TestAnswerTestQuestionRelation::getRows(const litesql::Database& db, const litesql::Expr& expr) {
    SelectQuery sel;
    sel.result(TestAnswer.fullName());
    sel.result(TestQuestion.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<TestAnswerTestQuestionRelation::Row>(db, sel);
}
template <> litesql::DataSource<TestSuite::TestAnswer> TestAnswerTestQuestionRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(TestAnswer.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::TestAnswer>(db, TestSuite::TestAnswer::Id.in(sel) && expr);
}
template <> litesql::DataSource<TestSuite::TestQuestion> TestAnswerTestQuestionRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(TestQuestion.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::TestQuestion>(db, TestSuite::TestQuestion::Id.in(sel) && expr);
}
StudentStudentAnswerRelation::Row::Row(const litesql::Database& db, const litesql::Record& rec)
         : studentAnswer(StudentStudentAnswerRelation::StudentAnswer), student(StudentStudentAnswerRelation::Student) {
    switch(rec.size()) {
    case 2:
        studentAnswer = rec[1];
    case 1:
        student = rec[0];
    }
}
const std::string StudentStudentAnswerRelation::table__("Student_StudentAnswer_");
const litesql::FieldType StudentStudentAnswerRelation::Student("Student1_",A_field_type_integer,table__);
const litesql::FieldType StudentStudentAnswerRelation::StudentAnswer("StudentAnswer2_",A_field_type_integer,table__);
void StudentStudentAnswerRelation::link(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::StudentAnswer& o1) {
    Record values;
    Split fields;
    fields.push_back(Student.name());
    values.push_back(o0.id);
    fields.push_back(StudentAnswer.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void StudentStudentAnswerRelation::unlink(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::StudentAnswer& o1) {
    db.delete_(table__, (Student == o0.id && StudentAnswer == o1.id));
}
void StudentStudentAnswerRelation::del(const litesql::Database& db, const litesql::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<StudentStudentAnswerRelation::Row> StudentStudentAnswerRelation::getRows(const litesql::Database& db, const litesql::Expr& expr) {
    SelectQuery sel;
    sel.result(Student.fullName());
    sel.result(StudentAnswer.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<StudentStudentAnswerRelation::Row>(db, sel);
}
template <> litesql::DataSource<TestSuite::Student> StudentStudentAnswerRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Student.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::Student>(db, TestSuite::Student::Id.in(sel) && expr);
}
template <> litesql::DataSource<TestSuite::StudentAnswer> StudentStudentAnswerRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(StudentAnswer.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::StudentAnswer>(db, TestSuite::StudentAnswer::Id.in(sel) && expr);
}
StudentStudentCustomAnswerRelation::Row::Row(const litesql::Database& db, const litesql::Record& rec)
         : studentCustomAnswer(StudentStudentCustomAnswerRelation::StudentCustomAnswer), student(StudentStudentCustomAnswerRelation::Student) {
    switch(rec.size()) {
    case 2:
        studentCustomAnswer = rec[1];
    case 1:
        student = rec[0];
    }
}
const std::string StudentStudentCustomAnswerRelation::table__("Student_StudentCustomAnswer_");
const litesql::FieldType StudentStudentCustomAnswerRelation::Student("Student1_",A_field_type_integer,table__);
const litesql::FieldType StudentStudentCustomAnswerRelation::StudentCustomAnswer("StudentCustomAnswer2_",A_field_type_integer,table__);
void StudentStudentCustomAnswerRelation::link(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::StudentCustomAnswer& o1) {
    Record values;
    Split fields;
    fields.push_back(Student.name());
    values.push_back(o0.id);
    fields.push_back(StudentCustomAnswer.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void StudentStudentCustomAnswerRelation::unlink(const litesql::Database& db, const TestSuite::Student& o0, const TestSuite::StudentCustomAnswer& o1) {
    db.delete_(table__, (Student == o0.id && StudentCustomAnswer == o1.id));
}
void StudentStudentCustomAnswerRelation::del(const litesql::Database& db, const litesql::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<StudentStudentCustomAnswerRelation::Row> StudentStudentCustomAnswerRelation::getRows(const litesql::Database& db, const litesql::Expr& expr) {
    SelectQuery sel;
    sel.result(Student.fullName());
    sel.result(StudentCustomAnswer.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<StudentStudentCustomAnswerRelation::Row>(db, sel);
}
template <> litesql::DataSource<TestSuite::Student> StudentStudentCustomAnswerRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Student.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::Student>(db, TestSuite::Student::Id.in(sel) && expr);
}
template <> litesql::DataSource<TestSuite::StudentCustomAnswer> StudentStudentCustomAnswerRelation::get(const litesql::Database& db, const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(StudentCustomAnswer.fullName());
    sel.where(srcExpr);
    return DataSource<TestSuite::StudentCustomAnswer>(db, TestSuite::StudentCustomAnswer::Id.in(sel) && expr);
}
const litesql::FieldType Test::Own::Id("id_",A_field_type_integer,"Test_");
Test::QuestionsHandle::QuestionsHandle(const Test& owner)
         : litesql::RelationHandle<Test>(owner) {
}
void Test::QuestionsHandle::link(const TestQuestion& o0) {
    TestTestQuestionRelation::link(owner->getDatabase(), *owner, o0);
}
void Test::QuestionsHandle::unlink(const TestQuestion& o0) {
    TestTestQuestionRelation::unlink(owner->getDatabase(), *owner, o0);
}
void Test::QuestionsHandle::del(const litesql::Expr& expr) {
    TestTestQuestionRelation::del(owner->getDatabase(), expr && TestTestQuestionRelation::Test == owner->id);
}
litesql::DataSource<TestQuestion> Test::QuestionsHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return TestTestQuestionRelation::get<TestQuestion>(owner->getDatabase(), expr, (TestTestQuestionRelation::Test == owner->id) && srcExpr);
}
litesql::DataSource<TestTestQuestionRelation::Row> Test::QuestionsHandle::getRows(const litesql::Expr& expr) {
    return TestTestQuestionRelation::getRows(owner->getDatabase(), expr && (TestTestQuestionRelation::Test == owner->id));
}
Test::StudentsHandle::StudentsHandle(const Test& owner)
         : litesql::RelationHandle<Test>(owner) {
}
void Test::StudentsHandle::link(const Student& o0) {
    StudentTestRelation::link(owner->getDatabase(), o0, *owner);
}
void Test::StudentsHandle::unlink(const Student& o0) {
    StudentTestRelation::unlink(owner->getDatabase(), o0, *owner);
}
void Test::StudentsHandle::del(const litesql::Expr& expr) {
    StudentTestRelation::del(owner->getDatabase(), expr && StudentTestRelation::Test == owner->id);
}
litesql::DataSource<Student> Test::StudentsHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentTestRelation::get<Student>(owner->getDatabase(), expr, (StudentTestRelation::Test == owner->id) && srcExpr);
}
litesql::DataSource<StudentTestRelation::Row> Test::StudentsHandle::getRows(const litesql::Expr& expr) {
    return StudentTestRelation::getRows(owner->getDatabase(), expr && (StudentTestRelation::Test == owner->id));
}
Test::StudentAnswersHandle::StudentAnswersHandle(const Test& owner)
         : litesql::RelationHandle<Test>(owner) {
}
void Test::StudentAnswersHandle::link(const StudentAnswer& o0) {
    StudentAnswerTestRelation::link(owner->getDatabase(), o0, *owner);
}
void Test::StudentAnswersHandle::unlink(const StudentAnswer& o0) {
    StudentAnswerTestRelation::unlink(owner->getDatabase(), o0, *owner);
}
void Test::StudentAnswersHandle::del(const litesql::Expr& expr) {
    StudentAnswerTestRelation::del(owner->getDatabase(), expr && StudentAnswerTestRelation::Test == owner->id);
}
litesql::DataSource<StudentAnswer> Test::StudentAnswersHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentAnswerTestRelation::get<StudentAnswer>(owner->getDatabase(), expr, (StudentAnswerTestRelation::Test == owner->id) && srcExpr);
}
litesql::DataSource<StudentAnswerTestRelation::Row> Test::StudentAnswersHandle::getRows(const litesql::Expr& expr) {
    return StudentAnswerTestRelation::getRows(owner->getDatabase(), expr && (StudentAnswerTestRelation::Test == owner->id));
}
Test::StudentCustomAnswersHandle::StudentCustomAnswersHandle(const Test& owner)
         : litesql::RelationHandle<Test>(owner) {
}
void Test::StudentCustomAnswersHandle::link(const StudentCustomAnswer& o0) {
    StudentCustomAnswerTestRelation::link(owner->getDatabase(), o0, *owner);
}
void Test::StudentCustomAnswersHandle::unlink(const StudentCustomAnswer& o0) {
    StudentCustomAnswerTestRelation::unlink(owner->getDatabase(), o0, *owner);
}
void Test::StudentCustomAnswersHandle::del(const litesql::Expr& expr) {
    StudentCustomAnswerTestRelation::del(owner->getDatabase(), expr && StudentCustomAnswerTestRelation::Test == owner->id);
}
litesql::DataSource<StudentCustomAnswer> Test::StudentCustomAnswersHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentCustomAnswerTestRelation::get<StudentCustomAnswer>(owner->getDatabase(), expr, (StudentCustomAnswerTestRelation::Test == owner->id) && srcExpr);
}
litesql::DataSource<StudentCustomAnswerTestRelation::Row> Test::StudentCustomAnswersHandle::getRows(const litesql::Expr& expr) {
    return StudentCustomAnswerTestRelation::getRows(owner->getDatabase(), expr && (StudentCustomAnswerTestRelation::Test == owner->id));
}
const std::string Test::type__("Test");
const std::string Test::table__("Test_");
const std::string Test::sequence__("Test_seq");
const litesql::FieldType Test::Id("id_",A_field_type_integer,table__);
const litesql::FieldType Test::Type("type_",A_field_type_string,table__);
const litesql::FieldType Test::TestName("testName_",A_field_type_string,table__);
void Test::defaults() {
    id = 0;
}
Test::Test(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), testName(TestName) {
    defaults();
}
Test::Test(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), testName(TestName) {
    defaults();
    size_t size = (rec.size() > 3) ? 3 : rec.size();
    switch(size) {
    case 3: testName = convert<const std::string&, std::string>(rec[2]);
        testName.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
Test::Test(const Test& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), testName(obj.testName) {
}
const Test& Test::operator=(const Test& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        testName = obj.testName;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
Test::QuestionsHandle Test::questions() {
    return Test::QuestionsHandle(*this);
}
Test::StudentsHandle Test::students() {
    return Test::StudentsHandle(*this);
}
Test::StudentAnswersHandle Test::studentAnswers() {
    return Test::StudentAnswersHandle(*this);
}
Test::StudentCustomAnswersHandle Test::studentCustomAnswers() {
    return Test::StudentCustomAnswersHandle(*this);
}
std::string Test::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(testName.name());
    values.push_back(testName);
    testName.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void Test::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Test::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, testName);
}
void Test::addIDUpdates(Updates& updates) {
}
void Test::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(TestName);
}
void Test::delRecord() {
    deleteFromTable(table__, id);
}
void Test::delRelations() {
    TestTestQuestionRelation::del(*db, (TestTestQuestionRelation::Test == id));
    StudentTestRelation::del(*db, (StudentTestRelation::Test == id));
    StudentAnswerTestRelation::del(*db, (StudentAnswerTestRelation::Test == id));
    StudentCustomAnswerTestRelation::del(*db, (StudentCustomAnswerTestRelation::Test == id));
}
void Test::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect())
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void Test::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<Test> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool Test::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<Test> Test::upcast() {
    return auto_ptr<Test>(new Test(*this));
}
std::auto_ptr<Test> Test::upcastCopy() {
    Test* np = new Test(*this);
    np->id = id;
    np->type = type;
    np->testName = testName;
    np->inDatabase = inDatabase;
    return auto_ptr<Test>(np);
}
std::ostream & operator<<(std::ostream& os, Test o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.testName.name() << " = " << o.testName << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType TestQuestion::Own::Id("id_",A_field_type_integer,"TestQuestion_");
TestQuestion::TestHandle::TestHandle(const TestQuestion& owner)
         : litesql::RelationHandle<TestQuestion>(owner) {
}
void TestQuestion::TestHandle::link(const Test& o0) {
    TestTestQuestionRelation::link(owner->getDatabase(), o0, *owner);
}
void TestQuestion::TestHandle::unlink(const Test& o0) {
    TestTestQuestionRelation::unlink(owner->getDatabase(), o0, *owner);
}
void TestQuestion::TestHandle::del(const litesql::Expr& expr) {
    TestTestQuestionRelation::del(owner->getDatabase(), expr && TestTestQuestionRelation::TestQuestion == owner->id);
}
litesql::DataSource<Test> TestQuestion::TestHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return TestTestQuestionRelation::get<Test>(owner->getDatabase(), expr, (TestTestQuestionRelation::TestQuestion == owner->id) && srcExpr);
}
litesql::DataSource<TestTestQuestionRelation::Row> TestQuestion::TestHandle::getRows(const litesql::Expr& expr) {
    return TestTestQuestionRelation::getRows(owner->getDatabase(), expr && (TestTestQuestionRelation::TestQuestion == owner->id));
}
TestQuestion::AnswersHandle::AnswersHandle(const TestQuestion& owner)
         : litesql::RelationHandle<TestQuestion>(owner) {
}
void TestQuestion::AnswersHandle::link(const TestAnswer& o0) {
    TestAnswerTestQuestionRelation::link(owner->getDatabase(), o0, *owner);
}
void TestQuestion::AnswersHandle::unlink(const TestAnswer& o0) {
    TestAnswerTestQuestionRelation::unlink(owner->getDatabase(), o0, *owner);
}
void TestQuestion::AnswersHandle::del(const litesql::Expr& expr) {
    TestAnswerTestQuestionRelation::del(owner->getDatabase(), expr && TestAnswerTestQuestionRelation::TestQuestion == owner->id);
}
litesql::DataSource<TestAnswer> TestQuestion::AnswersHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return TestAnswerTestQuestionRelation::get<TestAnswer>(owner->getDatabase(), expr, (TestAnswerTestQuestionRelation::TestQuestion == owner->id) && srcExpr);
}
litesql::DataSource<TestAnswerTestQuestionRelation::Row> TestQuestion::AnswersHandle::getRows(const litesql::Expr& expr) {
    return TestAnswerTestQuestionRelation::getRows(owner->getDatabase(), expr && (TestAnswerTestQuestionRelation::TestQuestion == owner->id));
}
const std::string TestQuestion::type__("TestQuestion");
const std::string TestQuestion::table__("TestQuestion_");
const std::string TestQuestion::sequence__("TestQuestion_seq");
const litesql::FieldType TestQuestion::Id("id_",A_field_type_integer,table__);
const litesql::FieldType TestQuestion::Type("type_",A_field_type_string,table__);
const litesql::FieldType TestQuestion::QuestionNum("questionNum_",A_field_type_integer,table__);
const litesql::FieldType TestQuestion::QuestionText("questionText_",A_field_type_string,table__);
const litesql::FieldType TestQuestion::QuestionPicture("questionPicture_",A_field_type_string,table__);
const litesql::FieldType TestQuestion::QuestionFormula("questionFormula_",A_field_type_string,table__);
void TestQuestion::defaults() {
    id = 0;
    questionNum = 0;
}
TestQuestion::TestQuestion(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), questionNum(QuestionNum), questionText(QuestionText), questionPicture(QuestionPicture), questionFormula(QuestionFormula) {
    defaults();
}
TestQuestion::TestQuestion(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), questionNum(QuestionNum), questionText(QuestionText), questionPicture(QuestionPicture), questionFormula(QuestionFormula) {
    defaults();
    size_t size = (rec.size() > 6) ? 6 : rec.size();
    switch(size) {
    case 6: questionFormula = convert<const std::string&, std::string>(rec[5]);
        questionFormula.setModified(false);
    case 5: questionPicture = convert<const std::string&, std::string>(rec[4]);
        questionPicture.setModified(false);
    case 4: questionText = convert<const std::string&, std::string>(rec[3]);
        questionText.setModified(false);
    case 3: questionNum = convert<const std::string&, int>(rec[2]);
        questionNum.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
TestQuestion::TestQuestion(const TestQuestion& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), questionNum(obj.questionNum), questionText(obj.questionText), questionPicture(obj.questionPicture), questionFormula(obj.questionFormula) {
}
const TestQuestion& TestQuestion::operator=(const TestQuestion& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        questionNum = obj.questionNum;
        questionText = obj.questionText;
        questionPicture = obj.questionPicture;
        questionFormula = obj.questionFormula;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
TestQuestion::TestHandle TestQuestion::test() {
    return TestQuestion::TestHandle(*this);
}
TestQuestion::AnswersHandle TestQuestion::answers() {
    return TestQuestion::AnswersHandle(*this);
}
std::string TestQuestion::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(questionNum.name());
    values.push_back(questionNum);
    questionNum.setModified(false);
    fields.push_back(questionText.name());
    values.push_back(questionText);
    questionText.setModified(false);
    fields.push_back(questionPicture.name());
    values.push_back(questionPicture);
    questionPicture.setModified(false);
    fields.push_back(questionFormula.name());
    values.push_back(questionFormula);
    questionFormula.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void TestQuestion::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void TestQuestion::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, questionNum);
    updateField(updates, table__, questionText);
    updateField(updates, table__, questionPicture);
    updateField(updates, table__, questionFormula);
}
void TestQuestion::addIDUpdates(Updates& updates) {
}
void TestQuestion::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(QuestionNum);
    ftypes.push_back(QuestionText);
    ftypes.push_back(QuestionPicture);
    ftypes.push_back(QuestionFormula);
}
void TestQuestion::delRecord() {
    deleteFromTable(table__, id);
}
void TestQuestion::delRelations() {
    TestTestQuestionRelation::del(*db, (TestTestQuestionRelation::TestQuestion == id));
    TestAnswerTestQuestionRelation::del(*db, (TestAnswerTestQuestionRelation::TestQuestion == id));
}
void TestQuestion::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect())
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void TestQuestion::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<TestQuestion> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool TestQuestion::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<TestQuestion> TestQuestion::upcast() {
    return auto_ptr<TestQuestion>(new TestQuestion(*this));
}
std::auto_ptr<TestQuestion> TestQuestion::upcastCopy() {
    TestQuestion* np = new TestQuestion(*this);
    np->id = id;
    np->type = type;
    np->questionNum = questionNum;
    np->questionText = questionText;
    np->questionPicture = questionPicture;
    np->questionFormula = questionFormula;
    np->inDatabase = inDatabase;
    return auto_ptr<TestQuestion>(np);
}
std::ostream & operator<<(std::ostream& os, TestQuestion o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.questionNum.name() << " = " << o.questionNum << std::endl;
    os << o.questionText.name() << " = " << o.questionText << std::endl;
    os << o.questionPicture.name() << " = " << o.questionPicture << std::endl;
    os << o.questionFormula.name() << " = " << o.questionFormula << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType TestAnswer::Own::Id("id_",A_field_type_integer,"TestAnswer_");
TestAnswer::QuestionHandle::QuestionHandle(const TestAnswer& owner)
         : litesql::RelationHandle<TestAnswer>(owner) {
}
void TestAnswer::QuestionHandle::link(const TestQuestion& o0) {
    TestAnswerTestQuestionRelation::link(owner->getDatabase(), *owner, o0);
}
void TestAnswer::QuestionHandle::unlink(const TestQuestion& o0) {
    TestAnswerTestQuestionRelation::unlink(owner->getDatabase(), *owner, o0);
}
void TestAnswer::QuestionHandle::del(const litesql::Expr& expr) {
    TestAnswerTestQuestionRelation::del(owner->getDatabase(), expr && TestAnswerTestQuestionRelation::TestAnswer == owner->id);
}
litesql::DataSource<TestQuestion> TestAnswer::QuestionHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return TestAnswerTestQuestionRelation::get<TestQuestion>(owner->getDatabase(), expr, (TestAnswerTestQuestionRelation::TestAnswer == owner->id) && srcExpr);
}
litesql::DataSource<TestAnswerTestQuestionRelation::Row> TestAnswer::QuestionHandle::getRows(const litesql::Expr& expr) {
    return TestAnswerTestQuestionRelation::getRows(owner->getDatabase(), expr && (TestAnswerTestQuestionRelation::TestAnswer == owner->id));
}
const std::string TestAnswer::type__("TestAnswer");
const std::string TestAnswer::table__("TestAnswer_");
const std::string TestAnswer::sequence__("TestAnswer_seq");
const litesql::FieldType TestAnswer::Id("id_",A_field_type_integer,table__);
const litesql::FieldType TestAnswer::Type("type_",A_field_type_string,table__);
const litesql::FieldType TestAnswer::AnswerNum("answerNum_",A_field_type_integer,table__);
const litesql::FieldType TestAnswer::AnswerText("answerText_",A_field_type_string,table__);
const litesql::FieldType TestAnswer::AnswerPicture("answerPicture_",A_field_type_string,table__);
const litesql::FieldType TestAnswer::AnswerFormula("answerFormula_",A_field_type_string,table__);
const litesql::FieldType TestAnswer::IsRight("isRight_",A_field_type_boolean,table__);
void TestAnswer::defaults() {
    id = 0;
    answerNum = 0;
    isRight = 0;
}
TestAnswer::TestAnswer(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), answerNum(AnswerNum), answerText(AnswerText), answerPicture(AnswerPicture), answerFormula(AnswerFormula), isRight(IsRight) {
    defaults();
}
TestAnswer::TestAnswer(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), answerNum(AnswerNum), answerText(AnswerText), answerPicture(AnswerPicture), answerFormula(AnswerFormula), isRight(IsRight) {
    defaults();
    size_t size = (rec.size() > 7) ? 7 : rec.size();
    switch(size) {
    case 7: isRight = convert<const std::string&, bool>(rec[6]);
        isRight.setModified(false);
    case 6: answerFormula = convert<const std::string&, std::string>(rec[5]);
        answerFormula.setModified(false);
    case 5: answerPicture = convert<const std::string&, std::string>(rec[4]);
        answerPicture.setModified(false);
    case 4: answerText = convert<const std::string&, std::string>(rec[3]);
        answerText.setModified(false);
    case 3: answerNum = convert<const std::string&, int>(rec[2]);
        answerNum.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
TestAnswer::TestAnswer(const TestAnswer& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), answerNum(obj.answerNum), answerText(obj.answerText), answerPicture(obj.answerPicture), answerFormula(obj.answerFormula), isRight(obj.isRight) {
}
const TestAnswer& TestAnswer::operator=(const TestAnswer& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        answerNum = obj.answerNum;
        answerText = obj.answerText;
        answerPicture = obj.answerPicture;
        answerFormula = obj.answerFormula;
        isRight = obj.isRight;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
TestAnswer::QuestionHandle TestAnswer::question() {
    return TestAnswer::QuestionHandle(*this);
}
std::string TestAnswer::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(answerNum.name());
    values.push_back(answerNum);
    answerNum.setModified(false);
    fields.push_back(answerText.name());
    values.push_back(answerText);
    answerText.setModified(false);
    fields.push_back(answerPicture.name());
    values.push_back(answerPicture);
    answerPicture.setModified(false);
    fields.push_back(answerFormula.name());
    values.push_back(answerFormula);
    answerFormula.setModified(false);
    fields.push_back(isRight.name());
    values.push_back(isRight);
    isRight.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void TestAnswer::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void TestAnswer::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, answerNum);
    updateField(updates, table__, answerText);
    updateField(updates, table__, answerPicture);
    updateField(updates, table__, answerFormula);
    updateField(updates, table__, isRight);
}
void TestAnswer::addIDUpdates(Updates& updates) {
}
void TestAnswer::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(AnswerNum);
    ftypes.push_back(AnswerText);
    ftypes.push_back(AnswerPicture);
    ftypes.push_back(AnswerFormula);
    ftypes.push_back(IsRight);
}
void TestAnswer::delRecord() {
    deleteFromTable(table__, id);
}
void TestAnswer::delRelations() {
    TestAnswerTestQuestionRelation::del(*db, (TestAnswerTestQuestionRelation::TestAnswer == id));
}
void TestAnswer::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect())
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void TestAnswer::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<TestAnswer> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool TestAnswer::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<TestAnswer> TestAnswer::upcast() {
    return auto_ptr<TestAnswer>(new TestAnswer(*this));
}
std::auto_ptr<TestAnswer> TestAnswer::upcastCopy() {
    TestAnswer* np = new TestAnswer(*this);
    np->id = id;
    np->type = type;
    np->answerNum = answerNum;
    np->answerText = answerText;
    np->answerPicture = answerPicture;
    np->answerFormula = answerFormula;
    np->isRight = isRight;
    np->inDatabase = inDatabase;
    return auto_ptr<TestAnswer>(np);
}
std::ostream & operator<<(std::ostream& os, TestAnswer o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.answerNum.name() << " = " << o.answerNum << std::endl;
    os << o.answerText.name() << " = " << o.answerText << std::endl;
    os << o.answerPicture.name() << " = " << o.answerPicture << std::endl;
    os << o.answerFormula.name() << " = " << o.answerFormula << std::endl;
    os << o.isRight.name() << " = " << o.isRight << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType Student::Own::Id("id_",A_field_type_integer,"Student_");
Student::TestHandle::TestHandle(const Student& owner)
         : litesql::RelationHandle<Student>(owner) {
}
void Student::TestHandle::link(const Test& o0) {
    StudentTestRelation::link(owner->getDatabase(), *owner, o0);
}
void Student::TestHandle::unlink(const Test& o0) {
    StudentTestRelation::unlink(owner->getDatabase(), *owner, o0);
}
void Student::TestHandle::del(const litesql::Expr& expr) {
    StudentTestRelation::del(owner->getDatabase(), expr && StudentTestRelation::Student == owner->id);
}
litesql::DataSource<Test> Student::TestHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentTestRelation::get<Test>(owner->getDatabase(), expr, (StudentTestRelation::Student == owner->id) && srcExpr);
}
litesql::DataSource<StudentTestRelation::Row> Student::TestHandle::getRows(const litesql::Expr& expr) {
    return StudentTestRelation::getRows(owner->getDatabase(), expr && (StudentTestRelation::Student == owner->id));
}
Student::AnswersHandle::AnswersHandle(const Student& owner)
         : litesql::RelationHandle<Student>(owner) {
}
void Student::AnswersHandle::link(const StudentAnswer& o0) {
    StudentStudentAnswerRelation::link(owner->getDatabase(), *owner, o0);
}
void Student::AnswersHandle::unlink(const StudentAnswer& o0) {
    StudentStudentAnswerRelation::unlink(owner->getDatabase(), *owner, o0);
}
void Student::AnswersHandle::del(const litesql::Expr& expr) {
    StudentStudentAnswerRelation::del(owner->getDatabase(), expr && StudentStudentAnswerRelation::Student == owner->id);
}
litesql::DataSource<StudentAnswer> Student::AnswersHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentStudentAnswerRelation::get<StudentAnswer>(owner->getDatabase(), expr, (StudentStudentAnswerRelation::Student == owner->id) && srcExpr);
}
litesql::DataSource<StudentStudentAnswerRelation::Row> Student::AnswersHandle::getRows(const litesql::Expr& expr) {
    return StudentStudentAnswerRelation::getRows(owner->getDatabase(), expr && (StudentStudentAnswerRelation::Student == owner->id));
}
Student::CustomAnswerHandle::CustomAnswerHandle(const Student& owner)
         : litesql::RelationHandle<Student>(owner) {
}
void Student::CustomAnswerHandle::link(const StudentCustomAnswer& o0) {
    StudentStudentCustomAnswerRelation::link(owner->getDatabase(), *owner, o0);
}
void Student::CustomAnswerHandle::unlink(const StudentCustomAnswer& o0) {
    StudentStudentCustomAnswerRelation::unlink(owner->getDatabase(), *owner, o0);
}
void Student::CustomAnswerHandle::del(const litesql::Expr& expr) {
    StudentStudentCustomAnswerRelation::del(owner->getDatabase(), expr && StudentStudentCustomAnswerRelation::Student == owner->id);
}
litesql::DataSource<StudentCustomAnswer> Student::CustomAnswerHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentStudentCustomAnswerRelation::get<StudentCustomAnswer>(owner->getDatabase(), expr, (StudentStudentCustomAnswerRelation::Student == owner->id) && srcExpr);
}
litesql::DataSource<StudentStudentCustomAnswerRelation::Row> Student::CustomAnswerHandle::getRows(const litesql::Expr& expr) {
    return StudentStudentCustomAnswerRelation::getRows(owner->getDatabase(), expr && (StudentStudentCustomAnswerRelation::Student == owner->id));
}
const std::string Student::type__("Student");
const std::string Student::table__("Student_");
const std::string Student::sequence__("Student_seq");
const litesql::FieldType Student::Id("id_",A_field_type_integer,table__);
const litesql::FieldType Student::Type("type_",A_field_type_string,table__);
const litesql::FieldType Student::GroupNum("groupNum_",A_field_type_integer,table__);
const litesql::FieldType Student::Surname("surname_",A_field_type_string,table__);
const litesql::FieldType Student::NumClasses("numClasses_",A_field_type_integer,table__);
const litesql::FieldType Student::VisitedClasses("visitedClasses_",A_field_type_integer,table__);
const litesql::FieldType Student::Bonuses("bonuses_",A_field_type_integer,table__);
const litesql::FieldType Student::Presentation("presentation_",A_field_type_integer,table__);
void Student::defaults() {
    id = 0;
    groupNum = 0;
}
Student::Student(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), groupNum(GroupNum), surname(Surname),numClasses(NumClasses), visitedClasses(VisitedClasses),bonuses(Bonuses), presentation(Presentation) {
    defaults();
}
Student::Student(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), groupNum(GroupNum), surname(Surname),numClasses(NumClasses), visitedClasses(VisitedClasses),bonuses(Bonuses), presentation(Presentation) {
    defaults();
    size_t size = (rec.size() > 8) ? 8 : rec.size();
    switch(size) {
    case 8: presentation = convert<const std::string&, int>(rec[7]);
        presentation.setModified(false);
    case 7: bonuses = convert<const std::string&, int>(rec[6]);
        bonuses.setModified(false);
    case 6: visitedClasses = convert<const std::string&, int>(rec[5]);
        visitedClasses.setModified(false);
    case 5: numClasses = convert<const std::string&, int>(rec[4]);
        numClasses.setModified(false);
    case 4: surname = convert<const std::string&, std::string>(rec[3]);
        surname.setModified(false);
    case 3: groupNum = convert<const std::string&, int>(rec[2]);
        groupNum.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
Student::Student(const Student& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), groupNum(obj.groupNum), surname(obj.surname),numClasses(obj.numClasses), visitedClasses(obj.visitedClasses),bonuses(obj.bonuses), presentation(obj.presentation) {
}
const Student& Student::operator=(const Student& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        groupNum = obj.groupNum;
        surname = obj.surname;
        numClasses = obj.numClasses;
        visitedClasses = obj.visitedClasses;
        bonuses = obj.bonuses;
        presentation = obj.presentation;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
Student::TestHandle Student::test() {
    return Student::TestHandle(*this);
}
Student::AnswersHandle Student::answers() {
    return Student::AnswersHandle(*this);
}
Student::CustomAnswerHandle Student::customAnswer() {
    return Student::CustomAnswerHandle(*this);
}
std::string Student::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(groupNum.name());
    values.push_back(groupNum);
    groupNum.setModified(false);
    fields.push_back(surname.name());
    values.push_back(surname);
    surname.setModified(false);

    fields.push_back(numClasses.name());
    values.push_back(numClasses);
    numClasses.setModified(false);
    fields.push_back(visitedClasses.name());
    values.push_back(visitedClasses);
    visitedClasses.setModified(false);
    fields.push_back(bonuses.name());
    values.push_back(bonuses);
    bonuses.setModified(false);
    fields.push_back(presentation.name());
    values.push_back(presentation);
    presentation.setModified(false);

    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void Student::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Student::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, groupNum);
    updateField(updates, table__, surname);
    updateField(updates, table__, numClasses);
    updateField(updates, table__, visitedClasses);
    updateField(updates, table__, bonuses);
    updateField(updates, table__, presentation);
}
void Student::addIDUpdates(Updates& updates) {
}
void Student::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(GroupNum);
    ftypes.push_back(Surname);
    ftypes.push_back(NumClasses);
    ftypes.push_back(VisitedClasses);
    ftypes.push_back(Bonuses);
    ftypes.push_back(Presentation);
}
void Student::delRecord() {
    deleteFromTable(table__, id);
}
void Student::delRelations() {
    StudentTestRelation::del(*db, (StudentTestRelation::Student == id));
    StudentStudentAnswerRelation::del(*db, (StudentStudentAnswerRelation::Student == id));
    StudentStudentCustomAnswerRelation::del(*db, (StudentStudentCustomAnswerRelation::Student == id));
}
void Student::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect())
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void Student::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<Student> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool Student::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<Student> Student::upcast() {
    return auto_ptr<Student>(new Student(*this));
}
std::auto_ptr<Student> Student::upcastCopy() {
    Student* np = new Student(*this);
    np->id = id;
    np->type = type;
    np->groupNum = groupNum;
    np->surname = surname;
    np->numClasses = numClasses;
    np->visitedClasses = visitedClasses;
    np->bonuses = bonuses;
    np->presentation = presentation;
    np->inDatabase = inDatabase;
    return auto_ptr<Student>(np);
}
std::ostream & operator<<(std::ostream& os, Student o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.groupNum.name() << " = " << o.groupNum << std::endl;
    os << o.surname.name() << " = " << o.surname << std::endl;
    os << o.numClasses.name() << " = " << o.numClasses << std::endl;
    os << o.visitedClasses.name() << " = " << o.visitedClasses << std::endl;
    os << o.bonuses.name() << " = " << o.bonuses << std::endl;
    os << o.presentation.name() << " = " << o.presentation << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType StudentAnswer::Own::Id("id_",A_field_type_integer,"StudentAnswer_");
StudentAnswer::TestHandle::TestHandle(const StudentAnswer& owner)
         : litesql::RelationHandle<StudentAnswer>(owner) {
}
void StudentAnswer::TestHandle::link(const Test& o0) {
    StudentAnswerTestRelation::link(owner->getDatabase(), *owner, o0);
}
void StudentAnswer::TestHandle::unlink(const Test& o0) {
    StudentAnswerTestRelation::unlink(owner->getDatabase(), *owner, o0);
}
void StudentAnswer::TestHandle::del(const litesql::Expr& expr) {
    StudentAnswerTestRelation::del(owner->getDatabase(), expr && StudentAnswerTestRelation::StudentAnswer == owner->id);
}
litesql::DataSource<Test> StudentAnswer::TestHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentAnswerTestRelation::get<Test>(owner->getDatabase(), expr, (StudentAnswerTestRelation::StudentAnswer == owner->id) && srcExpr);
}
litesql::DataSource<StudentAnswerTestRelation::Row> StudentAnswer::TestHandle::getRows(const litesql::Expr& expr) {
    return StudentAnswerTestRelation::getRows(owner->getDatabase(), expr && (StudentAnswerTestRelation::StudentAnswer == owner->id));
}
StudentAnswer::StudentHandle::StudentHandle(const StudentAnswer& owner)
         : litesql::RelationHandle<StudentAnswer>(owner) {
}
void StudentAnswer::StudentHandle::link(const Student& o0) {
    StudentStudentAnswerRelation::link(owner->getDatabase(), o0, *owner);
}
void StudentAnswer::StudentHandle::unlink(const Student& o0) {
    StudentStudentAnswerRelation::unlink(owner->getDatabase(), o0, *owner);
}
void StudentAnswer::StudentHandle::del(const litesql::Expr& expr) {
    StudentStudentAnswerRelation::del(owner->getDatabase(), expr && StudentStudentAnswerRelation::StudentAnswer == owner->id);
}
litesql::DataSource<Student> StudentAnswer::StudentHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentStudentAnswerRelation::get<Student>(owner->getDatabase(), expr, (StudentStudentAnswerRelation::StudentAnswer == owner->id) && srcExpr);
}
litesql::DataSource<StudentStudentAnswerRelation::Row> StudentAnswer::StudentHandle::getRows(const litesql::Expr& expr) {
    return StudentStudentAnswerRelation::getRows(owner->getDatabase(), expr && (StudentStudentAnswerRelation::StudentAnswer == owner->id));
}
const std::string StudentAnswer::type__("StudentAnswer");
const std::string StudentAnswer::table__("StudentAnswer_");
const std::string StudentAnswer::sequence__("StudentAnswer_seq");
const litesql::FieldType StudentAnswer::Id("id_",A_field_type_integer,table__);
const litesql::FieldType StudentAnswer::Type("type_",A_field_type_string,table__);
const litesql::FieldType StudentAnswer::QuestionNum("questionNum_",A_field_type_integer,table__);
const litesql::FieldType StudentAnswer::AnswerNum("answerNum_",A_field_type_integer,table__);
const litesql::FieldType StudentAnswer::Selected("selected_",A_field_type_boolean,table__);
void StudentAnswer::defaults() {
    id = 0;
    questionNum = 0;
    answerNum = 0;
    selected = 0;
}
StudentAnswer::StudentAnswer(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), questionNum(QuestionNum), answerNum(AnswerNum), selected(Selected) {
    defaults();
}
StudentAnswer::StudentAnswer(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), questionNum(QuestionNum), answerNum(AnswerNum), selected(Selected) {
    defaults();
    size_t size = (rec.size() > 5) ? 5 : rec.size();
    switch(size) {
    case 5: selected = convert<const std::string&, bool>(rec[4]);
        selected.setModified(false);
    case 4: answerNum = convert<const std::string&, int>(rec[3]);
        answerNum.setModified(false);
    case 3: questionNum = convert<const std::string&, int>(rec[2]);
        questionNum.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
StudentAnswer::StudentAnswer(const StudentAnswer& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), questionNum(obj.questionNum), answerNum(obj.answerNum), selected(obj.selected) {
}
const StudentAnswer& StudentAnswer::operator=(const StudentAnswer& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        questionNum = obj.questionNum;
        answerNum = obj.answerNum;
        selected = obj.selected;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
StudentAnswer::TestHandle StudentAnswer::test() {
    return StudentAnswer::TestHandle(*this);
}
StudentAnswer::StudentHandle StudentAnswer::student() {
    return StudentAnswer::StudentHandle(*this);
}
std::string StudentAnswer::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(questionNum.name());
    values.push_back(questionNum);
    questionNum.setModified(false);
    fields.push_back(answerNum.name());
    values.push_back(answerNum);
    answerNum.setModified(false);
    fields.push_back(selected.name());
    values.push_back(selected);
    selected.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void StudentAnswer::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void StudentAnswer::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, questionNum);
    updateField(updates, table__, answerNum);
    updateField(updates, table__, selected);
}
void StudentAnswer::addIDUpdates(Updates& updates) {
}
void StudentAnswer::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(QuestionNum);
    ftypes.push_back(AnswerNum);
    ftypes.push_back(Selected);
}
void StudentAnswer::delRecord() {
    deleteFromTable(table__, id);
}
void StudentAnswer::delRelations() {
    StudentAnswerTestRelation::del(*db, (StudentAnswerTestRelation::StudentAnswer == id));
    StudentStudentAnswerRelation::del(*db, (StudentStudentAnswerRelation::StudentAnswer == id));
}
void StudentAnswer::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect())
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void StudentAnswer::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<StudentAnswer> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool StudentAnswer::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<StudentAnswer> StudentAnswer::upcast() {
    return auto_ptr<StudentAnswer>(new StudentAnswer(*this));
}
std::auto_ptr<StudentAnswer> StudentAnswer::upcastCopy() {
    StudentAnswer* np = new StudentAnswer(*this);
    np->id = id;
    np->type = type;
    np->questionNum = questionNum;
    np->answerNum = answerNum;
    np->selected = selected;
    np->inDatabase = inDatabase;
    return auto_ptr<StudentAnswer>(np);
}
std::ostream & operator<<(std::ostream& os, StudentAnswer o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.questionNum.name() << " = " << o.questionNum << std::endl;
    os << o.answerNum.name() << " = " << o.answerNum << std::endl;
    os << o.selected.name() << " = " << o.selected << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType StudentCustomAnswer::Own::Id("id_",A_field_type_integer,"StudentCustomAnswer_");
StudentCustomAnswer::TestHandle::TestHandle(const StudentCustomAnswer& owner)
         : litesql::RelationHandle<StudentCustomAnswer>(owner) {
}
void StudentCustomAnswer::TestHandle::link(const Test& o0) {
    StudentCustomAnswerTestRelation::link(owner->getDatabase(), *owner, o0);
}
void StudentCustomAnswer::TestHandle::unlink(const Test& o0) {
    StudentCustomAnswerTestRelation::unlink(owner->getDatabase(), *owner, o0);
}
void StudentCustomAnswer::TestHandle::del(const litesql::Expr& expr) {
    StudentCustomAnswerTestRelation::del(owner->getDatabase(), expr && StudentCustomAnswerTestRelation::StudentCustomAnswer == owner->id);
}
litesql::DataSource<Test> StudentCustomAnswer::TestHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentCustomAnswerTestRelation::get<Test>(owner->getDatabase(), expr, (StudentCustomAnswerTestRelation::StudentCustomAnswer == owner->id) && srcExpr);
}
litesql::DataSource<StudentCustomAnswerTestRelation::Row> StudentCustomAnswer::TestHandle::getRows(const litesql::Expr& expr) {
    return StudentCustomAnswerTestRelation::getRows(owner->getDatabase(), expr && (StudentCustomAnswerTestRelation::StudentCustomAnswer == owner->id));
}
StudentCustomAnswer::StudentHandle::StudentHandle(const StudentCustomAnswer& owner)
         : litesql::RelationHandle<StudentCustomAnswer>(owner) {
}
void StudentCustomAnswer::StudentHandle::link(const Student& o0) {
    StudentStudentCustomAnswerRelation::link(owner->getDatabase(), o0, *owner);
}
void StudentCustomAnswer::StudentHandle::unlink(const Student& o0) {
    StudentStudentCustomAnswerRelation::unlink(owner->getDatabase(), o0, *owner);
}
void StudentCustomAnswer::StudentHandle::del(const litesql::Expr& expr) {
    StudentStudentCustomAnswerRelation::del(owner->getDatabase(), expr && StudentStudentCustomAnswerRelation::StudentCustomAnswer == owner->id);
}
litesql::DataSource<Student> StudentCustomAnswer::StudentHandle::get(const litesql::Expr& expr, const litesql::Expr& srcExpr) {
    return StudentStudentCustomAnswerRelation::get<Student>(owner->getDatabase(), expr, (StudentStudentCustomAnswerRelation::StudentCustomAnswer == owner->id) && srcExpr);
}
litesql::DataSource<StudentStudentCustomAnswerRelation::Row> StudentCustomAnswer::StudentHandle::getRows(const litesql::Expr& expr) {
    return StudentStudentCustomAnswerRelation::getRows(owner->getDatabase(), expr && (StudentStudentCustomAnswerRelation::StudentCustomAnswer == owner->id));
}
const std::string StudentCustomAnswer::type__("StudentCustomAnswer");
const std::string StudentCustomAnswer::table__("StudentCustomAnswer_");
const std::string StudentCustomAnswer::sequence__("StudentCustomAnswer_seq");
const litesql::FieldType StudentCustomAnswer::Id("id_",A_field_type_integer,table__);
const litesql::FieldType StudentCustomAnswer::Type("type_",A_field_type_string,table__);
const litesql::FieldType StudentCustomAnswer::QuestionNum("questionNum_",A_field_type_integer,table__);
const litesql::FieldType StudentCustomAnswer::CustomAnswer("customAnswer_",A_field_type_string,table__);
const litesql::FieldType StudentCustomAnswer::Score("score",A_field_type_integer,table__);
void StudentCustomAnswer::defaults() {
    id = 0;
    questionNum = 0;
    score = 0;
}
StudentCustomAnswer::StudentCustomAnswer(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), questionNum(QuestionNum), customAnswer(CustomAnswer), score(Score)  {
    defaults();
}
StudentCustomAnswer::StudentCustomAnswer(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), questionNum(QuestionNum), customAnswer(CustomAnswer), score(Score) {
    defaults();
    size_t size = (rec.size() > 5) ? 5 : rec.size();
    switch(size) {
    case 5: score = convert<const std::string&, int>(rec[4]);
        score.setModified(false);
    case 4: customAnswer = convert<const std::string&, std::string>(rec[3]);
        customAnswer.setModified(false);
    case 3: questionNum = convert<const std::string&, int>(rec[2]);
        questionNum.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
StudentCustomAnswer::StudentCustomAnswer(const StudentCustomAnswer& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), questionNum(obj.questionNum), customAnswer(obj.customAnswer), score(obj.score) {
}
const StudentCustomAnswer& StudentCustomAnswer::operator=(const StudentCustomAnswer& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        questionNum = obj.questionNum;
        customAnswer = obj.customAnswer;
        score = obj.score;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
StudentCustomAnswer::TestHandle StudentCustomAnswer::test() {
    return StudentCustomAnswer::TestHandle(*this);
}
StudentCustomAnswer::StudentHandle StudentCustomAnswer::student() {
    return StudentCustomAnswer::StudentHandle(*this);
}
std::string StudentCustomAnswer::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(questionNum.name());
    values.push_back(questionNum);
    questionNum.setModified(false);
    fields.push_back(customAnswer.name());
    values.push_back(customAnswer);
    customAnswer.setModified(false);
    fields.push_back(score.name());
    values.push_back(score);
    score.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void StudentCustomAnswer::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void StudentCustomAnswer::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, questionNum);
    updateField(updates, table__, customAnswer);
    updateField(updates, table__, score);
}
void StudentCustomAnswer::addIDUpdates(Updates& updates) {
}
void StudentCustomAnswer::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(QuestionNum);
    ftypes.push_back(CustomAnswer);
    ftypes.push_back(Score);
}
void StudentCustomAnswer::delRecord() {
    deleteFromTable(table__, id);
}
void StudentCustomAnswer::delRelations() {
    StudentCustomAnswerTestRelation::del(*db, (StudentCustomAnswerTestRelation::StudentCustomAnswer == id));
    StudentStudentCustomAnswerRelation::del(*db, (StudentStudentCustomAnswerRelation::StudentCustomAnswer == id));
}
void StudentCustomAnswer::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect())
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void StudentCustomAnswer::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<StudentCustomAnswer> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool StudentCustomAnswer::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<StudentCustomAnswer> StudentCustomAnswer::upcast() {
    return auto_ptr<StudentCustomAnswer>(new StudentCustomAnswer(*this));
}
std::auto_ptr<StudentCustomAnswer> StudentCustomAnswer::upcastCopy() {
    StudentCustomAnswer* np = new StudentCustomAnswer(*this);
    np->id = id;
    np->type = type;
    np->questionNum = questionNum;
    np->customAnswer = customAnswer;
    np->score = score;
    np->inDatabase = inDatabase;
    return auto_ptr<StudentCustomAnswer>(np);
}
std::ostream & operator<<(std::ostream& os, StudentCustomAnswer o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.questionNum.name() << " = " << o.questionNum << std::endl;
    os << o.customAnswer.name() << " = " << o.customAnswer << std::endl;
    os << o.score.name() << " = " << o.score << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
TestSuiteDB::TestSuiteDB(std::string backendType, std::string connInfo)
     : litesql::Database(backendType, connInfo) {
    initialize();
}
std::vector<litesql::Database::SchemaItem> TestSuiteDB::getSchema() const {
    vector<Database::SchemaItem> res;
    string TEXT = backend->getSQLType(A_field_type_string);
    string rowIdType = backend->getRowIDType();
    res.push_back(Database::SchemaItem("schema_","table","CREATE TABLE schema_ (name_ "+TEXT+", type_ "+TEXT+", sql_ "+TEXT+")"));
    if (backend->supportsSequences()) {
        res.push_back(Database::SchemaItem("Test_seq","sequence",backend->getCreateSequenceSQL("Test_seq")));
        res.push_back(Database::SchemaItem("TestQuestion_seq","sequence",backend->getCreateSequenceSQL("TestQuestion_seq")));
        res.push_back(Database::SchemaItem("TestAnswer_seq","sequence",backend->getCreateSequenceSQL("TestAnswer_seq")));
        res.push_back(Database::SchemaItem("Student_seq","sequence",backend->getCreateSequenceSQL("Student_seq")));
        res.push_back(Database::SchemaItem("StudentAnswer_seq","sequence",backend->getCreateSequenceSQL("StudentAnswer_seq")));
        res.push_back(Database::SchemaItem("StudentCustomAnswer_seq","sequence",backend->getCreateSequenceSQL("StudentCustomAnswer_seq")));
    }
    res.push_back(Database::SchemaItem("Test_","table","CREATE TABLE Test_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",testName_ " + backend->getSQLType(A_field_type_string,"") + " UNIQUE" +")"));
    res.push_back(Database::SchemaItem("TestQuestion_","table","CREATE TABLE TestQuestion_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",questionNum_ " + backend->getSQLType(A_field_type_integer,"") + "" +",questionText_ " + backend->getSQLType(A_field_type_string,"") + "" +",questionPicture_ " + backend->getSQLType(A_field_type_string,"") + "" +",questionFormula_ " + backend->getSQLType(A_field_type_string,"") + "" +")"));
    res.push_back(Database::SchemaItem("TestAnswer_","table","CREATE TABLE TestAnswer_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",answerNum_ " + backend->getSQLType(A_field_type_integer,"") + "" +",answerText_ " + backend->getSQLType(A_field_type_string,"") + "" +",answerPicture_ " + backend->getSQLType(A_field_type_string,"") + "" +",answerFormula_ " + backend->getSQLType(A_field_type_string,"") + "" +",isRight_ " + backend->getSQLType(A_field_type_boolean,"") + "" +")"));
    res.push_back(Database::SchemaItem("Student_","table","CREATE TABLE Student_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + ""
                                       +",groupNum_ " + backend->getSQLType(A_field_type_integer,"") + ""
                                       +",surname_ " + backend->getSQLType(A_field_type_string,"")+ ""
                                       +",numClasses_ " + backend->getSQLType(A_field_type_integer,"") + ""
                                       +",visitedClasses_ " + backend->getSQLType(A_field_type_integer,"") + ""
                                       +",bonuses_ " + backend->getSQLType(A_field_type_integer,"") + ""
                                       +",presentation_ " + backend->getSQLType(A_field_type_integer,"") + ""
                                       +")"));
    res.push_back(Database::SchemaItem("StudentAnswer_","table","CREATE TABLE StudentAnswer_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",questionNum_ " + backend->getSQLType(A_field_type_integer,"") + "" +",answerNum_ " + backend->getSQLType(A_field_type_integer,"") + "" +",selected_ " + backend->getSQLType(A_field_type_boolean,"") + "" +")"));
    res.push_back(Database::SchemaItem("StudentCustomAnswer_","table","CREATE TABLE StudentCustomAnswer_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",questionNum_ " + backend->getSQLType(A_field_type_integer,"") + "" +",customAnswer_ " + backend->getSQLType(A_field_type_string,"")+ "" + ",score " + backend->getSQLType(A_field_type_integer,"") + "" +")"));
    res.push_back(Database::SchemaItem("Test_TestQuestion_","table","CREATE TABLE Test_TestQuestion_ (Test1_ " + backend->getSQLType(A_field_type_integer,"") + "" +",TestQuestion2_ " + backend->getSQLType(A_field_type_integer,"") + " UNIQUE" +")"));
    res.push_back(Database::SchemaItem("Student_Test_","table","CREATE TABLE Student_Test_ (Student1_ " + backend->getSQLType(A_field_type_integer,"") + "" +",Test2_ " + backend->getSQLType(A_field_type_integer,"") + "" +")"));
    res.push_back(Database::SchemaItem("StudentAnswer_Test_","table","CREATE TABLE StudentAnswer_Test_ (StudentAnswer1_ " + backend->getSQLType(A_field_type_integer,"") + " UNIQUE" +",Test2_ " + backend->getSQLType(A_field_type_integer,"") + "" +")"));
    res.push_back(Database::SchemaItem("StudentCustomAnswer_Test_","table","CREATE TABLE StudentCustomAnswer_Test_ (StudentCustomAnswer1_ " + backend->getSQLType(A_field_type_integer,"") + " UNIQUE" +",Test2_ " + backend->getSQLType(A_field_type_integer,"") + "" +")"));
    res.push_back(Database::SchemaItem("TestAnswer_TestQuestion_","table","CREATE TABLE TestAnswer_TestQuestion_ (TestAnswer1_ " + backend->getSQLType(A_field_type_integer,"") + " UNIQUE" +",TestQuestion2_ " + backend->getSQLType(A_field_type_integer,"") + "" +")"));
    res.push_back(Database::SchemaItem("Student_StudentAnswer_","table","CREATE TABLE Student_StudentAnswer_ (Student1_ " + backend->getSQLType(A_field_type_integer,"") + "" +",StudentAnswer2_ " + backend->getSQLType(A_field_type_integer,"") + " UNIQUE" +")"));
    res.push_back(Database::SchemaItem("Student_StudentCustomAnswer_","table","CREATE TABLE Student_StudentCustomAnswer_ (Student1_ " + backend->getSQLType(A_field_type_integer,"") + "" +",StudentCustomAnswer2_ " + backend->getSQLType(A_field_type_integer,"") + " UNIQUE" +")"));
    res.push_back(Database::SchemaItem("Test_id_idx","index","CREATE INDEX Test_id_idx ON Test_ (id_)"));
    res.push_back(Database::SchemaItem("TestQuestion_id_idx","index","CREATE INDEX TestQuestion_id_idx ON TestQuestion_ (id_)"));
    res.push_back(Database::SchemaItem("TestAnswer_id_idx","index","CREATE INDEX TestAnswer_id_idx ON TestAnswer_ (id_)"));
    res.push_back(Database::SchemaItem("Student_id_idx","index","CREATE INDEX Student_id_idx ON Student_ (id_)"));
    res.push_back(Database::SchemaItem("StudentAnswer_id_idx","index","CREATE INDEX StudentAnswer_id_idx ON StudentAnswer_ (id_)"));
    res.push_back(Database::SchemaItem("StudentCustomAnswer_id_idx","index","CREATE INDEX StudentCustomAnswer_id_idx ON StudentCustomAnswer_ (id_)"));
    res.push_back(Database::SchemaItem("Test_TestQuestion_Test1_idx","index","CREATE INDEX Test_TestQuestion_Test1_idx ON Test_TestQuestion_ (Test1_)"));
    res.push_back(Database::SchemaItem("O6068e032d606f8f103f9bceb161e8","index","CREATE INDEX O6068e032d606f8f103f9bceb161e8 ON Test_TestQuestion_ (TestQuestion2_)"));
    res.push_back(Database::SchemaItem("Test_TestQuestion__all_idx","index","CREATE INDEX Test_TestQuestion__all_idx ON Test_TestQuestion_ (Test1_,TestQuestion2_)"));
    res.push_back(Database::SchemaItem("Student_Test_Student1_idx","index","CREATE INDEX Student_Test_Student1_idx ON Student_Test_ (Student1_)"));
    res.push_back(Database::SchemaItem("Student_Test_Test2_idx","index","CREATE INDEX Student_Test_Test2_idx ON Student_Test_ (Test2_)"));
    res.push_back(Database::SchemaItem("Student_Test__all_idx","index","CREATE INDEX Student_Test__all_idx ON Student_Test_ (Student1_,Test2_)"));
    res.push_back(Database::SchemaItem("O2b8207d277aa79d27665ecdccaefd","index","CREATE INDEX O2b8207d277aa79d27665ecdccaefd ON StudentAnswer_Test_ (StudentAnswer1_)"));
    res.push_back(Database::SchemaItem("StudentAnswer_Test_Test2_idx","index","CREATE INDEX StudentAnswer_Test_Test2_idx ON StudentAnswer_Test_ (Test2_)"));
    res.push_back(Database::SchemaItem("StudentAnswer_Test__all_idx","index","CREATE INDEX StudentAnswer_Test__all_idx ON StudentAnswer_Test_ (StudentAnswer1_,Test2_)"));
    res.push_back(Database::SchemaItem("O92075f79ef8be8e5f133e14f91734","index","CREATE INDEX O92075f79ef8be8e5f133e14f91734 ON StudentCustomAnswer_Test_ (StudentCustomAnswer1_)"));
    res.push_back(Database::SchemaItem("O23fd091ba452875e289578dd046b2","index","CREATE INDEX O23fd091ba452875e289578dd046b2 ON StudentCustomAnswer_Test_ (Test2_)"));
    res.push_back(Database::SchemaItem("O2727a76c497312c0f79484a5292f3","index","CREATE INDEX O2727a76c497312c0f79484a5292f3 ON StudentCustomAnswer_Test_ (StudentCustomAnswer1_,Test2_)"));
    res.push_back(Database::SchemaItem("Ob682e0b25611342323c4386ae5e6f","index","CREATE INDEX Ob682e0b25611342323c4386ae5e6f ON TestAnswer_TestQuestion_ (TestAnswer1_)"));
    res.push_back(Database::SchemaItem("O16497dc8a39722401016fa4e36d9d","index","CREATE INDEX O16497dc8a39722401016fa4e36d9d ON TestAnswer_TestQuestion_ (TestQuestion2_)"));
    res.push_back(Database::SchemaItem("O988209e31395d85871f39725ded27","index","CREATE INDEX O988209e31395d85871f39725ded27 ON TestAnswer_TestQuestion_ (TestAnswer1_,TestQuestion2_)"));
    res.push_back(Database::SchemaItem("O50f3b72591b1a7edbdad7574c7d09","index","CREATE INDEX O50f3b72591b1a7edbdad7574c7d09 ON Student_StudentAnswer_ (Student1_)"));
    res.push_back(Database::SchemaItem("Oa037e52b3b15b8b7ea75bdfa3ce49","index","CREATE INDEX Oa037e52b3b15b8b7ea75bdfa3ce49 ON Student_StudentAnswer_ (StudentAnswer2_)"));
    res.push_back(Database::SchemaItem("Student_StudentAnswer__all_idx","index","CREATE INDEX Student_StudentAnswer__all_idx ON Student_StudentAnswer_ (Student1_,StudentAnswer2_)"));
    res.push_back(Database::SchemaItem("Oc001e381d8a1070bed04ce8b21f72","index","CREATE INDEX Oc001e381d8a1070bed04ce8b21f72 ON Student_StudentCustomAnswer_ (Student1_)"));
    res.push_back(Database::SchemaItem("Oc2be20a2db8a2d016e0e2f95ba36a","index","CREATE INDEX Oc2be20a2db8a2d016e0e2f95ba36a ON Student_StudentCustomAnswer_ (StudentCustomAnswer2_)"));
    res.push_back(Database::SchemaItem("Oe94a7da2ce534822108735e7dd763","index","CREATE INDEX Oe94a7da2ce534822108735e7dd763 ON Student_StudentCustomAnswer_ (Student1_,StudentCustomAnswer2_)"));
    return res;
}
void TestSuiteDB::initialize() {
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
}
}
