#pragma once

#include "BaseUnit.h"
#include "../utils/Randomized.h"

class UrukHai : public BaseUnit
{
public:
    UrukHai()
    {
        m_power = Randomized::Get(10, 12);
        m_type = Type::INFANTRY;
    }
};
