/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:17:36 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/30 12:52:14 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &humanName) : _name(humanName), _weapon(nullptr) {}

void	HumanB::setWeapon(Weapon &humanWeapon)
{
	_weapon = &humanWeapon;
}

HumanB::~HumanB()
{
	return;
}

void	HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << " is unarmed and cannot attack." << std::endl;
	else
		std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
}
