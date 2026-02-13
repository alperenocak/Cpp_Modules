#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{   
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)
    {
        this->_attackDamage = other._attackDamage;
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
    }
    return(*this);   
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout<<"ClapTrap " << _name << " is born" << std::endl; 
}

void ClapTrap::attack(const std::string &target)
{
    
}
