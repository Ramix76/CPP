/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:40:14 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/06 17:09:13 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		//ScavTrap();
		ScavTrap(ScavTrap const &sct);
		ScavTrap(const std::string &name);
		ScavTrap &operator=(ScavTrap const &other);
		~ScavTrap();
		void	attack(const std::string &target);
		void	guardGate();

	private:
		ScavTrap();
};

#endif
