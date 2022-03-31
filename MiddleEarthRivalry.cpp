#include <iostream>
#include "BattleHandler/BattleHandler.h"

int main()
{
    int light_infantry_amount = 50, light_cavalry_amount = 50, darkness_infantry_amount = 50, darkness_cavalry_amount = 50;
    bool is_wizard_included = true, is_settings_complete = false;
    char feedback;

    while (!is_settings_complete)
    {
        std::cout << std::endl << "Current battle settings:" << std::endl;
        std::cout << std::endl << "Army of light:" << std::endl;
        std::cout << "Amount of infantry units (Human / Elf / Wooden elf) = " << light_infantry_amount << std::endl;
        std::cout << "Amount of cavalry units (Rohirrim / Wizard) = " << light_cavalry_amount << std::endl;
        std::cout << "Is wizard possible to be spawned = " << is_wizard_included << std::endl;
        std::cout << std::endl << "Army of darkness:" << std::endl;
        std::cout << "Amount of infantry units (Goblin / UrukHai / Troll) = " << darkness_infantry_amount << std::endl;
        std::cout << "Amount of cavalry units (Orc) = " << darkness_cavalry_amount << std::endl << std::endl;

        std::cout << "Do you want to change anything? (y/n) ";

        std::cin >> feedback;
        switch (feedback)
        {
        case 'y':
            std::cout << std::endl << "Which parameter do you want to change?" << std::endl;
            std::cout << "1: Is wizard included" << std::endl;
            std::cout << "2: Light infantry amount" << std::endl;
            std::cout << "3: Light cavalry amount" << std::endl;
            std::cout << "4: Darkness infantry amount" << std::endl;
            std::cout << "5: Darkness cavalry amount" << std::endl;
            std::cout << "0: Back" << std::endl;

            std::cin >> feedback;
            switch (feedback)
            {
            case '0': break;
            case '1':
                std::cout << (is_wizard_included ? "Now wizard can't be spawned" : "Now wizard can be spawned");
                is_wizard_included = !is_wizard_included;
                break;
            case '2':
                std::cout << "New amount of light army infantry units = ";
                std::cin >> light_infantry_amount;
                break;
            case '3':
                std::cout << "New amount of light army cavalry units = ";
                std::cin >> light_cavalry_amount;
                break;
            case '4':
                std::cout << "New amount of darkness army infantry units = ";
                std::cin >> darkness_infantry_amount;
                break;
            case '5':
                std::cout << "New amount of darkness army cavalry units = ";
                std::cin >> darkness_cavalry_amount;
                break;
            default:
                std::cout << "Please answer with the number of one of given options" << std::endl;
            }
            break;
        case 'n':
            is_settings_complete = true; break;
        default:
            std::cout << "Please, answer with 'y' or 'n' symbol" << std::endl;
        }
    }

    BattleHandler battle(is_wizard_included, light_infantry_amount, light_cavalry_amount, darkness_infantry_amount, darkness_cavalry_amount);

    std::cout << "Press any button to start the battle...";
    std::cin.ignore(); std::cin.get();

    battle.Execute();
    std::cin.get();
}
