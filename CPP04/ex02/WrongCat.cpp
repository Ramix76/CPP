/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:48:26 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/10 19:02:33 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Dog")
{
	std::cout << "WrongCat default constructor called!" << std::endl;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
	return ;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	(void) other;
	std::cout << "Does not make sense to call assigment overload; All WrongCats are initialized with type WrongCat" << std::endl;
	return (*this);
}

WrongCat::WrongCat(WrongCat const &wrca)
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
	*this = wrca;
}

void	WrongCat::makeSound() const
{
	std::cout << "BUFF BUFF!! I'm not a cat,i'm a fucking dog!!" << std::endl;
	return ;
}
