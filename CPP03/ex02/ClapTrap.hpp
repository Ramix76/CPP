/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:58:47 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/06 17:51:34 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		//ClapTrap();
		ClapTrap(ClapTrap const &cp);
		ClapTrap(const std::string &name);
		ClapTrap &operator=(ClapTrap const &other);
		~ClapTrap();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string _name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
		ClapTrap(void);

		static const unsigned int defaultHitPoints  = 10;
		static const unsigned int defaultEnergyPoints = 10;
		static const unsigned int defaultAttackDamage = 0;
};

#endif
