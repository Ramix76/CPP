/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:42:59 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/06 17:09:28 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
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

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints == 0 || energyPoints == 0)
		std::cout << "ScavTrap " << name << " can't attack " << target << " because of low hit points or energy points!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target << " , causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}
