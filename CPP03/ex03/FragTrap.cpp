/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:23:08 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/07 12:33:14 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "FragTrap constructor called!" << std::endl;
	this->_name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &ftp)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this=ftp;
}

void	FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << _name << " request a high five! High five, anyone?" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	this->_name = other._name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void	FragTrap::attack(std::string const &target)
{
	if (energyPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << " , causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	return ;
}
