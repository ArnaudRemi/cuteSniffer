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
    QByteArrayData data[26];
    char stringdata[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainView_t qt_meta_stringdata_MainView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainView"
QT_MOC_LITERAL(1, 9, 20), // "clientHandlerChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "packetsChanged"
QT_MOC_LITERAL(4, 46, 16), // "interfaceChanged"
QT_MOC_LITERAL(5, 63, 16), // "promisciousError"
QT_MOC_LITERAL(6, 80, 15), // "openFileChanged"
QT_MOC_LITERAL(7, 96, 15), // "saveFileChanged"
QT_MOC_LITERAL(8, 112, 10), // "runCapture"
QT_MOC_LITERAL(9, 123, 11), // "stopCapture"
QT_MOC_LITERAL(10, 135, 11), // "saveCapture"
QT_MOC_LITERAL(11, 147, 11), // "openCapture"
QT_MOC_LITERAL(12, 159, 13), // "deleteCapture"
QT_MOC_LITERAL(13, 173, 11), // "catchPacket"
QT_MOC_LITERAL(14, 185, 12), // "displayUsers"
QT_MOC_LITERAL(15, 198, 14), // "rowDoubleClick"
QT_MOC_LITERAL(16, 213, 3), // "row"
QT_MOC_LITERAL(17, 217, 14), // "openFileSelect"
QT_MOC_LITERAL(18, 232, 14), // "saveFileSelect"
QT_MOC_LITERAL(19, 247, 7), // "packets"
QT_MOC_LITERAL(20, 255, 33), // "QQmlListProperty<EthernetDisp..."
QT_MOC_LITERAL(21, 289, 9), // "interface"
QT_MOC_LITERAL(22, 299, 8), // "openFile"
QT_MOC_LITERAL(23, 308, 8), // "saveFile"
QT_MOC_LITERAL(24, 317, 13), // "clientHandler"
QT_MOC_LITERAL(25, 331, 13) // "ClientHandler"

    },
    "MainView\0clientHandlerChanged\0\0"
    "packetsChanged\0interfaceChanged\0"
    "promisciousError\0openFileChanged\0"
    "saveFileChanged\0runCapture\0stopCapture\0"
    "saveCapture\0openCapture\0deleteCapture\0"
    "catchPacket\0displayUsers\0rowDoubleClick\0"
    "row\0openFileSelect\0saveFileSelect\0"
    "packets\0QQmlListProperty<EthernetDisplay>\0"
    "interface\0openFile\0saveFile\0clientHandler\0"
    "ClientHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       5,  112, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    0,   98,    2, 0x06 /* Public */,
       7,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    1,  107,    2, 0x0a /* Public */,
      17,    0,  110,    2, 0x0a /* Public */,
      18,    0,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      19, 0x80000000 | 20, 0x00495009,
      21, QMetaType::QString, 0x00495103,
      22, QMetaType::QString, 0x00495103,
      23, QMetaType::QString, 0x00495103,
      24, 0x80000000 | 25, 0x00495009,

 // properties: notify_signal_id
       1,
       2,
       4,
       5,
       0,

       0        // eod
};

void MainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainView *_t = static_cast<MainView *>(_o);
        switch (_id) {
        case 0: _t->clientHandlerChanged(); break;
        case 1: _t->packetsChanged(); break;
        case 2: _t->interfaceChanged(); break;
        case 3: _t->promisciousError(); break;
        case 4: _t->openFileChanged(); break;
        case 5: _t->saveFileChanged(); break;
        case 6: _t->runCapture(); break;
        case 7: _t->stopCapture(); break;
        case 8: _t->saveCapture(); break;
        case 9: _t->openCapture(); break;
        case 10: _t->deleteCapture(); break;
        case 11: _t->catchPacket(); break;
        case 12: _t->displayUsers(); break;
        case 13: _t->rowDoubleClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->openFileSelect(); break;
        case 15: _t->saveFileSelect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::clientHandlerChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::packetsChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::interfaceChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::promisciousError)) {
                *result = 3;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::openFileChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (MainView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainView::saveFileChanged)) {
                *result = 5;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<EthernetDisplay>*>(_v) = getPackets(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getInterface(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getOpenFile(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getSaveFile(); break;
        case 4: *reinterpret_cast< ClientHandler*>(_v) = getClientHandler(); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setInterface(*reinterpret_cast< QString*>(_v)); break;
        case 2: setOpenFile(*reinterpret_cast< QString*>(_v)); break;
        case 3: setSaveFile(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainView::clientHandlerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainView::packetsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainView::interfaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainView::promisciousError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainView::openFileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainView::saveFileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
