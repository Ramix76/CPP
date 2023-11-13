/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:22:42 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/09 12:51:16 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called!" << std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called!" << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
	return ;
}

Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

Animal::Animal(Animal const &an)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = an;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
	return ;
}
