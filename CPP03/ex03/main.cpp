/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:26:25 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/07 19:14:48 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap	claptrap("CT-1");
	ScavTrap	scavtrap("SP-1");
	FragTrap	fragtrap("FT-1");
	DiamondTrap	diamondtrap("D1T-1");

	std::cout << std::endl;

	std::cout << "ClapTrap: " << std::endl;
	claptrap.attack("Target");
	claptrap.takeDamage(20);
	claptrap.beRepaired(10);

	std::cout << std::endl;

	std::cout << "ScavTrap :" << std::endl;
	scavtrap.attack("Intruder");
	scavtrap.guardGate();
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(15);

	std::cout << std::endl;

	std::cout << "FragTrap: " << std::endl;
	fragtrap.attack("Enemy");
	fragtrap.highFiveGuys();
	fragtrap.takeDamage(40);
	fragtrap.beRepaired(20);

	std::cout << std::endl;

	std::cout << "DiamondTrap: " << std::endl;
	diamondtrap.attack("Enemy");
	diamondtrap.highFiveGuys();
	diamondtrap.whoAmI();
	diamondtrap.guardGate();

	std::cout << std::endl;

	return (0);
}
