/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:10:58 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/14 10:37:51 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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
