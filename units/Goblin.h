#pragma once

#include "BaseUnit.h"
#include "../utils/Randomized.h"

class Goblin : public BaseUnit
{
public:
    Goblin()
    {
        m_power = Randomized::Get(2, 5);
        m_type = Type::INFANTRY;
    }
};
