/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:37:49 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/13 12:06:28 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(Brain const &br);
		Brain &operator=(Brain const &other);

		std::string	getIdeas(int i) const;
		void		setIdeas(int i, std::string idea);

	private:
		std::string _ideas[100];
};

#endif
