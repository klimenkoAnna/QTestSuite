/****************************************************************************
** Meta object code from reading C++ file 'SUStudResults.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTestSuite_admin/SUStudResults.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SUStudResults.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SUStudResults_t {
    QByteArrayData data[7];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SUStudResults_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SUStudResults_t qt_meta_stringdata_SUStudResults = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SUStudResults"
QT_MOC_LITERAL(1, 14, 17), // "GoToSUTestResults"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "updateUI"
QT_MOC_LITERAL(4, 42, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 64, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 88, 23) // "on_pushButton_3_clicked"

    },
    "SUStudResults\0GoToSUTestResults\0\0"
    "updateUI\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SUStudResults[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SUStudResults::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SUStudResults *_t = static_cast<SUStudResults *>(_o);
        switch (_id) {
        case 0: _t->GoToSUTestResults(); break;
        case 1: _t->updateUI(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SUStudResults::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SUStudResults::GoToSUTestResults)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SUStudResults::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SUStudResults.data,
      qt_meta_data_SUStudResults,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SUStudResults::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SUStudResults::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SUStudResults.stringdata))
        return static_cast<void*>(const_cast< SUStudResults*>(this));
    return QDialog::qt_metacast(_clname);
}

int SUStudResults::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SUStudResults::GoToSUTestResults()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
