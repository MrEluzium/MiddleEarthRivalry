#pragma once
#include <vector>

#include "../utils/Randomized.h"
#include "../units/BaseUnit.h"

class BaseArmy
{
public:
    std::vector<BaseUnit> m_infantry;
    std::vector<BaseUnit> m_cavalry;
};

