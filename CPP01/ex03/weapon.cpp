/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:03:32 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/30 12:51:47 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon(std::string weaponType) : _type(weaponType) {}

Weapon::~Weapon()
{
	return;
}

const std::string &Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}
