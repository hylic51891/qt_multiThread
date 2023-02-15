/****************************************************************************
** Meta object code from reading C++ file 'test_multiThreading.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../test_multiThreading.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_multiThreading.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_test_multiThreading_t {
    QByteArrayData data[15];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_test_multiThreading_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_test_multiThreading_t qt_meta_stringdata_test_multiThreading = {
    {
QT_MOC_LITERAL(0, 0, 19), // "test_multiThreading"
QT_MOC_LITERAL(1, 20, 15), // "sengMsgToThread"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16), // "sig_doAutoDetect"
QT_MOC_LITERAL(4, 54, 16), // "sig_doResultDeal"
QT_MOC_LITERAL(5, 71, 11), // "slot_finish"
QT_MOC_LITERAL(6, 83, 32), // "on_StartAutoDetectButton_clicked"
QT_MOC_LITERAL(7, 116, 31), // "on_StopAutoDetectButton_clicked"
QT_MOC_LITERAL(8, 148, 25), // "on_PLCstartButton_clicked"
QT_MOC_LITERAL(9, 174, 31), // "slot_recMegFromAutoDetectThread"
QT_MOC_LITERAL(10, 206, 3), // "str"
QT_MOC_LITERAL(11, 210, 31), // "slot_recMegFromResultDealThread"
QT_MOC_LITERAL(12, 242, 34), // "slot_recResultFromResultDealT..."
QT_MOC_LITERAL(13, 277, 14), // "test_structure"
QT_MOC_LITERAL(14, 292, 11) // "show_result"

    },
    "test_multiThreading\0sengMsgToThread\0"
    "\0sig_doAutoDetect\0sig_doResultDeal\0"
    "slot_finish\0on_StartAutoDetectButton_clicked\0"
    "on_StopAutoDetectButton_clicked\0"
    "on_PLCstartButton_clicked\0"
    "slot_recMegFromAutoDetectThread\0str\0"
    "slot_recMegFromResultDealThread\0"
    "slot_recResultFromResultDealThread\0"
    "test_structure\0show_result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_test_multiThreading[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    0,   67,    2, 0x06 /* Public */,
       4,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   69,    2, 0x0a /* Public */,
       6,    0,   70,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    1,   73,    2, 0x0a /* Public */,
      11,    1,   76,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void test_multiThreading::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        test_multiThreading *_t = static_cast<test_multiThreading *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sengMsgToThread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_doAutoDetect(); break;
        case 2: _t->sig_doResultDeal(); break;
        case 3: _t->slot_finish(); break;
        case 4: _t->on_StartAutoDetectButton_clicked(); break;
        case 5: _t->on_StopAutoDetectButton_clicked(); break;
        case 6: _t->on_PLCstartButton_clicked(); break;
        case 7: _t->slot_recMegFromAutoDetectThread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slot_recMegFromResultDealThread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slot_recResultFromResultDealThread((*reinterpret_cast< test_structure(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (test_multiThreading::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&test_multiThreading::sengMsgToThread)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (test_multiThreading::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&test_multiThreading::sig_doAutoDetect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (test_multiThreading::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&test_multiThreading::sig_doResultDeal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject test_multiThreading::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_test_multiThreading.data,
      qt_meta_data_test_multiThreading,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *test_multiThreading::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *test_multiThreading::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_test_multiThreading.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int test_multiThreading::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void test_multiThreading::sengMsgToThread(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void test_multiThreading::sig_doAutoDetect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void test_multiThreading::sig_doResultDeal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
