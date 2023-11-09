/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:10:58 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/08 16:15:03 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	Dog();
	~Dog();
	Dog &operator=(Dog const &other);
	Dog(Dog const &dog);

	virtual void makeSound() const;
};

#endif
