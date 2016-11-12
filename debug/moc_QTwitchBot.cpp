/****************************************************************************
** Meta object code from reading C++ file 'QTwitchBot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QTwitchBot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTwitchBot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QTwitchBot_t {
    QByteArrayData data[13];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTwitchBot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTwitchBot_t qt_meta_stringdata_QTwitchBot = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QTwitchBot"
QT_MOC_LITERAL(1, 11, 11), // "setPassword"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "newPassword"
QT_MOC_LITERAL(4, 36, 11), // "setUsername"
QT_MOC_LITERAL(5, 48, 11), // "newUserName"
QT_MOC_LITERAL(6, 60, 14), // "setChannelName"
QT_MOC_LITERAL(7, 75, 14), // "newChannelName"
QT_MOC_LITERAL(8, 90, 22), // "writeCommandDataToFile"
QT_MOC_LITERAL(9, 113, 23), // "readCommandDataFromFile"
QT_MOC_LITERAL(10, 137, 16), // "onMessageRecieve"
QT_MOC_LITERAL(11, 154, 7), // "connect"
QT_MOC_LITERAL(12, 162, 10) // "disconnect"

    },
    "QTwitchBot\0setPassword\0\0newPassword\0"
    "setUsername\0newUserName\0setChannelName\0"
    "newChannelName\0writeCommandDataToFile\0"
    "readCommandDataFromFile\0onMessageRecieve\0"
    "connect\0disconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTwitchBot[] = {

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
       1,    1,   54,    2, 0x0a /* Public */,
       4,    1,   57,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       8,    0,   63,    2, 0x0a /* Public */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QTwitchBot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTwitchBot *_t = static_cast<QTwitchBot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPassword((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->setUsername((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->setChannelName((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->writeCommandDataToFile(); break;
        case 4: _t->readCommandDataFromFile(); break;
        case 5: _t->onMessageRecieve(); break;
        case 6: _t->connect(); break;
        case 7: _t->disconnect(); break;
        default: ;
        }
    }
}

const QMetaObject QTwitchBot::staticMetaObject = {
    { &QTextBrowser::staticMetaObject, qt_meta_stringdata_QTwitchBot.data,
      qt_meta_data_QTwitchBot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QTwitchBot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTwitchBot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QTwitchBot.stringdata0))
        return static_cast<void*>(const_cast< QTwitchBot*>(this));
    return QTextBrowser::qt_metacast(_clname);
}

int QTwitchBot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextBrowser::qt_metacall(_c, _id, _a);
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
