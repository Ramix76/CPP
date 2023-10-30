/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:10:22 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/30 12:52:39 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanA.hpp"
#include <iostream>

HumanA::HumanA(std::string humanName, Weapon &humanWeapon)
	: _name(humanName), _weapon(humanWeapon) {}

HumanA::~HumanA()
{
	return;
}

void	HumanA::setWeapon(Weapon weapon)
{
	_weapon = weapon;
}

void	HumanA::attack()
{
	std::cout << _name << " attack with their " << _weapon.getType() << std::endl;
}
