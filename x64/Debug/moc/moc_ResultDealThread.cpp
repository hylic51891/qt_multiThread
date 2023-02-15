/****************************************************************************
** Meta object code from reading C++ file 'ResultDealThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ResultDealThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ResultDealThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResultDealThread_t {
    QByteArrayData data[9];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResultDealThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResultDealThread_t qt_meta_stringdata_ResultDealThread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ResultDealThread"
QT_MOC_LITERAL(1, 17, 10), // "sig_finish"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "chip_finish"
QT_MOC_LITERAL(4, 41, 16), // "sendResultToMain"
QT_MOC_LITERAL(5, 58, 14), // "test_structure"
QT_MOC_LITERAL(6, 73, 13), // "sendMegToMain"
QT_MOC_LITERAL(7, 87, 14), // "slot_chipstart"
QT_MOC_LITERAL(8, 102, 17) // "slot_doResultDeal"

    },
    "ResultDealThread\0sig_finish\0\0chip_finish\0"
    "sendResultToMain\0test_structure\0"
    "sendMegToMain\0slot_chipstart\0"
    "slot_doResultDeal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResultDealThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   52,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResultDealThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResultDealThread *_t = static_cast<ResultDealThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_finish(); break;
        case 1: _t->chip_finish(); break;
        case 2: _t->sendResultToMain((*reinterpret_cast< test_structure(*)>(_a[1]))); break;
        case 3: _t->sendMegToMain((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slot_chipstart(); break;
        case 5: _t->slot_doResultDeal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ResultDealThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultDealThread::sig_finish)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ResultDealThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultDealThread::chip_finish)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ResultDealThread::*_t)(test_structure );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultDealThread::sendResultToMain)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ResultDealThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultDealThread::sendMegToMain)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ResultDealThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ResultDealThread.data,
      qt_meta_data_ResultDealThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ResultDealThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResultDealThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResultDealThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ResultDealThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ResultDealThread::sig_finish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ResultDealThread::chip_finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ResultDealThread::sendResultToMain(test_structure _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ResultDealThread::sendMegToMain(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
