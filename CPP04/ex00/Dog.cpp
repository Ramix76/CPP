/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:14:37 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/10 18:15:02 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default consstructor called!" << std::endl;
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &other)
{
	( void ) other;
	std::cout << "Does not make sense to call assigment overload; All Dogs are initialized with type Dog" << std::endl;
	return (*this);}

Dog::Dog(Dog const &dog)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = dog;
}

void	Dog::makeSound() const
{
	std::cout << "BUF BUF BUF!!, i'm a dog!" << std::endl;
	return ;
}
