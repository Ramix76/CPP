/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:22:42 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/14 10:37:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called!" << std::endl;
	return ;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal constructor called!" << std::endl;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called!" << std::endl;
	return ;
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

AAnimal::AAnimal(AAnimal const &an)
{
	std::cout << "AAnimal copy constructor called!" << std::endl;
	*this = an;
}

std::string AAnimal::getType() const
{
	return (this->_type);
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << std::endl;
	return ;
}
