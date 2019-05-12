/****************************************************************************
** Meta object code from reading C++ file 'SUTestResults.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTestSuite_admin/SUTestResults.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SUTestResults.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SUTestResults_t {
    QByteArrayData data[9];
    char stringdata[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SUTestResults_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SUTestResults_t qt_meta_stringdata_SUTestResults = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SUTestResults"
QT_MOC_LITERAL(1, 14, 17), // "GoToSUStudentInfo"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "GoToSUTestsLits"
QT_MOC_LITERAL(4, 49, 17), // "GoToSUStudResults"
QT_MOC_LITERAL(5, 67, 8), // "updateUI"
QT_MOC_LITERAL(6, 76, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 98, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(8, 122, 23) // "on_pushButton_3_clicked"

    },
    "SUTestResults\0GoToSUStudentInfo\0\0"
    "GoToSUTestsLits\0GoToSUStudResults\0"
    "updateUI\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SUTestResults[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SUTestResults::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SUTestResults *_t = static_cast<SUTestResults *>(_o);
        switch (_id) {
        case 0: _t->GoToSUStudentInfo(); break;
        case 1: _t->GoToSUTestsLits(); break;
        case 2: _t->GoToSUStudResults(); break;
        case 3: _t->updateUI(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SUTestResults::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SUTestResults::GoToSUStudentInfo)) {
                *result = 0;
            }
        }
        {
            typedef void (SUTestResults::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SUTestResults::GoToSUTestsLits)) {
                *result = 1;
            }
        }
        {
            typedef void (SUTestResults::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SUTestResults::GoToSUStudResults)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SUTestResults::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SUTestResults.data,
      qt_meta_data_SUTestResults,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SUTestResults::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SUTestResults::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SUTestResults.stringdata))
        return static_cast<void*>(const_cast< SUTestResults*>(this));
    return QDialog::qt_metacast(_clname);
}

int SUTestResults::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SUTestResults::GoToSUStudentInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SUTestResults::GoToSUTestsLits()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SUTestResults::GoToSUStudResults()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
