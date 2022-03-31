#pragma once
#include "../Armies/ArmyOfLight.h"
#include "../Armies/ArmyOfDarkness.h"

class BattleHandler
{
private:
    ArmyOfLight m_army_light;
    ArmyOfDarkness m_army_darkness;
public:
    BattleHandler(bool is_wizard_included, int light_infantry_amount, int light_cavalry_amount, int darkness_infantry_amount, int darkness_cavalry_amount) : m_army_light(ArmyOfLight(is_wizard_included, light_infantry_amount, light_cavalry_amount)), m_army_darkness(ArmyOfDarkness(darkness_infantry_amount, darkness_cavalry_amount)) { }
    void Execute();
};
