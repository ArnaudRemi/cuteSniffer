/****************************************************************************
** Meta object code from reading C++ file 'FilterData.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "filters/FilterData.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilterData.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FilterData_t {
    QByteArrayData data[8];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterData_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterData_t qt_meta_stringdata_FilterData = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FilterData"
QT_MOC_LITERAL(1, 11, 18), // "ether_dhostChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "ether_shostChanged"
QT_MOC_LITERAL(4, 50, 17), // "ether_typeChanged"
QT_MOC_LITERAL(5, 68, 11), // "ether_dhost"
QT_MOC_LITERAL(6, 80, 11), // "ether_shost"
QT_MOC_LITERAL(7, 92, 10) // "ether_type"

    },
    "FilterData\0ether_dhostChanged\0\0"
    "ether_shostChanged\0ether_typeChanged\0"
    "ether_dhost\0ether_shost\0ether_type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00495103,
       6, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void FilterData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterData *_t = static_cast<FilterData *>(_o);
        switch (_id) {
        case 0: _t->ether_dhostChanged(); break;
        case 1: _t->ether_shostChanged(); break;
        case 2: _t->ether_typeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FilterData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterData::ether_dhostChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (FilterData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterData::ether_shostChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (FilterData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterData::ether_typeChanged)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FilterData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FilterData.data,
      qt_meta_data_FilterData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FilterData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FilterData.stringdata))
        return static_cast<void*>(const_cast< FilterData*>(this));
    return QObject::qt_metacast(_clname);
}

int FilterData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getEther_dhost(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getEther_shost(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getEther_type(); break;
        default: break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setEther_dhost(*reinterpret_cast< QString*>(_v)); break;
        case 1: setEther_shost(*reinterpret_cast< QString*>(_v)); break;
        case 2: setEther_type(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FilterData::ether_dhostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void FilterData::ether_shostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void FilterData::ether_typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
