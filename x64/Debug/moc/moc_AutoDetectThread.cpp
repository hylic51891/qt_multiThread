/****************************************************************************
** Meta object code from reading C++ file 'AutoDetectThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AutoDetectThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AutoDetectThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AutoDetectThread_t {
    QByteArrayData data[8];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutoDetectThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutoDetectThread_t qt_meta_stringdata_AutoDetectThread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AutoDetectThread"
QT_MOC_LITERAL(1, 17, 19), // "sig_ResultDealstart"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 10), // "sig_finish"
QT_MOC_LITERAL(4, 49, 13), // "sendMegToMain"
QT_MOC_LITERAL(5, 63, 3), // "str"
QT_MOC_LITERAL(6, 67, 17), // "slot_doAutoDetect"
QT_MOC_LITERAL(7, 85, 9) // "slot_stop"

    },
    "AutoDetectThread\0sig_ResultDealstart\0"
    "\0sig_finish\0sendMegToMain\0str\0"
    "slot_doAutoDetect\0slot_stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutoDetectThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AutoDetectThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AutoDetectThread *_t = static_cast<AutoDetectThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_ResultDealstart(); break;
        case 1: _t->sig_finish(); break;
        case 2: _t->sendMegToMain((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slot_doAutoDetect(); break;
        case 4: _t->slot_stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AutoDetectThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AutoDetectThread::sig_ResultDealstart)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AutoDetectThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AutoDetectThread::sig_finish)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AutoDetectThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AutoDetectThread::sendMegToMain)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject AutoDetectThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AutoDetectThread.data,
      qt_meta_data_AutoDetectThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AutoDetectThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutoDetectThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AutoDetectThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AutoDetectThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void AutoDetectThread::sig_ResultDealstart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AutoDetectThread::sig_finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AutoDetectThread::sendMegToMain(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
