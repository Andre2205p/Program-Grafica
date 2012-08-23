/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created: Thu 16. Aug 20:58:56 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Snake_Trabalho/window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Window[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      16,    7,    7,    7, 0x0a,
      23,    7,    7,    7, 0x0a,
      42,    7,    7,    7, 0x0a,
      56,    7,    7,    7, 0x0a,
      68,    7,    7,    7, 0x0a,
      85,    7,    7,    7, 0x0a,
     103,    7,   98,    7, 0x0a,
     115,    7,    7,    7, 0x0a,
     132,    7,    7,    7, 0x0a,
     145,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Window[] = {
    "Window\0\0about()\0save()\0barraDeProgresso()\0"
    "barraDeVida()\0resetJogo()\0resetBarraVida()\0"
    "writeScore()\0bool\0readScore()\0"
    "readWriteScore()\0clearScore()\0"
    "openScores()\0"
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Window *_t = static_cast<Window *>(_o);
        switch (_id) {
        case 0: _t->about(); break;
        case 1: _t->save(); break;
        case 2: _t->barraDeProgresso(); break;
        case 3: _t->barraDeVida(); break;
        case 4: _t->resetJogo(); break;
        case 5: _t->resetBarraVida(); break;
        case 6: _t->writeScore(); break;
        case 7: { bool _r = _t->readScore();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->readWriteScore(); break;
        case 9: _t->clearScore(); break;
        case 10: _t->openScores(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Window::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window,
      qt_meta_data_Window, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Window::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Window))
        return static_cast<void*>(const_cast< Window*>(this));
    return QWidget::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
