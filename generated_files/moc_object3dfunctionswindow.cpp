/****************************************************************************
** Meta object code from reading C++ file 'object3dfunctionswindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/qtgui/object3dfunctionswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'object3dfunctionswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_object3DFunctionsWindow[] = {

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
      25,   24,   24,   24, 0x08,
      47,   24,   24,   24, 0x08,
      73,   24,   24,   24, 0x08,
      96,   24,   24,   24, 0x08,
     125,   24,   24,   24, 0x08,
     149,   24,   24,   24, 0x08,
     180,   24,   24,   24, 0x08,
     208,   24,   24,   24, 0x08,
     231,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_object3DFunctionsWindow[] = {
    "object3DFunctionsWindow\0\0on_scaleBtn_clicked()\0"
    "on_translateBtn_clicked()\0"
    "on_rotateBtn_clicked()\0"
    "on_planeProjectBtn_clicked()\0"
    "on_reflectBtn_clicked()\0"
    "on_orthographic3DBtn_clicked()\0"
    "on_isometric3DBtn_clicked()\0"
    "on_renderBtn_clicked()\0"
    "on_renderSolidBtn_clicked()\0"
};

void object3DFunctionsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        object3DFunctionsWindow *_t = static_cast<object3DFunctionsWindow *>(_o);
        switch (_id) {
        case 0: _t->on_scaleBtn_clicked(); break;
        case 1: _t->on_translateBtn_clicked(); break;
        case 2: _t->on_rotateBtn_clicked(); break;
        case 3: _t->on_planeProjectBtn_clicked(); break;
        case 4: _t->on_reflectBtn_clicked(); break;
        case 5: _t->on_orthographic3DBtn_clicked(); break;
        case 6: _t->on_isometric3DBtn_clicked(); break;
        case 7: _t->on_renderBtn_clicked(); break;
        case 8: _t->on_renderSolidBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData object3DFunctionsWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject object3DFunctionsWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_object3DFunctionsWindow,
      qt_meta_data_object3DFunctionsWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &object3DFunctionsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *object3DFunctionsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *object3DFunctionsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_object3DFunctionsWindow))
        return static_cast<void*>(const_cast< object3DFunctionsWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int object3DFunctionsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
