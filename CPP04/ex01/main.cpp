/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:50:41 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/13 12:13:22 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define N 4

int	main( void )
{
	Animal ** animals = new Animal*[N]; 
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

	std::cout << std::endl << std::endl;
	Dog *	dog1 = new Dog();
	dog1->getBrain().setIdeas( 0 , "Dog2 was created with this value");

	Dog	*	dog2 = new Dog(*dog1);
	std::cout << std::endl;

	std::cout << "Deep copy: ";
	dog1->getBrain().setIdeas( 0 , "Dog1 is the only that is changed");
	if (!(dog2->getBrain().getIdeas(0)).compare("Dog2 was created with this value"))
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	std::cout << std::endl;

	std::cout << "Protected string: " << std::endl;
		dog1->getBrain().setIdeas(200 , "Dog2 was created with this value");
		dog1->getBrain().getIdeas(200);

	delete dog1;
	delete dog2;
	return (0);	
}
