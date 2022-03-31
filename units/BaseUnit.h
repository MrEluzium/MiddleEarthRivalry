#pragma once
class BaseUnit
{
protected:
    int m_power;
    bool m_is_dead = false;
public:
    int GetPower() const { return m_power; }
    void DecrementPower(int dec_power);
    bool IsDead() const { return m_is_dead; }
};
