/****************************************************************************
** Meta object code from reading C++ file 'report.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Four/report.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'report.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_report_t {
    QByteArrayData data[6];
    char stringdata[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_report_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_report_t qt_meta_stringdata_report = {
    {
QT_MOC_LITERAL(0, 0, 6), // "report"
QT_MOC_LITERAL(1, 7, 12), // "repeatReport"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "retReport"
QT_MOC_LITERAL(4, 31, 10), // "repeatPush"
QT_MOC_LITERAL(5, 42, 7) // "retPush"

    },
    "report\0repeatReport\0\0retReport\0"
    "repeatPush\0retPush"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_report[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void report::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        report *_t = static_cast<report *>(_o);
        switch (_id) {
        case 0: _t->repeatReport(); break;
        case 1: _t->retReport(); break;
        case 2: _t->repeatPush(); break;
        case 3: _t->retPush(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (report::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&report::repeatReport)) {
                *result = 0;
            }
        }
        {
            typedef void (report::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&report::retReport)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject report::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_report.data,
      qt_meta_data_report,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *report::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *report::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_report.stringdata))
        return static_cast<void*>(const_cast< report*>(this));
    return QDialog::qt_metacast(_clname);
}

int report::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void report::repeatReport()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void report::retReport()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
