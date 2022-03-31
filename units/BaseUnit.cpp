#include "BaseUnit.h"

void BaseUnit::DecrementPower(int dec_power)
{
    m_power -= dec_power;
    if (m_power <= 0){ m_is_dead = true; }
}
