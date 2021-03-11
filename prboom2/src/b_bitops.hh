#pragma once

#include <type_traits>

template <typename Underlying,
          typename = std::enable_if_t<std::is_integral<Underlying>::value>>
class Bitset
{
    Underlying m_value;

  public:
    constexpr Bitset() : m_value(Underlying())
    {
    }

    constexpr Bitset(Underlying value) : m_value(value)
    {
    }

    constexpr Underlying value() const
    {
        return m_value;
    }

    constexpr Bitset<Underlying> operator~() const
    {
        return ~m_value;
    }

    constexpr Bitset<Underlying> operator|(
        const Bitset<Underlying> &other) const
    {
        return {static_cast<Underlying>(m_value | other.m_value)};
    }

    constexpr Bitset<Underlying> operator&(
        const Bitset<Underlying> &other) const
    {
        return {static_cast<Underlying>(m_value & other.m_value)};
    }

    constexpr Bitset<Underlying> operator^(
        const Bitset<Underlying> &other) const
    {
        return {static_cast<Underlying>(m_value ^ other.m_value)};
    }

    constexpr Bitset<Underlying> &operator|=(const Bitset<Underlying> &other)
    {
        m_value |= other.m_value;
        return *this;
    }

    constexpr Bitset<Underlying> &operator&=(const Bitset<Underlying> &other)
    {
        m_value &= other.m_value;
        return *this;
    }

    constexpr Bitset<Underlying> &operator^=(const Bitset<Underlying> &other)
    {
        m_value ^= other.m_value;
        return *this;
    }

    constexpr operator bool() const
    {
        return m_value != 0;
    }

    constexpr bool operator!() const
    {
        return m_value == 0;
    }
};

template <typename Underlying,
          typename = std::enable_if_t<std::is_integral<Underlying>::value>>
class SequentialEnum
{
    Underlying m_value;

  public:
    constexpr SequentialEnum() : m_value(0)
    {
    }

    constexpr SequentialEnum(Underlying value) : m_value(value)
    {
    }

    constexpr Underlying value() const
    {
        return m_value;
    }

    constexpr const SequentialEnum<Underlying> operator++()
    {
        m_value++;
        return m_value;
    }

    constexpr const SequentialEnum<Underlying> operator++(int)
    {
        auto value = m_value;
        m_value++;
        return value;
    }

    constexpr const SequentialEnum<Underlying> operator--()
    {
        m_value--;
        return m_value;
    }

    constexpr const SequentialEnum<Underlying> operator--(int)
    {
        auto value = m_value;
        m_value--;
        return value;
    }

    constexpr bool operator<(const SequentialEnum<Underlying> &other) const
    {
        return m_value < other.m_value;
    }

    constexpr bool operator<=(const SequentialEnum<Underlying> &other) const
    {
        return m_value <= other.m_value;
    }

    constexpr bool operator>(const SequentialEnum<Underlying> &other) const
    {
        return m_value > other.m_value;
    }

    constexpr bool operator>=(const SequentialEnum<Underlying> &other) const
    {
        return m_value >= other.m_value;
    }

    constexpr bool operator==(const SequentialEnum<Underlying> &other) const
    {
        return m_value == other.m_value;
    }

    constexpr bool operator!=(const SequentialEnum<Underlying> &other) const
    {
        return m_value != other.m_value;
    }

    constexpr SequentialEnum<Underlying> operator~() const
    {
        return ~m_value;
    }

    constexpr SequentialEnum<Underlying> operator&(
        const SequentialEnum<Underlying> &other) const
    {
        return m_value & other.m_value;
    }

    constexpr SequentialEnum<Underlying> operator|(
        const SequentialEnum<Underlying> &other) const
    {
        return m_value | other.m_value;
    }

    constexpr SequentialEnum<Underlying> operator^(
        const SequentialEnum<Underlying> &other) const
    {
        return m_value ^ other.m_value;
    }

    constexpr SequentialEnum<Underlying> &operator&=(
        const SequentialEnum<Underlying> &other)
    {
        m_value &= other.m_value;
        return *this;
    }
};
