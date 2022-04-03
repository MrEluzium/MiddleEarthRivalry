#include <iostream>
#include <stdexcept>
#include "BattleHandler.h"
#include "../Utils/Randomized.h"
#include "../Armies/ArmyOfLight.h"
#include "../Armies/ArmyOfDarkness.h"
#include "../Units/BaseUnit.h"

enum class Stage
{
    CAVALRY_DUEL,
    INFANTRY_DUEL,
    MIXED_DUEL
};

template <typename T>
void move_item_back(std::vector<T>& v, size_t itemIndex)
{
    auto it = v.begin() + itemIndex;
    std::rotate(it, it + 1, v.end());
}

void BattleHandler::ProcessStage(Stage current_stage)
{
    bool is_stage_done = false;
    std::vector<BaseUnit> *p_light_current_squad, *p_darkness_current_squad;

    if (current_stage == Stage::CAVALRY_DUEL)
    {
        p_light_current_squad = &m_army_light.m_cavalry;
        p_darkness_current_squad = &m_army_darkness.m_cavalry;
    } else if (current_stage == Stage::INFANTRY_DUEL)
    {
        p_light_current_squad = &m_army_light.m_infantry;
        p_darkness_current_squad = &m_army_darkness.m_infantry;
    } else
    {
        // Using infantry vector as temporary to create mixed squad
        m_army_light.m_infantry.reserve(m_army_light.m_infantry.size() + m_army_light.m_cavalry.size());
        m_army_darkness.m_infantry.reserve(m_army_darkness.m_infantry.size() + m_army_darkness.m_cavalry.size());

        m_army_light.m_infantry.insert(m_army_light.m_infantry.end(), m_army_light.m_cavalry.begin(), m_army_light.m_cavalry.end());
        m_army_darkness.m_infantry.insert(m_army_darkness.m_infantry.end(), m_army_darkness.m_cavalry.begin(), m_army_darkness.m_cavalry.end());

        p_light_current_squad = &m_army_light.m_infantry;
        p_darkness_current_squad = &m_army_darkness.m_infantry;
    }

    while (!is_stage_done)
    {
        BaseUnit* p_light_current_unit = &((*p_light_current_squad)[0]);
        BaseUnit* p_darkness_current_unit = &((*p_darkness_current_squad)[0]);


        bool is_darkness_first_strike = Randomized::Get(0, 1);
        if (current_stage == Stage::MIXED_DUEL)
        {
            // In third stage cavalry have priority over infantry in attack order

            if (p_light_current_unit->GetType() == Type::CAVALRY && p_darkness_current_unit->GetType() == Type::INFANTRY)
                is_darkness_first_strike = false;
            else if (p_light_current_unit->GetType() == Type::INFANTRY && p_darkness_current_unit->GetType() == Type::CAVALRY)
                is_darkness_first_strike = true;
        }

        while (!p_light_current_unit->IsDead() && !p_darkness_current_unit->IsDead())
        {
            if (is_darkness_first_strike)
                p_light_current_unit->DecrementPower(p_darkness_current_unit->GetPower());
            else 
                p_darkness_current_unit->DecrementPower(p_light_current_unit->GetPower());
            is_darkness_first_strike = !is_darkness_first_strike;
        }

        if (p_light_current_unit->IsDead())
        {
            (*p_light_current_squad).erase((*p_light_current_squad).begin());
            move_item_back((*p_darkness_current_squad), 0);
        } else if (p_darkness_current_unit->IsDead())
        {
            (*p_darkness_current_squad).erase((*p_darkness_current_squad).begin());
            move_item_back((*p_light_current_squad), 0);
        } else throw std::runtime_error("No dead units found but duel is over");

        if ((*p_light_current_squad).empty() || (*p_darkness_current_squad).empty()) { is_stage_done = true; }
    }
}


void BattleHandler::Execute()
{
    std::cout << std::endl << "Starting battle for Meddle Earth!" << std::endl;

    ProcessStage(Stage::CAVALRY_DUEL);
    ProcessStage(Stage::INFANTRY_DUEL);

    if (m_army_light.m_infantry.size() + m_army_light.m_cavalry.size() && m_army_darkness.m_infantry.size() + m_army_darkness.m_cavalry.size())
        ProcessStage(Stage::MIXED_DUEL);

    unsigned long long const light_total_last = m_army_light.m_infantry.size() + m_army_light.m_cavalry.size();
    unsigned long long const darkness_total_last = m_army_darkness.m_infantry.size() + m_army_darkness.m_cavalry.size();

    if (light_total_last > darkness_total_last)
        std::cout << "Army of light won!" << std::endl;
    else if (light_total_last < darkness_total_last)
        std::cout << "Army of darkness won!" << std::endl;
    else
        std::cout << "Draw! (?)" << std::endl;

    std::cout << "Light units last: " << light_total_last << std::endl;
    std::cout << "Darkness units last: " << darkness_total_last << std::endl;

}
