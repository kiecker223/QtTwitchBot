/****************************************************************************
** Meta object code from reading C++ file 'CommandDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CommandDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommandDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CommandDialog_t {
    QByteArrayData data[13];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandDialog_t qt_meta_stringdata_CommandDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CommandDialog"
QT_MOC_LITERAL(1, 14, 14), // "syncDialogData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "addDialogOption"
QT_MOC_LITERAL(4, 46, 5), // "value"
QT_MOC_LITERAL(5, 52, 8), // "saveData"
QT_MOC_LITERAL(6, 61, 31), // "on_DialogOutputNum_valueChanged"
QT_MOC_LITERAL(7, 93, 4), // "arg1"
QT_MOC_LITERAL(8, 98, 18), // "createAddDialogWin"
QT_MOC_LITERAL(9, 117, 36), // "on_commandSelect_currentIndex..."
QT_MOC_LITERAL(10, 154, 5), // "index"
QT_MOC_LITERAL(11, 160, 24), // "on_deleteButton_released"
QT_MOC_LITERAL(12, 185, 20) // "on_forceSave_clicked"

    },
    "CommandDialog\0syncDialogData\0\0"
    "addDialogOption\0value\0saveData\0"
    "on_DialogOutputNum_valueChanged\0arg1\0"
    "createAddDialogWin\0"
    "on_commandSelect_currentIndexChanged\0"
    "index\0on_deleteButton_released\0"
    "on_forceSave_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    1,   55,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    1,   59,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    1,   63,    2, 0x08 /* Private */,
      11,    0,   66,    2, 0x08 /* Private */,
      12,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CommandDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommandDialog *_t = static_cast<CommandDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->syncDialogData(); break;
        case 1: _t->addDialogOption((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->saveData(); break;
        case 3: _t->on_DialogOutputNum_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->createAddDialogWin(); break;
        case 5: _t->on_commandSelect_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_deleteButton_released(); break;
        case 7: _t->on_forceSave_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject CommandDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CommandDialog.data,
      qt_meta_data_CommandDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CommandDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CommandDialog.stringdata0))
        return static_cast<void*>(const_cast< CommandDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CommandDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
