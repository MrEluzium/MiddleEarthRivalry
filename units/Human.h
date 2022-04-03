#pragma once

#include "BaseUnit.h"
#include "../utils/Randomized.h"

class Human : public BaseUnit
{
public:
    Human()
    {
        m_power = Randomized::Get(7, 8);
        m_type = Type::INFANTRY;
    }
};
