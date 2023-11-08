/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:40:14 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/08 10:35:34 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(ScavTrap const &sct);
		ScavTrap(const std::string &name);
		ScavTrap &operator=(ScavTrap const &other);
		~ScavTrap();
		void	attack(const std::string &target);
		void	guardGate();

	protected:
		ScavTrap(void);
};

#endif
