/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:59:53 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/04 11:12:14 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (hitPoints == 0 || energyPoints == 0)
		std::cout << "ClapTrap " << name << " can't attack " << target << " because of low hit points or energy points!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " can't take more damage because it has no hit points left!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		hitPoints -= amount;
		if (hitPoints < 0)
			hitPoints = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " can't be repaired because it is destroyed!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
		hitPoints += amount;
		if (hitPoints > 100)
			hitPoints = 100;
	}
}
