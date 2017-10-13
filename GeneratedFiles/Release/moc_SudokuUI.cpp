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
    QByteArrayData data[18];
    char stringdata0[252];
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
QT_MOC_LITERAL(3, 22, 21), // "refreshAboutSudokuBox"
QT_MOC_LITERAL(4, 44, 15), // "responseGetTips"
QT_MOC_LITERAL(5, 60, 5), // "rowId"
QT_MOC_LITERAL(6, 66, 5), // "colId"
QT_MOC_LITERAL(7, 72, 14), // "responseFinish"
QT_MOC_LITERAL(8, 87, 17), // "refreshLCDCurTime"
QT_MOC_LITERAL(9, 105, 23), // "refreshPreAndNextButton"
QT_MOC_LITERAL(10, 129, 15), // "responsePreGame"
QT_MOC_LITERAL(11, 145, 16), // "responseNextGame"
QT_MOC_LITERAL(12, 162, 11), // "refreshJump"
QT_MOC_LITERAL(13, 174, 12), // "responseJump"
QT_MOC_LITERAL(14, 187, 17), // "responsePlayAgain"
QT_MOC_LITERAL(15, 205, 13), // "responsePause"
QT_MOC_LITERAL(16, 219, 16), // "responseContinue"
QT_MOC_LITERAL(17, 236, 15) // "responseGetHelp"

    },
    "SudokuUI\0receiveQues\0\0refreshAboutSudokuBox\0"
    "responseGetTips\0rowId\0colId\0responseFinish\0"
    "refreshLCDCurTime\0refreshPreAndNextButton\0"
    "responsePreGame\0responseNextGame\0"
    "refreshJump\0responseJump\0responsePlayAgain\0"
    "responsePause\0responseContinue\0"
    "responseGetHelp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SudokuUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    2,   86,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    0,   95,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    0,   98,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,
      16,    0,  100,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->receiveQues(); break;
        case 1: _t->refreshAboutSudokuBox(); break;
        case 2: _t->responseGetTips((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->responseFinish(); break;
        case 4: _t->refreshLCDCurTime(); break;
        case 5: _t->refreshPreAndNextButton(); break;
        case 6: _t->responsePreGame(); break;
        case 7: _t->responseNextGame(); break;
        case 8: _t->refreshJump(); break;
        case 9: _t->responseJump(); break;
        case 10: _t->responsePlayAgain(); break;
        case 11: _t->responsePause(); break;
        case 12: _t->responseContinue(); break;
        case 13: _t->responseGetHelp(); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
