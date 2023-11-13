/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:51:42 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/13 12:11:02 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat default constructor called!" << std::endl;
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete _brain;
	return ;
}

Cat::Cat(Cat const &cat) : Animal(cat), _brain(new Brain(*cat._brain))
{
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = cat;
}

Cat	&Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "Does not make sense to call assigment overload; All Cats are initialized with type Cat" << std::endl;
	}
	return (*this);
}

Brain &Cat::getBrain() const
{
	return (*this->_brain);
}

void	Cat::makeSound() const
{
	std::cout << "Meowwww!!, i'm a cat!" << std::endl;
	return ;
}
