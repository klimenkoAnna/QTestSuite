/****************************************************************************
** Meta object code from reading C++ file 'SUTestsList.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTestSuite_admin/SUTestsList.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SUTestsList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SUTestsList_t {
    QByteArrayData data[11];
    char stringdata[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SUTestsList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SUTestsList_t qt_meta_stringdata_SUTestsList = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SUTestsList"
QT_MOC_LITERAL(1, 12, 17), // "GoToSUTestResults"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "GoToSUTestEdit"
QT_MOC_LITERAL(4, 46, 12), // "GoToLoginWnd"
QT_MOC_LITERAL(5, 59, 8), // "updateUI"
QT_MOC_LITERAL(6, 68, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 90, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(8, 114, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(9, 138, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(10, 162, 23) // "on_pushButton_5_clicked"

    },
    "SUTestsList\0GoToSUTestResults\0\0"
    "GoToSUTestEdit\0GoToLoginWnd\0updateUI\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SUTestsList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SUTestsList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SUTestsList *_t = static_cast<SUTestsList *>(_o);
        switch (_id) {
        case 0: _t->GoToSUTestResults(); break;
        case 1: _t->GoToSUTestEdit(); break;
        case 2: _t->GoToLoginWnd(); break;
        case 3: _t->updateUI(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_4_clicked(); break;
        case 8: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SUTestsList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SUTestsList::GoToSUTestResults)) {
                *result = 0;
            }
        }
        {
            typedef void (SUTestsList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SUTestsList::GoToSUTestEdit)) {
                *result = 1;
            }
        }
        {
            typedef void (SUTestsList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SUTestsList::GoToLoginWnd)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SUTestsList::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SUTestsList.data,
      qt_meta_data_SUTestsList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SUTestsList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SUTestsList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SUTestsList.stringdata))
        return static_cast<void*>(const_cast< SUTestsList*>(this));
    return QDialog::qt_metacast(_clname);
}

int SUTestsList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SUTestsList::GoToSUTestResults()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SUTestsList::GoToSUTestEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SUTestsList::GoToLoginWnd()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
