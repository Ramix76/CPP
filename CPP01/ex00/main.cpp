/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:36:20 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/28 12:08:19 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie* zombie1 = newZombie("Zombie1");
	zombie1->announce();
	randomChump("Zombie2");
	delete zombie1;
	return (0);
}
