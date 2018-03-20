/****************************************************************************
** Meta object code from reading C++ file 'testwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Four/testwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_testwindow_t {
    QByteArrayData data[11];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_testwindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_testwindow_t qt_meta_stringdata_testwindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "testwindow"
QT_MOC_LITERAL(1, 11, 10), // "myComplete"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "repeatTest"
QT_MOC_LITERAL(4, 34, 7), // "retTest"
QT_MOC_LITERAL(5, 42, 7), // "myCheck"
QT_MOC_LITERAL(6, 50, 6), // "myPass"
QT_MOC_LITERAL(7, 57, 6), // "myExit"
QT_MOC_LITERAL(8, 64, 8), // "myReport"
QT_MOC_LITERAL(9, 73, 12), // "myTestRepeat"
QT_MOC_LITERAL(10, 86, 9) // "myTestRet"

    },
    "testwindow\0myComplete\0\0repeatTest\0"
    "retTest\0myCheck\0myPass\0myExit\0myReport\0"
    "myTestRepeat\0myTestRet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_testwindow[] = {

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

void testwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        testwindow *_t = static_cast<testwindow *>(_o);
        switch (_id) {
        case 0: _t->myComplete(); break;
        case 1: _t->repeatTest(); break;
        case 2: _t->retTest(); break;
        case 3: _t->myCheck(); break;
        case 4: _t->myPass(); break;
        case 5: _t->myExit(); break;
        case 6: _t->myReport(); break;
        case 7: _t->myTestRepeat(); break;
        case 8: _t->myTestRet(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (testwindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testwindow::myComplete)) {
                *result = 0;
            }
        }
        {
            typedef void (testwindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testwindow::repeatTest)) {
                *result = 1;
            }
        }
        {
            typedef void (testwindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testwindow::retTest)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject testwindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_testwindow.data,
      qt_meta_data_testwindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *testwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *testwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_testwindow.stringdata))
        return static_cast<void*>(const_cast< testwindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int testwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void testwindow::myComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void testwindow::repeatTest()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void testwindow::retTest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
