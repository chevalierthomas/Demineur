/****************************************************************************
** Meta object code from reading C++ file 'DifficultySelectionDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "DifficultySelectionDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DifficultySelectionDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DifficultySelectionDialog_t {
    QByteArrayData data[14];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DifficultySelectionDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DifficultySelectionDialog_t qt_meta_stringdata_DifficultySelectionDialog = {
    {
QT_MOC_LITERAL(0, 0, 25), // "DifficultySelectionDialog"
QT_MOC_LITERAL(1, 26, 18), // "gameStartRequested"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 5), // "width"
QT_MOC_LITERAL(4, 52, 6), // "height"
QT_MOC_LITERAL(5, 59, 5), // "mines"
QT_MOC_LITERAL(6, 65, 22), // "customizationRequested"
QT_MOC_LITERAL(7, 88, 22), // "onStandardGameSelected"
QT_MOC_LITERAL(8, 111, 20), // "onMediumGameSelected"
QT_MOC_LITERAL(9, 132, 18), // "onHardGameSelected"
QT_MOC_LITERAL(10, 151, 23), // "onCustomizationSelected"
QT_MOC_LITERAL(11, 175, 15), // "onExitRequested"
QT_MOC_LITERAL(12, 191, 13), // "onToggleSound"
QT_MOC_LITERAL(13, 205, 12) // "onShowScores"

    },
    "DifficultySelectionDialog\0gameStartRequested\0"
    "\0width\0height\0mines\0customizationRequested\0"
    "onStandardGameSelected\0onMediumGameSelected\0"
    "onHardGameSelected\0onCustomizationSelected\0"
    "onExitRequested\0onToggleSound\0"
    "onShowScores"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DifficultySelectionDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       6,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DifficultySelectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DifficultySelectionDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameStartRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->customizationRequested(); break;
        case 2: _t->onStandardGameSelected(); break;
        case 3: _t->onMediumGameSelected(); break;
        case 4: _t->onHardGameSelected(); break;
        case 5: _t->onCustomizationSelected(); break;
        case 6: _t->onExitRequested(); break;
        case 7: _t->onToggleSound(); break;
        case 8: _t->onShowScores(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DifficultySelectionDialog::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DifficultySelectionDialog::gameStartRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DifficultySelectionDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DifficultySelectionDialog::customizationRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DifficultySelectionDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DifficultySelectionDialog.data,
    qt_meta_data_DifficultySelectionDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DifficultySelectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DifficultySelectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DifficultySelectionDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DifficultySelectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DifficultySelectionDialog::gameStartRequested(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DifficultySelectionDialog::customizationRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
