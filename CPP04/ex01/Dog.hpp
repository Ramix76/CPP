/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:10:58 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/13 12:11:04 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog &operator=(Dog const &other);
		Dog(Dog const &dog);

		Brain			&getBrain() const;
		virtual void	makeSound() const;

	private:
		Brain *_brain;
};

#endif
