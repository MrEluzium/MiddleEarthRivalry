#pragma once

#include "BaseUnit.h"
#include "../utils/Randomized.h"

class Troll : public BaseUnit
{
public:
    Troll(){ m_power = Randomized::Get(11, 15); }
};
