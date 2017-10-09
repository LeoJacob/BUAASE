/****************************************************************************
** Meta object code from reading C++ file 'SudokuUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SudokuUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SudokuUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SudokuUI_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SudokuUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SudokuUI_t qt_meta_stringdata_SudokuUI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SudokuUI"
QT_MOC_LITERAL(1, 9, 11), // "receiveQues"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "int**"
QT_MOC_LITERAL(4, 28, 4), // "ques"
QT_MOC_LITERAL(5, 33, 15), // "iGenerateNumber"
QT_MOC_LITERAL(6, 49, 10), // "refreshAll"
QT_MOC_LITERAL(7, 60, 15), // "responseGetTips"
QT_MOC_LITERAL(8, 76, 14), // "responseFinish"
QT_MOC_LITERAL(9, 91, 17) // "refreshLCDCurTime"

    },
    "SudokuUI\0receiveQues\0\0int**\0ques\0"
    "iGenerateNumber\0refreshAll\0responseGetTips\0"
    "responseFinish\0refreshLCDCurTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SudokuUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,
       8,    0,   46,    2, 0x0a /* Public */,
       9,    0,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SudokuUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SudokuUI *_t = static_cast<SudokuUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveQues((*reinterpret_cast< int**(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->refreshAll(); break;
        case 2: _t->responseGetTips(); break;
        case 3: _t->responseFinish(); break;
        case 4: _t->refreshLCDCurTime(); break;
        default: ;
        }
    }
}

const QMetaObject SudokuUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SudokuUI.data,
      qt_meta_data_SudokuUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SudokuUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SudokuUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SudokuUI.stringdata0))
        return static_cast<void*>(const_cast< SudokuUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SudokuUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
