#pragma once

#include "BaseUnit.h"
#include "../utils/Randomized.h"

class Elf : public BaseUnit
{
public:
    Elf()
    {
        m_power = Randomized::Get(4, 7);
        m_type = Type::INFANTRY;
    }
};
