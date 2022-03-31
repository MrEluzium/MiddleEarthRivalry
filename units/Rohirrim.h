#pragma once

#include "BaseUnit.h"
#include "../utils/Randomized.h"

class Rohirrim : public BaseUnit
{
public:
    Rohirrim(){ m_power = Randomized::Get(11, 13); }
};
