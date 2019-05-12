/****************************************************************************
** Meta object code from reading C++ file 'QDBCheckBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../db_code/QDBCheckBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDBCheckBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QDBCheckBox_t {
    QByteArrayData data[7];
    char stringdata[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDBCheckBox_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDBCheckBox_t qt_meta_stringdata_QDBCheckBox = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QDBCheckBox"
QT_MOC_LITERAL(1, 12, 10), // "clickedNum"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "num"
QT_MOC_LITERAL(4, 28, 5), // "click"
QT_MOC_LITERAL(5, 34, 3), // "pos"
QT_MOC_LITERAL(6, 38, 12) // "slot_emitNum"

    },
    "QDBCheckBox\0clickedNum\0\0num\0click\0pos\0"
    "slot_emitNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDBCheckBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void,

       0        // eod
};

void QDBCheckBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDBCheckBox *_t = static_cast<QDBCheckBox *>(_o);
        switch (_id) {
        case 0: _t->clickedNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->click((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->slot_emitNum(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QDBCheckBox::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDBCheckBox::clickedNum)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QDBCheckBox::staticMetaObject = {
    { &QCheckBox::staticMetaObject, qt_meta_stringdata_QDBCheckBox.data,
      qt_meta_data_QDBCheckBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QDBCheckBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBCheckBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QDBCheckBox.stringdata))
        return static_cast<void*>(const_cast< QDBCheckBox*>(this));
    return QCheckBox::qt_metacast(_clname);
}

int QDBCheckBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCheckBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QDBCheckBox::clickedNum(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
