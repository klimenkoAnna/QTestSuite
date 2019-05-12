/****************************************************************************
** Meta object code from reading C++ file 'TestWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTestSuite_user/TestWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestWindow_t {
    QByteArrayData data[8];
    char stringdata[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestWindow_t qt_meta_stringdata_TestWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TestWindow"
QT_MOC_LITERAL(1, 11, 18), // "GoToTestResultsWnd"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "GoToTestSelectWnd"
QT_MOC_LITERAL(4, 49, 8), // "updateUI"
QT_MOC_LITERAL(5, 58, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 80, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 104, 23) // "on_pushButton_3_clicked"

    },
    "TestWindow\0GoToTestResultsWnd\0\0"
    "GoToTestSelectWnd\0updateUI\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestWindow *_t = static_cast<TestWindow *>(_o);
        switch (_id) {
        case 0: _t->GoToTestResultsWnd(); break;
        case 1: _t->GoToTestSelectWnd(); break;
        case 2: _t->updateUI(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TestWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TestWindow::GoToTestResultsWnd)) {
                *result = 0;
            }
        }
        {
            typedef void (TestWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TestWindow::GoToTestSelectWnd)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TestWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TestWindow.data,
      qt_meta_data_TestWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TestWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TestWindow.stringdata))
        return static_cast<void*>(const_cast< TestWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int TestWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TestWindow::GoToTestResultsWnd()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TestWindow::GoToTestSelectWnd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
