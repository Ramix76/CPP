/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:23:08 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/04 11:27:40 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed!" << std::endl;
}

void	FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << name << " request a high five! High five, anyone?" << std::endl;
}
