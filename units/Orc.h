#pragma once

#include "BaseUnit.h"
#include "../utils/Randomized.h"

class Orc : public BaseUnit
{
public:
    Orc()
    {
        m_power = Randomized::Get(8, 10);
        m_type = Type::CAVALRY;
    }
};
