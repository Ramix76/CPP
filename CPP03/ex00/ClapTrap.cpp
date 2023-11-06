/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:59:53 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/06 12:48:20 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("CL4P-TP") , hitPoints(defaultHitPoints), energyPoints(defaultEnergyPoints), attackDamage(defaultAttackDamage)
{
	std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(defaultHitPoints), energyPoints(defaultEnergyPoints), attackDamage(defaultAttackDamage)
{
	std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cp) : name(cp.name), hitPoints(cp.hitPoints), energyPoints(cp.energyPoints), attackDamage(cp.attackDamage)
{
	std::cout << "Copy ClapTrap constructor called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called!" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap  const &other)
{
	std::cout << "ClapTrap Copy assigment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " can't attack " << target << " because of low energy points!" << std::endl;
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
		hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		if (hitPoints == 0)
			std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " can't be repaired because it is destroyed!" << std::endl;
	else
	{
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
	}
}
