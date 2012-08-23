/****************************************************************************
** Meta object code from reading C++ file 'board.h'
**
** Created: Thu 16. Aug 20:58:52 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Snake_Trabalho/board.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'board.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Board[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,    7,    6,    6, 0x05,
      41,   35,    6,    6, 0x05,
      58,    6,    6,    6, 0x05,
      76,    6,    6,    6, 0x05,
      89,    6,    6,    6, 0x05,
     102,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     115,    6,    6,    6, 0x0a,
     124,    6,    6,    6, 0x0a,
     132,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Board[] = {
    "Board\0\0level\0nivelDificuldade(int)\0"
    "score\0pontosGanho(int)\0barra_Progresso()\0"
    "barra_Vida()\0sinalReset()\0salvaScore()\0"
    "inicio()\0pausa()\0reset()\0"
};

void Board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Board *_t = static_cast<Board *>(_o);
        switch (_id) {
        case 0: _t->nivelDificuldade((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->pontosGanho((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->barra_Progresso(); break;
        case 3: _t->barra_Vida(); break;
        case 4: _t->sinalReset(); break;
        case 5: _t->salvaScore(); break;
        case 6: _t->inicio(); break;
        case 7: _t->pausa(); break;
        case 8: _t->reset(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Board::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Board::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_Board,
      qt_meta_data_Board, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Board::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Board::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Board))
        return static_cast<void*>(const_cast< Board*>(this));
    return QFrame::qt_metacast(_clname);
}

int Board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Board::nivelDificuldade(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Board::pontosGanho(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Board::barra_Progresso()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Board::barra_Vida()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Board::sinalReset()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Board::salvaScore()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
