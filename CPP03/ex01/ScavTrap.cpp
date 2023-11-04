/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:42:59 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/04 11:01:43 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
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
