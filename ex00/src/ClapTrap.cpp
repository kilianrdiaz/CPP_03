#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructed (HP: " << hitPoints
              << ", EP: " << energyPoints << ", AD: " << attackDamage << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints),
      energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << name << " copy-constructed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
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
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack, it has no hit points left." << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack, it has no energy points left." << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage! (EP left: " << energyPoints << ")"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already at 0 HP." << std::endl;
        return;
    }
    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage! (HP: " << hitPoints << ")"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " can't be repaired, it has 0 HP." << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't be repaired, it has no energy points." << std::endl;
        return;
    }
    --energyPoints;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount
              << " points! (HP: " << hitPoints << ", EP: " << energyPoints << ")" << std::endl;
}

// getters
const std::string& ClapTrap::getName() const { return name; }
unsigned int ClapTrap::getHitPoints() const { return hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return attackDamage; }
