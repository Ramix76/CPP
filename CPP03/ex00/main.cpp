/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:26:25 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/06 12:48:16 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	claptrap("CL4P-TP");
	ClapTrap	claptrap2(claptrap);

	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap2.takeDamage(20);

	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	claptrap.attack("CL4P-TP2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);

	return (0);
}
