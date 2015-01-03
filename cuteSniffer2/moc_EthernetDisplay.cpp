/****************************************************************************
** Meta object code from reading C++ file 'EthernetDisplay.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "views/EthernetDisplay.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EthernetDisplay.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EthernetDisplay_t {
    QByteArrayData data[11];
    char stringdata[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EthernetDisplay_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EthernetDisplay_t qt_meta_stringdata_EthernetDisplay = {
    {
QT_MOC_LITERAL(0, 0, 15), // "EthernetDisplay"
QT_MOC_LITERAL(1, 16, 12), // "dhostChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "shostChanged"
QT_MOC_LITERAL(4, 43, 11), // "typeChanged"
QT_MOC_LITERAL(5, 55, 11), // "dataChanged"
QT_MOC_LITERAL(6, 67, 10), // "sendPacket"
QT_MOC_LITERAL(7, 78, 5), // "dhost"
QT_MOC_LITERAL(8, 84, 5), // "shost"
QT_MOC_LITERAL(9, 90, 4), // "type"
QT_MOC_LITERAL(10, 95, 4) // "data"

    },
    "EthernetDisplay\0dhostChanged\0\0"
    "shostChanged\0typeChanged\0dataChanged\0"
    "sendPacket\0dhost\0shost\0type\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EthernetDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       4,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void EthernetDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EthernetDisplay *_t = static_cast<EthernetDisplay *>(_o);
        switch (_id) {
        case 0: _t->dhostChanged(); break;
        case 1: _t->shostChanged(); break;
        case 2: _t->typeChanged(); break;
        case 3: _t->dataChanged(); break;
        case 4: _t->sendPacket(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EthernetDisplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EthernetDisplay::dhostChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (EthernetDisplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EthernetDisplay::shostChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (EthernetDisplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EthernetDisplay::typeChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (EthernetDisplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EthernetDisplay::dataChanged)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EthernetDisplay::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EthernetDisplay.data,
      qt_meta_data_EthernetDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EthernetDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EthernetDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EthernetDisplay.stringdata))
        return static_cast<void*>(const_cast< EthernetDisplay*>(this));
    return QObject::qt_metacast(_clname);
}

int EthernetDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getDhost(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getShost(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getType(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getData(); break;
        default: break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDhost(*reinterpret_cast< QString*>(_v)); break;
        case 1: setShost(*reinterpret_cast< QString*>(_v)); break;
        case 2: setType(*reinterpret_cast< QString*>(_v)); break;
        case 3: setData(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void EthernetDisplay::dhostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void EthernetDisplay::shostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void EthernetDisplay::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void EthernetDisplay::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
