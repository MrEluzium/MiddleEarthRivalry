#include <iostream>
#include "ArmyOfDarkness.h"
#include "../Utils/Randomized.h"
#include "../Units/Goblin.h"
#include "../Units/UrukHai.h"
#include "../Units/Troll.h"
#include "../Units/Orc.h"

ArmyOfDarkness::ArmyOfDarkness(int infantry_amount, int cavalry_amount)
{
    std::cout << std::endl << "Generating army of darkness";
    std::cout << " | infantry amount: " << infantry_amount;
    std::cout << " | cavalry amount: " << cavalry_amount << std::endl;
    m_infantry.reserve(infantry_amount);
    m_cavalry.reserve(cavalry_amount);

    // Infantry generation
    while (m_infantry.size() < m_infantry.capacity())
    {
        switch (Randomized::Get(0, 2))
        {
        case 0: 
            m_infantry.emplace_back(Goblin());
            std::cout << "Goblin with " << m_infantry.back().GetPower() << " power" << std::endl;
            break;
        case 1: 
            m_infantry.emplace_back(UrukHai());
            std::cout << "UrukHai with " << m_infantry.back().GetPower() << " power" << std::endl;
            break;
        case 2: 
            m_infantry.emplace_back(Troll());
            std::cout << "Troll with " << m_infantry.back().GetPower() << " power" << std::endl;
        }
    }

    // Cavalry generation
    while (m_cavalry.size() < m_cavalry.capacity())
    {
        m_cavalry.emplace_back(Orc());
        std::cout << "Orc with " << m_cavalry.back().GetPower() << " power" << std::endl;
    }
}
