/****************************************************************************
** Meta object code from reading C++ file 'MainView.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "views/MainView.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainView.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainView_t {
    QByteArrayData data[16];
    char stringdata[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainView_t qt_meta_stringdata_MainView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainView"
QT_MOC_LITERAL(1, 9, 14), // "packetsChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "interfaceChanged"
QT_MOC_LITERAL(4, 42, 16), // "promisciousError"
QT_MOC_LITERAL(5, 59, 10), // "runCapture"
QT_MOC_LITERAL(6, 70, 11), // "stopCapture"
QT_MOC_LITERAL(7, 82, 11), // "saveCapture"
QT_MOC_LITERAL(8, 94, 13), // "deleteCapture"
QT_MOC_LITERAL(9, 108, 11), // "catchPacket"
QT_MOC_LITERAL(10, 120, 12), // "displayUsers"
QT_MOC_LITERAL(11, 133, 14), // "rowDoubleClick"
QT_MOC_LITERAL(12, 148, 3), // "row"
QT_MOC_LITERAL(13, 152, 7), // "packets"
QT_MOC_LITERAL(14, 160, 33), // "QQmlListProperty<EthernetDisp..."
QT_MOC_LITERAL(15, 194, 9) // "interface"

    },
    "MainView\0packetsChanged\0\0interfaceChanged\0"
    "promisciousError\0runCapture\0stopCapture\0"
    "saveCapture\0deleteCapture\0catchPacket\0"
    "displayUsers\0rowDoubleClick\0row\0packets\0"
    "QQmlListProperty<EthernetDisplay>\0"
    "interface"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    1,   73,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Int,   12,

 // properties: name, type, flags
      13, 0x80000000 | 14, 0x00495009,
      15, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void MainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainView *_t = static_cast<MainView *>(_o);
        switch (_id) {
        case 0: _t->packetsChanged(); break;
        case 1: _t->interfaceChanged(); break;
        case 2: _t->promisciousError(); break;
        case 3: _t->runCapture(); break;
        case 4: _t->stopCapture(); break;
        case 5: _t->saveCapture(); break;
        case 6: _t->deleteCapture(); break;
        case 7: _t->catchPacket(); break;
        case 8: _t->displayUsers(); break;
        case 9: _t->rowDoubleClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::packetsChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::interfaceChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::promisciousError)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MainView::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainView.data,
      qt_meta_data_MainView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainView.stringdata))
        return static_cast<void*>(const_cast< MainView*>(this));
    return QObject::qt_metacast(_clname);
}

int MainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<EthernetDisplay>*>(_v) = getPackets(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getInterface(); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setInterface(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainView::packetsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainView::interfaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainView::promisciousError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
