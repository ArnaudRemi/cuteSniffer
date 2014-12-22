/****************************************************************************
** Meta object code from reading C++ file 'MainScreen.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graphic/MainScreen.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainScreen.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      19,   11,   11,   11, 0x0a,
      29,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      77,   75,   11,   11, 0x0a,
      99,   11,   11,   11, 0x0a,
     116,  111,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainScreen[] = {
    "MainScreen\0\0quit()\0capture()\0filtring()\0"
    "forging()\0manInMiddle()\0modifier()\0,\0"
    "cellSelected(int,int)\0getPacket()\0"
    "item\0itemClicked(QListWidgetItem*)\0"
};

void MainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainScreen *_t = static_cast<MainScreen *>(_o);
        switch (_id) {
        case 0: _t->quit(); break;
        case 1: _t->capture(); break;
        case 2: _t->filtring(); break;
        case 3: _t->forging(); break;
        case 4: _t->manInMiddle(); break;
        case 5: _t->modifier(); break;
        case 6: _t->cellSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->getPacket(); break;
        case 8: _t->itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainScreen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainScreen,
      qt_meta_data_MainScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainScreen))
        return static_cast<void*>(const_cast< MainScreen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
