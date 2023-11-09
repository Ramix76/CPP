/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:58:37 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/09 12:51:25 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(std::string type);
		Animal &operator=(Animal const &other);
		Animal(Animal const &an);

		std::string		getType() const;
		virtual void	makeSound() const;
	
	protected:
		std::string _type;
};

#endif
