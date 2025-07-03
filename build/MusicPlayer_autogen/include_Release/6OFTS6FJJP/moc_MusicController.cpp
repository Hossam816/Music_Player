/****************************************************************************
** Meta object code from reading C++ file 'MusicController.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../header/MusicController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN15MusicControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto MusicController::qt_create_metaobjectdata<qt_meta_tag_ZN15MusicControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MusicController",
        "currentSongChanged",
        "",
        "volumeChanged",
        "playingStateChanged",
        "playlistChanged",
        "positionChanged",
        "durationChanged",
        "OpenFolder",
        "Play",
        "Pause",
        "Next",
        "Previous",
        "SetVolume",
        "volume",
        "SetPosition",
        "position",
        "SeekToPosition",
        "currentSong",
        "isPlaying",
        "playlistSize",
        "duration",
        "formattedPosition",
        "formattedDuration"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'currentSongChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'volumeChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'playingStateChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'playlistChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'positionChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'durationChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'OpenFolder'
        QtMocHelpers::MethodData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'Play'
        QtMocHelpers::MethodData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'Pause'
        QtMocHelpers::MethodData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'Next'
        QtMocHelpers::MethodData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'Previous'
        QtMocHelpers::MethodData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'SetVolume'
        QtMocHelpers::MethodData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Method 'SetPosition'
        QtMocHelpers::MethodData<void(qint64)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 16 },
        }}),
        // Method 'SeekToPosition'
        QtMocHelpers::MethodData<void(qint64)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'currentSong'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'volume'
        QtMocHelpers::PropertyData<int>(14, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable, 1),
        // property 'isPlaying'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
        // property 'playlistSize'
        QtMocHelpers::PropertyData<int>(20, QMetaType::Int, QMC::DefaultPropertyFlags, 3),
        // property 'position'
        QtMocHelpers::PropertyData<qint64>(16, QMetaType::LongLong, QMC::DefaultPropertyFlags, 4),
        // property 'duration'
        QtMocHelpers::PropertyData<qint64>(21, QMetaType::LongLong, QMC::DefaultPropertyFlags, 5),
        // property 'formattedPosition'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags, 4),
        // property 'formattedDuration'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags, 5),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MusicController, qt_meta_tag_ZN15MusicControllerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MusicController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MusicControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MusicControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15MusicControllerE_t>.metaTypes,
    nullptr
} };

void MusicController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MusicController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentSongChanged(); break;
        case 1: _t->volumeChanged(); break;
        case 2: _t->playingStateChanged(); break;
        case 3: _t->playlistChanged(); break;
        case 4: _t->positionChanged(); break;
        case 5: _t->durationChanged(); break;
        case 6: _t->OpenFolder(); break;
        case 7: _t->Play(); break;
        case 8: _t->Pause(); break;
        case 9: _t->Next(); break;
        case 10: _t->Previous(); break;
        case 11: _t->SetVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->SetPosition((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 13: _t->SeekToPosition((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MusicController::*)()>(_a, &MusicController::currentSongChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicController::*)()>(_a, &MusicController::volumeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicController::*)()>(_a, &MusicController::playingStateChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicController::*)()>(_a, &MusicController::playlistChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicController::*)()>(_a, &MusicController::positionChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicController::*)()>(_a, &MusicController::durationChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->CurrentSong(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->Volume(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->IsPlaying(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->PlaylistSize(); break;
        case 4: *reinterpret_cast<qint64*>(_v) = _t->Position(); break;
        case 5: *reinterpret_cast<qint64*>(_v) = _t->Duration(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->FormattedPosition(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->FormattedDuration(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->SetVolume(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *MusicController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MusicControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MusicController::currentSongChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MusicController::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MusicController::playingStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MusicController::playlistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MusicController::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MusicController::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
