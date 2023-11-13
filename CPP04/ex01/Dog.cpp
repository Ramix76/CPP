/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:14:37 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/13 12:10:24 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain)
{
	std::cout << "Dog default consstructor called!" << std::endl;
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete _brain;
	return ;
}

Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "Does not make sense to call assigment overload; All Dogs are initialized with type Dog" << std::endl;
	}
	return (*this);}

Dog::Dog(Dog const &dog) : Animal(dog), _brain(new Brain(*dog._brain))
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = dog;
}

Brain &Dog::getBrain() const
{
	return (*this->_brain);
}

void	Dog::makeSound() const
{
	std::cout << "BUF BUF BUF!!, i'm a dog!" << std::endl;
	return ;
}
