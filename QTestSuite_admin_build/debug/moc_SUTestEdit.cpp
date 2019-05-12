/****************************************************************************
** Meta object code from reading C++ file 'SUTestEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTestSuite_admin/SUTestEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SUTestEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SUTestEdit_t {
    QByteArrayData data[15];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SUTestEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SUTestEdit_t qt_meta_stringdata_SUTestEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SUTestEdit"
QT_MOC_LITERAL(1, 11, 15), // "GoToSUTestsList"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "updateUI"
QT_MOC_LITERAL(4, 37, 12), // "deleteAnswer"
QT_MOC_LITERAL(5, 50, 3), // "num"
QT_MOC_LITERAL(6, 54, 16), // "setAnswerPicture"
QT_MOC_LITERAL(7, 71, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 93, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(9, 117, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(10, 141, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(11, 165, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(12, 189, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(13, 213, 34), // "on_checkBoxQuestionPicture_cl..."
QT_MOC_LITERAL(14, 248, 7) // "checked"

    },
    "SUTestEdit\0GoToSUTestsList\0\0updateUI\0"
    "deleteAnswer\0num\0setAnswerPicture\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked\0"
    "on_checkBoxQuestionPicture_clicked\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SUTestEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x08 /* Private */,
       4,    1,   71,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       7,    0,   77,    2, 0x08 /* Private */,
       8,    0,   78,    2, 0x08 /* Private */,
       9,    0,   79,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void SUTestEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SUTestEdit *_t = static_cast<SUTestEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GoToSUTestsList(); break;
        case 1: _t->updateUI(); break;
        case 2: _t->deleteAnswer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setAnswerPicture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_4_clicked(); break;
        case 8: _t->on_pushButton_5_clicked(); break;
        case 9: _t->on_pushButton_6_clicked(); break;
        case 10: _t->on_checkBoxQuestionPicture_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SUTestEdit::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SUTestEdit::GoToSUTestsList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SUTestEdit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SUTestEdit.data,
      qt_meta_data_SUTestEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SUTestEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SUTestEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SUTestEdit.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SUTestEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SUTestEdit::GoToSUTestsList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
