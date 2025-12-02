#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ScavTrap s("Scavy");

    s.attack("a dummy");
    s.guardGate();
    s.takeDamage(30);
    s.beRepaired(10);

    ScavTrap s2 = s;

    s2.attack("another dummy");
    return 0;
}
