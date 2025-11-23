#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
    : ClapTrap("Default_FragTrap")
{
    std::cout << "FragTrap " << getName() << " constructed with default name" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    std::cout << "FragTrap " << getName() << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap " << getName() << " copy-constructed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << getName() << " assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " destructed" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (getHitPoints() == 0) {
        std::cout << "FragTrap " << getName() << " can't attack, it has no hit points left." << std::endl;
        return;
    }
    if (getEnergyPoints() == 0) {
        std::cout << "FragTrap " << getName() << " can't attack, it has no energy points left." << std::endl;
        return;
    }
    std::cout << "FragTrap " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
    // decrement energy etc (see note sobre acceso a miembros)
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << getName() << " requests a positive high five! ✋" << std::endl;
}
