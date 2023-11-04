/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:26:25 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/04 11:31:47 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	claptrap("CT-1");
	claptrap.attack("Target");
	claptrap.takeDamage(20);
	claptrap.beRepaired(10);

	ScavTrap	scavtrap("SP-1");

	scavtrap.attack("Intruder");
	scavtrap.guardGate();
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(15);

	FragTrap	fragtrap("FT-1");
	fragtrap.attack("Enemy");
	fragtrap.highFiveGuys();
	fragtrap.takeDamage(40);
	fragtrap.beRepaired(20);

	return (0);
}
