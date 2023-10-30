/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:14:01 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/30 12:51:41 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "weapon.hpp"
# include <string>

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(const std::string &humanName);
		~HumanB();
		void	setWeapon(Weapon &humanWeapon);
		void	attack();
};

#endif
