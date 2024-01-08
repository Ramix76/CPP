/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:54:40 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/08 12:29:36 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    //std::cout << "Serializer default constructr called!" << std::endl;
    return ;
}

Serializer::~Serializer()
{
    //std::cout << "Serializer destructor called!" << std::endl;
    return ;
}

Serializer::Serializer(Serializer const &serial)
{
    *this=serial;
    return ;
}

Serializer &Serializer::operator=(Serializer const &other)
{
    std::cout << "Assignation not allowed for PresidentialPardonForm's class" << std::endl;
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

