#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap f("Fraggi");
    f.attack("robot");
    f.highFivesGuys();
    f.takeDamage(50);
    f.beRepaired(20);
    
    FragTrap f2 = f;
    f2.attack("robot2");
    return 0;
}
