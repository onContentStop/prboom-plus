#include "unions.hh"
std::ostream &operator<<(std::ostream &os, const Action &action)
{
    switch (action.m_discriminant)
    {
    case Action::discriminant::ceiling:
        return os << "Action { kind: ceiling, pointer: " << action.m_ceiling
                  << " }";
    case Action::discriminant::elevator:
        return os << "Action { kind: elevator, pointer: " << action.m_elevator
                  << " }";
    case Action::discriminant::fireflicker:
        return os << "Action { kind: fireflicker, pointer: "
                  << action.m_fireflicker << " }";
    case Action::discriminant::floormove:
        return os << "Action { kind: floormove, pointer: " << action.m_floormove
                  << " }";
    case Action::discriminant::friction:
        return os << "Action { kind: friction, pointer: " << action.m_friction
                  << " }";
    case Action::discriminant::glow:
        return os << "Action { kind: glow, pointer: " << action.m_glow << " }";
    case Action::discriminant::lightflash:
        return os << "Action { kind: lightflash, pointer: "
                  << action.m_lightflash << " }";
    case Action::discriminant::mobj:
        return os << "Action { kind: mobj, pointer: " << action.m_mobj << " }";
    case Action::discriminant::message_thinker:
        return os << "Action { kind: message_thinker, pointer: "
                  << action.m_message_thinker << " }";
    case Action::discriminant::plat:
        return os << "Action { kind: plat, pointer: " << action.m_plat << " }";
    case Action::discriminant::plps:
        return os << "Action { kind: plps, pointer: " << action.m_plps << " }";
    case Action::discriminant::pusher:
        return os << "Action { kind: pusher, pointer: " << action.m_pusher
                  << " }";
    case Action::discriminant::scroll:
        return os << "Action { kind: scroll, pointer: " << action.m_scroll
                  << " }";
    case Action::discriminant::strobe:
        return os << "Action { kind: strobe, pointer: " << action.m_strobe
                  << " }";
    case Action::discriminant::thinker:
        return os << "Action { kind: thinker, pointer: " << action.m_thinker
                  << " }";
    case Action::discriminant::vldoor:
        return os << "Action { kind: vldoor, pointer: " << action.m_vldoor
                  << " }";
    case Action::discriminant::v:
        return os << "Action { kind: v, pointer: " << action.m_v << " }";
    case Action::discriminant::p1:
        return os << "Action { kind: p1, pointer: " << action.m_p1 << " }";
    case Action::discriminant::p2:
        return os << "Action { kind: p2, pointer: " << action.m_p2 << " }";
    case Action::discriminant::undefined:
        return os << "Action { kind: undefined }";
    }
}
std::ostream &operator<<(std::ostream &os, const SetupMenuVar &setupmenuvar)
{
    switch (setupmenuvar.m_discriminant)
    {
    case SetupMenuVar::discriminant::other:
        return os << "SetupMenuVar { kind: other, pointer: "
                  << setupmenuvar.m_other << " }";
    case SetupMenuVar::discriminant::key:
        return os << "SetupMenuVar { kind: key, pointer: " << setupmenuvar.m_key
                  << " }";
    case SetupMenuVar::discriminant::name:
        return os << "SetupMenuVar { kind: name, pointer: "
                  << setupmenuvar.m_name << " }";
    case SetupMenuVar::discriminant::def:
        return os << "SetupMenuVar { kind: def, pointer: " << setupmenuvar.m_def
                  << " }";
    case SetupMenuVar::discriminant::menu:
        return os << "SetupMenuVar { kind: menu, pointer: "
                  << setupmenuvar.m_menu << " }";
    case SetupMenuVar::discriminant::undefined:
        return os << "SetupMenuVar { kind: undefined }";
    }
}
std::ostream &operator<<(std::ostream &os,
                         const CheatSequenceFunction &cheatsequencefunction)
{
    switch (cheatsequencefunction.m_discriminant)
    {
    case CheatSequenceFunction::discriminant::v:
        return os << "CheatSequenceFunction { kind: v, pointer: "
                  << cheatsequencefunction.m_v << " }";
    case CheatSequenceFunction::discriminant::i1:
        return os << "CheatSequenceFunction { kind: i1, pointer: "
                  << cheatsequencefunction.m_i1 << " }";
    case CheatSequenceFunction::discriminant::buf:
        return os << "CheatSequenceFunction { kind: buf, pointer: "
                  << cheatsequencefunction.m_buf << " }";
    case CheatSequenceFunction::discriminant::undefined:
        return os << "CheatSequenceFunction { kind: undefined }";
    }
}