#include <iostream>
#include "ArmyOfLight.h"
#include "../Utils/Randomized.h"
#include "../Units/Elf.h"
#include "../Units/WoodenElf.h"
#include "../Units/Human.h"
#include "../Units/Rohirrim.h"
#include "../Units/Wizard.h"

ArmyOfLight::ArmyOfLight(bool is_wizard_included, int infantry_amount, int cavalry_amount)
{
    std::cout << std::endl << "Generating army of light";
    std::cout << " | infantry amount: " << infantry_amount;
    std::cout << " | cavalry amount: " << cavalry_amount << (is_wizard_included ? " (including a possible wizard)" : "(excluding a possible wizard)") << std::endl;

    m_infantry.reserve(infantry_amount);
    m_cavalry.reserve(cavalry_amount);

    // Infantry generation
    while (m_infantry.size() < m_infantry.capacity())
    {
        switch (Randomized::Get(0, 2))
        {
        case 0: 
            m_infantry.emplace_back(Elf());
            std::cout << "Elf with " << m_infantry.back().GetPower() << " power" << std::endl;
            break;
        case 1: 
            m_infantry.emplace_back(WoodenElf());
            std::cout << "Wooden elf with " << m_infantry.back().GetPower() << " power" << std::endl;
            break;
        case 2: 
            m_infantry.emplace_back(Human());
            std::cout << "Human with " << m_infantry.back().GetPower() << " power" << std::endl;
        }
    }

    // Cavalry generation
    if (is_wizard_included && Randomized::Get(0, 1))
    {
        m_cavalry.emplace_back(Wizard());
        std::cout << "Wizard with " << m_cavalry.back().GetPower() << " power" << std::endl;
    }

    while (m_cavalry.size() < m_cavalry.capacity())
    {
        m_cavalry.emplace_back(Rohirrim());
        std::cout << "Rohirrim with " << m_cavalry.back().GetPower() << " power" << std::endl;
    }
}
