#pragma once
#include "BaseArmy.h"

class ArmyOfLight : public BaseArmy
{
public:
    ArmyOfLight() : ArmyOfLight(true, 50, 50) { }
    ArmyOfLight(bool is_wizard_included) : ArmyOfLight(is_wizard_included, 50, 50) { }
    ArmyOfLight(bool is_wizard_included, int infantry_amount, int cavalry_amount);
};
