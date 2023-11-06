/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:26:25 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/06 17:04:25 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	clap("CL4V-TP");
	ScavTrap	scav("SC4V-TP");

	std ::cout << std::endl;

	std::cout << "ClapTrap: " << std::endl;
	clap.attack("Intruder");
	clap.takeDamage(30);
	clap.beRepaired(15);

	std ::cout << std::endl;

	std::cout << "ScavTrap: " << std::endl;
	scav.attack("Coopy of Intruder");
	scav.guardGate();
	scav.takeDamage(20);
	scav.beRepaired(10);

	std ::cout << std::endl;

	return (0);
}
