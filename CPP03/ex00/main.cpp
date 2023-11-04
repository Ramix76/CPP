/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:26:25 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/04 10:28:54 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	claptrap("CL4P-TP");

	claptrap.attack("Enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(20);

	return (0);
}
