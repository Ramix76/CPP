/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:40:39 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/13 12:06:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called!" << std::endl;
	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destrucotr called!" << std::endl;
	return;
}

Brain::Brain(Brain const &br)
{
	std::cout << "Brain copy constructor called!" << std::endl;
	*this = br;
	return;
}

Brain &Brain::operator=(Brain const &other)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other.getIdeas(i);
	return (*this);
}

std::string	Brain::getIdeas(int i) const
{
	if (i < 0 || i > 99)
	{
		std::cout << i << " is not a valid number!!" << std::endl;
		return ("");
	}
	return (_ideas[i]);
}

void	Brain::setIdeas(int i, std::string idea)
{
	if (i < 0 || i > 99)
	{
		std::cout << "Out-of-bounds index!" << std::endl;
		return ;
	}
	_ideas[i] = idea;
	return ;
}
