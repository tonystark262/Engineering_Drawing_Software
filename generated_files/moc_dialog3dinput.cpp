/****************************************************************************
** Meta object code from reading C++ file 'dialog3dinput.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/qtgui/dialog3dinput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog3dinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog3DInput[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      39,   14,   14,   14, 0x08,
      65,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialog3DInput[] = {
    "Dialog3DInput\0\0on_pushButton_clicked()\0"
    "on_proceed3DBtn_clicked()\0"
    "on_proceedFileBtn_clicked()\0"
};

void Dialog3DInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog3DInput *_t = static_cast<Dialog3DInput *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_proceed3DBtn_clicked(); break;
        case 2: _t->on_proceedFileBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Dialog3DInput::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog3DInput::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog3DInput,
      qt_meta_data_Dialog3DInput, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog3DInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog3DInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog3DInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog3DInput))
        return static_cast<void*>(const_cast< Dialog3DInput*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog3DInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
