/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[36];
    char stringdata0[330];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 13), // "Mouse_Pressed"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 14), // "Mouse_Released"
QT_MOC_LITERAL(41, 17), // "showMousePosition"
QT_MOC_LITERAL(59, 7), // "QPoint&"
QT_MOC_LITERAL(67, 3), // "pos"
QT_MOC_LITERAL(71, 20), // "on_show_axes_clicked"
QT_MOC_LITERAL(92, 15), // "on_Draw_clicked"
QT_MOC_LITERAL(108, 21), // "on_set_point1_clicked"
QT_MOC_LITERAL(130, 21), // "on_set_point2_clicked"
QT_MOC_LITERAL(152, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(174, 25), // "on_pushButtonCopy_clicked"
QT_MOC_LITERAL(200, 26), // "on_pushButtonPaste_clicked"
QT_MOC_LITERAL(227, 24), // "on_pushButtonNew_clicked"
QT_MOC_LITERAL(252, 25), // "on_pushButtonOpen_clicked"
QT_MOC_LITERAL(278, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(304, 25) // "on_pushButtonFind_clicked"

    },
    "MainWindow\0Mouse_Pressed\0\0Mouse_Released\0"
    "showMousePosition\0QPoint&\0pos\0"
    "on_show_axes_clicked\0on_Draw_clicked\0"
    "on_set_point1_clicked\0on_set_point2_clicked\0"
    "on_pushButton_clicked\0on_pushButtonCopy_clicked\0"
    "on_pushButtonPaste_clicked\0"
    "on_pushButtonNew_clicked\0"
    "on_pushButtonOpen_clicked\0"
    "on_pushButtonSave_clicked\0"
    "on_pushButtonFind_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x0a,    1 /* Public */,
       3,    0,   99,    2, 0x0a,    2 /* Public */,
       4,    1,  100,    2, 0x0a,    3 /* Public */,
       7,    0,  103,    2, 0x08,    5 /* Private */,
       8,    0,  104,    2, 0x08,    6 /* Private */,
       9,    0,  105,    2, 0x08,    7 /* Private */,
      10,    0,  106,    2, 0x08,    8 /* Private */,
      11,    0,  107,    2, 0x08,    9 /* Private */,
      12,    0,  108,    2, 0x08,   10 /* Private */,
      13,    0,  109,    2, 0x08,   11 /* Private */,
      14,    0,  110,    2, 0x08,   12 /* Private */,
      15,    0,  111,    2, 0x08,   13 /* Private */,
      16,    0,  112,    2, 0x08,   14 /* Private */,
      17,    0,  113,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->Mouse_Released(); break;
        case 2: _t->showMousePosition((*reinterpret_cast< std::add_pointer_t<QPoint&>>(_a[1]))); break;
        case 3: _t->on_show_axes_clicked(); break;
        case 4: _t->on_Draw_clicked(); break;
        case 5: _t->on_set_point1_clicked(); break;
        case 6: _t->on_set_point2_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButtonCopy_clicked(); break;
        case 9: _t->on_pushButtonPaste_clicked(); break;
        case 10: _t->on_pushButtonNew_clicked(); break;
        case 11: _t->on_pushButtonOpen_clicked(); break;
        case 12: _t->on_pushButtonSave_clicked(); break;
        case 13: _t->on_pushButtonFind_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
