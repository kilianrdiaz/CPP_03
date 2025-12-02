#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
    : ClapTrap("Default_ScavTrap")
{
    this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage= 20;
    std::cout << "ScavTrap " << getName() << " constructed with default name" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage= 20;
    std::cout << "ScavTrap " << getName() << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap " << getName() << " copy-constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << getName() << " assigned" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " destructed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (getHitPoints() == 0) {
        std::cout << "ScavTrap " << getName() << " can't attack, it has no hit points left." << std::endl;
        return;
    }
    if (getEnergyPoints() == 0) {
        std::cout << "ScavTrap " << getName() << " can't attack, it has no energy points left." << std::endl;
        return;
    }
    --this->_energyPoints;
    std::cout << "ScavTrap " << getName() << " ruthlessly attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!" 
              << "(EP left: " << _energyPoints << ")" << std::endl;
}

void ScavTrap::guardGate()
{
    if (getHitPoints() == 0) {
        std::cout << "ScavTrap " << getName() << " can't enter guard mode, it has no hit points left." << std::endl;
        return;
    }
    if (getEnergyPoints() == 0) {
        std::cout << "ScavTrap " << getName() << " can't enter guard mode, it has no energy points left." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << getName() << " is now guarding the gate." << std::endl;
}
