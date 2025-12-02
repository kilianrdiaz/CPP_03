#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap a("Clappy");
    a.attack("target1");
    a.beRepaired(5);
    a.takeDamage(8);
    a.attack("target2");
    a.takeDamage(20);
    a.beRepaired(3);

    ClapTrap b = a;
    b.attack("target3");

    ClapTrap c("Clumpy");
    c = a;
    c.attack("target4");

    return 0;
}
