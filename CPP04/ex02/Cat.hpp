/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:07:59 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/14 10:38:37 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		~Cat();
		Cat &operator=(Cat const &other);
		Cat(Cat const &cat);

		Brain			&getBrain() const;
		virtual void	makeSound() const;

	private:
		Brain *_brain;
};

#endif
