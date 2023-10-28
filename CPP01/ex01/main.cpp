/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:30:35 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/28 13:11:52 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int numZombies = 5;
	Zombie* horde;
	horde = zombieHorde(numZombies, "Hungry");
	
	for (int i = 0; i < numZombies; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
