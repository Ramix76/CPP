/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:26:25 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/04 11:03:13 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	scavtrap("S4V-TP");

	scavtrap.attack("Intruder");
	scavtrap.guardGate();
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(15);

	return (0);
}
