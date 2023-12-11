/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:46:40 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/11 12:10:46 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &dp)

{
	std::cout << "DiamoondTrap copy construictor called!" << std::endl;
	*this=dp;
}

DiamondTrap::DiamondTrap(std::string name) 
{
	std::cout << "DiamondTrap constructor called!" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	this->_name = other._name;
	this->ClapTrap::_name = other._name + "_clap_name";
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;

	return (*this);
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
