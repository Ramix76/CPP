/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:50:41 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/14 10:43:35 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define N 4

int	main( void )
{
	AAnimal ** animals = new AAnimal*[N];
	int	i;

	i = -1;
	while (++i < (N/2))
		animals[i] = new Dog();
	while (i < N )
		animals[i++] = new Cat();
	
	std::cout << std::endl;
	
	while(--i >= 0)
		delete animals[i];
	delete [] animals;

	// AAnimal hello;		//If uncommented should not compile
	return (0);
}
