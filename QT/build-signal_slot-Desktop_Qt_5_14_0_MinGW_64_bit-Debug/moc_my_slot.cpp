/****************************************************************************
** Meta object code from reading C++ file 'my_slot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../signal_slot/my_slot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_slot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_my_slot_t {
    QByteArrayData data[9];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_my_slot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_my_slot_t qt_meta_stringdata_my_slot = {
    {
QT_MOC_LITERAL(0, 0, 7), // "my_slot"
QT_MOC_LITERAL(1, 8, 9), // "slot_test"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "std::string"
QT_MOC_LITERAL(4, 31, 4), // "_msg"
QT_MOC_LITERAL(5, 36, 8), // "slot_foo"
QT_MOC_LITERAL(6, 45, 11), // "slot_foo_01"
QT_MOC_LITERAL(7, 57, 11), // "slot_foo_02"
QT_MOC_LITERAL(8, 69, 11) // "slot_foo_03"

    },
    "my_slot\0slot_test\0\0std::string\0_msg\0"
    "slot_foo\0slot_foo_01\0slot_foo_02\0"
    "slot_foo_03"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_my_slot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       1,    1,   45,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void my_slot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<my_slot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_test(); break;
        case 1: _t->slot_test((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->slot_foo(); break;
        case 3: _t->slot_foo_01(); break;
        case 4: _t->slot_foo_02(); break;
        case 5: _t->slot_foo_03(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject my_slot::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_my_slot.data,
    qt_meta_data_my_slot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *my_slot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *my_slot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_my_slot.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int my_slot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
