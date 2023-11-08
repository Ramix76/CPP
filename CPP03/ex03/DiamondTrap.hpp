/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:38:28 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/08 10:35:22 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &dt);
		DiamondTrap &operator=(DiamondTrap const &other);
		~DiamondTrap();
		void	attack(std::string const &target);
		void	whoAmI();

	private:
		std::string _name;
		DiamondTrap();
};

#endif
