#pragma once
#include <ostream>
struct ceiling_t;
struct elevator_t;
struct fireflicker_t;
struct floormove_t;
struct glow_t;
struct lightflash_t;
struct mobj_t;
struct message_thinker_t;
struct plat_t;
struct strobe_t;
struct vldoor_t;
struct player_t;
struct pspdef_t;
struct scroll_t;
struct pusher_t;
struct friction_t;
struct thinker_t;
class Action
{
  public:
    using t_ceiling = void (*)(ceiling_t *);
    using t_elevator = void (*)(elevator_t *);
    using t_fireflicker = void (*)(fireflicker_t *);
    using t_floormove = void (*)(floormove_t *);
    using t_friction = void (*)(friction_t *);
    using t_glow = void (*)(glow_t *);
    using t_lightflash = void (*)(lightflash_t *);
    using t_mobj = void (*)(mobj_t *);
    using t_message_thinker = void (*)(message_thinker_t *);
    using t_plat = void (*)(plat_t *);
    using t_plps = void (*)(player_t *, pspdef_t *);
    using t_pusher = void (*)(pusher_t *);
    using t_scroll = void (*)(scroll_t *);
    using t_strobe = void (*)(strobe_t *);
    using t_thinker = void (*)(thinker_t *);
    using t_vldoor = void (*)(vldoor_t *);
    using t_v = void (*)();
    using t_p1 = void (*)(void *);
    using t_p2 = void (*)(void *, void *);
  private:
    t_ceiling m_ceiling = nullptr;
    t_elevator m_elevator = nullptr;
    t_fireflicker m_fireflicker = nullptr;
    t_floormove m_floormove = nullptr;
    t_friction m_friction = nullptr;
    t_glow m_glow = nullptr;
    t_lightflash m_lightflash = nullptr;
    t_mobj m_mobj = nullptr;
    t_message_thinker m_message_thinker = nullptr;
    t_plat m_plat = nullptr;
    t_plps m_plps = nullptr;
    t_pusher m_pusher = nullptr;
    t_scroll m_scroll = nullptr;
    t_strobe m_strobe = nullptr;
    t_thinker m_thinker = nullptr;
    t_vldoor m_vldoor = nullptr;
    t_v m_v = nullptr;
    t_p1 m_p1 = nullptr;
    t_p2 m_p2 = nullptr;
    enum class discriminant
    {
        undefined,
        ceiling,
        elevator,
        fireflicker,
        floormove,
        friction,
        glow,
        lightflash,
        mobj,
        message_thinker,
        plat,
        plps,
        pusher,
        scroll,
        strobe,
        thinker,
        vldoor,
        v,
        p1,
        p2,
    };
    discriminant m_discriminant = discriminant::undefined;
  public:
    constexpr Action() = default;
    constexpr Action(t_ceiling ceiling)
        : m_ceiling(ceiling), m_discriminant(discriminant::ceiling)
    {
    }
    constexpr t_ceiling ceiling()
    {
        return m_ceiling;
    }
    constexpr Action(t_elevator elevator)
        : m_elevator(elevator), m_discriminant(discriminant::elevator)
    {
    }
    constexpr t_elevator elevator()
    {
        return m_elevator;
    }
    constexpr Action(t_fireflicker fireflicker)
        : m_fireflicker(fireflicker), m_discriminant(discriminant::fireflicker)
    {
    }
    constexpr t_fireflicker fireflicker()
    {
        return m_fireflicker;
    }
    constexpr Action(t_floormove floormove)
        : m_floormove(floormove), m_discriminant(discriminant::floormove)
    {
    }
    constexpr t_floormove floormove()
    {
        return m_floormove;
    }
    constexpr Action(t_friction friction)
        : m_friction(friction), m_discriminant(discriminant::friction)
    {
    }
    constexpr t_friction friction()
    {
        return m_friction;
    }
    constexpr Action(t_glow glow)
        : m_glow(glow), m_discriminant(discriminant::glow)
    {
    }
    constexpr t_glow glow()
    {
        return m_glow;
    }
    constexpr Action(t_lightflash lightflash)
        : m_lightflash(lightflash), m_discriminant(discriminant::lightflash)
    {
    }
    constexpr t_lightflash lightflash()
    {
        return m_lightflash;
    }
    constexpr Action(t_mobj mobj)
        : m_mobj(mobj), m_discriminant(discriminant::mobj)
    {
    }
    constexpr t_mobj mobj()
    {
        return m_mobj;
    }
    constexpr Action(t_message_thinker message_thinker)
        : m_message_thinker(message_thinker),
          m_discriminant(discriminant::message_thinker)
    {
    }
    constexpr t_message_thinker message_thinker()
    {
        return m_message_thinker;
    }
    constexpr Action(t_plat plat)
        : m_plat(plat), m_discriminant(discriminant::plat)
    {
    }
    constexpr t_plat plat()
    {
        return m_plat;
    }
    constexpr Action(t_plps plps)
        : m_plps(plps), m_discriminant(discriminant::plps)
    {
    }
    constexpr t_plps plps()
    {
        return m_plps;
    }
    constexpr Action(t_pusher pusher)
        : m_pusher(pusher), m_discriminant(discriminant::pusher)
    {
    }
    constexpr t_pusher pusher()
    {
        return m_pusher;
    }
    constexpr Action(t_scroll scroll)
        : m_scroll(scroll), m_discriminant(discriminant::scroll)
    {
    }
    constexpr t_scroll scroll()
    {
        return m_scroll;
    }
    constexpr Action(t_strobe strobe)
        : m_strobe(strobe), m_discriminant(discriminant::strobe)
    {
    }
    constexpr t_strobe strobe()
    {
        return m_strobe;
    }
    constexpr Action(t_thinker thinker)
        : m_thinker(thinker), m_discriminant(discriminant::thinker)
    {
    }
    constexpr t_thinker thinker()
    {
        return m_thinker;
    }
    constexpr Action(t_vldoor vldoor)
        : m_vldoor(vldoor), m_discriminant(discriminant::vldoor)
    {
    }
    constexpr t_vldoor vldoor()
    {
        return m_vldoor;
    }
    constexpr Action(t_v v) : m_v(v), m_discriminant(discriminant::v)
    {
    }
    constexpr t_v v()
    {
        return m_v;
    }
    constexpr Action(t_p1 p1) : m_p1(p1), m_discriminant(discriminant::p1)
    {
    }
    constexpr t_p1 p1()
    {
        return m_p1;
    }
    constexpr Action(t_p2 p2) : m_p2(p2), m_discriminant(discriminant::p2)
    {
    }
    constexpr t_p2 p2()
    {
        return m_p2;
    }
    constexpr bool operator==(const Action &other) const
    {
        switch (m_discriminant)
        {
        case discriminant::ceiling:
            return m_ceiling == other.m_ceiling;
        case discriminant::elevator:
            return m_elevator == other.m_elevator;
        case discriminant::fireflicker:
            return m_fireflicker == other.m_fireflicker;
        case discriminant::floormove:
            return m_floormove == other.m_floormove;
        case discriminant::friction:
            return m_friction == other.m_friction;
        case discriminant::glow:
            return m_glow == other.m_glow;
        case discriminant::lightflash:
            return m_lightflash == other.m_lightflash;
        case discriminant::mobj:
            return m_mobj == other.m_mobj;
        case discriminant::message_thinker:
            return m_message_thinker == other.m_message_thinker;
        case discriminant::plat:
            return m_plat == other.m_plat;
        case discriminant::plps:
            return m_plps == other.m_plps;
        case discriminant::pusher:
            return m_pusher == other.m_pusher;
        case discriminant::scroll:
            return m_scroll == other.m_scroll;
        case discriminant::strobe:
            return m_strobe == other.m_strobe;
        case discriminant::thinker:
            return m_thinker == other.m_thinker;
        case discriminant::vldoor:
            return m_vldoor == other.m_vldoor;
        case discriminant::v:
            return m_v == other.m_v;
        case discriminant::p1:
            return m_p1 == other.m_p1;
        case discriminant::p2:
            return m_p2 == other.m_p2;
        case discriminant::undefined:
            return true;
        }
    }
    constexpr bool operator!=(const Action &other) const
    {
        return !(*this == other);
    }
    friend std::ostream &operator<<(std::ostream &os, const Action &action);
};
constexpr Action ACTION_NULL;
struct default_t;
struct setup_menu_t;
class SetupMenuVar
{
  public:
    using t_other = const void *;
    using t_key = int *;
    using t_name = const char *;
    using t_def = default_t *;
    using t_menu = setup_menu_t *;
  private:
    t_other m_other = nullptr;
    t_key m_key = nullptr;
    t_name m_name = nullptr;
    t_def m_def = nullptr;
    t_menu m_menu = nullptr;
    enum class discriminant
    {
        undefined,
        other,
        key,
        name,
        def,
        menu,
    };
    discriminant m_discriminant = discriminant::undefined;
  public:
    constexpr SetupMenuVar() = default;
    constexpr SetupMenuVar(t_other other)
        : m_other(other), m_discriminant(discriminant::other)
    {
    }
    constexpr t_other other()
    {
        return m_other;
    }
    constexpr SetupMenuVar(t_key key)
        : m_key(key), m_discriminant(discriminant::key)
    {
    }
    constexpr t_key key()
    {
        return m_key;
    }
    constexpr SetupMenuVar(t_name name)
        : m_name(name), m_discriminant(discriminant::name)
    {
    }
    constexpr t_name name()
    {
        return m_name;
    }
    constexpr SetupMenuVar(t_def def)
        : m_def(def), m_discriminant(discriminant::def)
    {
    }
    constexpr t_def def()
    {
        return m_def;
    }
    constexpr SetupMenuVar(t_menu menu)
        : m_menu(menu), m_discriminant(discriminant::menu)
    {
    }
    constexpr t_menu menu()
    {
        return m_menu;
    }
    constexpr bool operator==(const SetupMenuVar &other) const
    {
        switch (m_discriminant)
        {
        case discriminant::other:
            return m_other == other.m_other;
        case discriminant::key:
            return m_key == other.m_key;
        case discriminant::name:
            return m_name == other.m_name;
        case discriminant::def:
            return m_def == other.m_def;
        case discriminant::menu:
            return m_menu == other.m_menu;
        case discriminant::undefined:
            return true;
        }
    }
    constexpr bool operator!=(const SetupMenuVar &other) const
    {
        return !(*this == other);
    }
    friend std::ostream &operator<<(std::ostream &os,
                                    const SetupMenuVar &setupmenuvar);
};
constexpr SetupMenuVar SETUPMENUVAR_NULL;
class CheatSequenceFunction
{
  public:
    using t_v = void (*)();
    using t_i1 = void (*)(int);
    using t_buf = void (*)(const char *);
  private:
    t_v m_v = nullptr;
    t_i1 m_i1 = nullptr;
    t_buf m_buf = nullptr;
    enum class discriminant
    {
        undefined,
        v,
        i1,
        buf,
    };
    discriminant m_discriminant = discriminant::undefined;
  public:
    constexpr CheatSequenceFunction() = default;
    constexpr CheatSequenceFunction(t_v v)
        : m_v(v), m_discriminant(discriminant::v)
    {
    }
    constexpr t_v v()
    {
        return m_v;
    }
    constexpr CheatSequenceFunction(t_i1 i1)
        : m_i1(i1), m_discriminant(discriminant::i1)
    {
    }
    constexpr t_i1 i1()
    {
        return m_i1;
    }
    constexpr CheatSequenceFunction(t_buf buf)
        : m_buf(buf), m_discriminant(discriminant::buf)
    {
    }
    constexpr t_buf buf()
    {
        return m_buf;
    }
    constexpr bool operator==(const CheatSequenceFunction &other) const
    {
        switch (m_discriminant)
        {
        case discriminant::v:
            return m_v == other.m_v;
        case discriminant::i1:
            return m_i1 == other.m_i1;
        case discriminant::buf:
            return m_buf == other.m_buf;
        case discriminant::undefined:
            return true;
        }
    }
    constexpr bool operator!=(const CheatSequenceFunction &other) const
    {
        return !(*this == other);
    }
    friend std::ostream &operator<<(
        std::ostream &os, const CheatSequenceFunction &cheatsequencefunction);
};
constexpr CheatSequenceFunction CHEATSEQUENCEFUNCTION_NULL;