#pragma once

enum class Type
{
    CAVALRY,
    INFANTRY
};

class BaseUnit
{
protected:
    int m_power;
    bool m_is_dead = false;
    Type m_type;
public:
    int GetPower() const { return m_power; }
    bool IsDead() const { return m_is_dead; }
    Type GetType() const { return m_type; }

    void DecrementPower(int dec_power);
};
