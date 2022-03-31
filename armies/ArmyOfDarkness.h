#pragma once
#include "BaseArmy.h"

class ArmyOfDarkness : public BaseArmy
{
public:
    ArmyOfDarkness() : ArmyOfDarkness(50, 50) { }
    ArmyOfDarkness(int infantry_amount, int cavalry_amount);
};