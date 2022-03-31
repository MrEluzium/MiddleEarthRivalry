#include <iostream>
#include <stdexcept>
#include "BattleHandler.h"
#include "../Utils/Randomized.h"
#include "../Armies/ArmyOfLight.h"
#include "../Armies/ArmyOfDarkness.h"
#include "../Units/BaseUnit.h"


void BattleHandler::Execute()
{
    int light_unit_index = 0, darkness_unit_index = 0;
    bool is_cavalry_done = false, is_infantry_done = false;
    BaseUnit *light_current_unit, *darkness_currnt_unit;

    std::cout << std::endl << "Starting battle for Meddle Earth!" << std::endl;
    
    while (!is_cavalry_done)
    {
        // Reset index count when hit the last unit in cavalry
        if (light_unit_index >= m_army_light.m_cavalry.size()) { light_unit_index = 0; }
        if (darkness_unit_index >= m_army_darkness.m_cavalry.size()) { darkness_unit_index = 0; }

        light_current_unit = &(m_army_light.m_cavalry[light_unit_index]);
        darkness_currnt_unit = &(m_army_darkness.m_cavalry[darkness_unit_index]);

        bool attack_order = Randomized::Get(0, 1);
        while (!light_current_unit->IsDead() && !darkness_currnt_unit->IsDead())
        {
            switch (attack_order)
            {
            case 0:
                light_current_unit->DecrementPower(darkness_currnt_unit->GetPower());
                break;
            case 1:
                darkness_currnt_unit->DecrementPower(light_current_unit->GetPower());
            }
            attack_order = !attack_order;
        }

        if (light_current_unit->IsDead())
        {
            m_army_light.m_cavalry.erase(m_army_light.m_cavalry.begin());
        }
        else if (darkness_currnt_unit->IsDead())
        {
            m_army_darkness.m_cavalry.erase(m_army_darkness.m_cavalry.begin());
        }
        else
        {
            throw std::runtime_error("No dead units found but duel is over");
        }

        if (!m_army_light.m_cavalry.size() || !m_army_darkness.m_cavalry.size()) { is_cavalry_done = true; }

    }

    light_unit_index = 0;
    darkness_unit_index = 0;
    while (!is_infantry_done)
    {
        // Reset index count when hit the last unit in cavalry
        if (light_unit_index >= m_army_light.m_infantry.size()) { light_unit_index = 0; }
        if (darkness_unit_index >= m_army_darkness.m_infantry.size()) { darkness_unit_index = 0; }

        light_current_unit = &(m_army_light.m_infantry[light_unit_index]);
        darkness_currnt_unit = &(m_army_darkness.m_infantry[darkness_unit_index]);

        bool attack_order = Randomized::Get(0, 1);
        while (!light_current_unit->IsDead() && !darkness_currnt_unit->IsDead())
        {
            switch (attack_order)
            {
            case 0:
                light_current_unit->DecrementPower(darkness_currnt_unit->GetPower());
                break;
            case 1:
                darkness_currnt_unit->DecrementPower(light_current_unit->GetPower());
            }
            attack_order = !attack_order;
        }

        if (light_current_unit->IsDead())
        {
            m_army_light.m_infantry.erase(m_army_light.m_infantry.begin());
        }
        else if (darkness_currnt_unit->IsDead())
        {
            m_army_darkness.m_infantry.erase(m_army_darkness.m_infantry.begin());
        }
        else
        {
            throw std::runtime_error("No dead units found but duel is over");
        }

        if (!m_army_light.m_infantry.size() || !m_army_darkness.m_infantry.size()) { is_infantry_done = true; }
    }

    int const light_total_last = m_army_light.m_infantry.size() + m_army_light.m_cavalry.size();
    int const darkness_total_last = m_army_darkness.m_infantry.size() + m_army_darkness.m_cavalry.size();
    if (light_total_last > darkness_total_last) { std::cout << "Army of light won!"; }
    else if (light_total_last < darkness_total_last) { std::cout << "Army of darkness won!"; }
    else { std::cout << "Draw!"; }
}
