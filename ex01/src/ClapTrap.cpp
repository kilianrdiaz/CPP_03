#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructed (HP: " << _hitPoints
              << ", EP: " << _energyPoints << ", AD: " << _attackDamage << ")" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructed (HP: " << _hitPoints
              << ", EP: " << _energyPoints << ", AD: " << _attackDamage << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << name << " copy-constructed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other) {
        this->name = other.name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack, it has no hit points left." << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack, it has no energy points left." << std::endl;
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage! (EP left: " << _energyPoints << ")"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already at 0 HP." << std::endl;
        return;
    }
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage! (HP: " << _hitPoints << ")"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << name << " can't be repaired, it has 0 HP." << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't be repaired, it has no energy points." << std::endl;
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount
              << " points! (HP: " << _hitPoints << ", EP: " << _energyPoints << ")" << std::endl;
}

// getters
const std::string& ClapTrap::getName() const { return name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }
