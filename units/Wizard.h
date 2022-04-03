#pragma once

#include "BaseUnit.h"
#include "../utils/Randomized.h"

class Wizard : public BaseUnit
{
public:
    Wizard()
    {
        m_power = Randomized::Get(24, 25);
        m_type = Type::CAVALRY;
    }
};
