/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:42:59 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/06 17:52:23 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &sct) : ClapTrap(sct)
{
	std::cout << "Copy ScavTrap constructor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap copy assigment operator called!" << std::endl;
	}
	return (*this);
}

ScavTrap::ScavTrap(const std::string &name)
{
	this->_name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints == 0 || energyPoints == 0)
		std::cout << "ScavTrap " << _name << " can't attack " << target << " because of low hit points or energy points!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " , causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode!" << std::endl;
}
