/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:58:37 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/14 10:36:02 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(std::string type);
		AAnimal &operator=(AAnimal const &other);
		AAnimal(AAnimal const &an);

		std::string		getType() const;
		virtual void	makeSound() const = 0;
	
	protected:
		std::string _type;
};

#endif
