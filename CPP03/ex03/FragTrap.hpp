/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:21:11 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/08 10:35:28 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(FragTrap const &ftp);
		FragTrap(const std::string &name);
		FragTrap &operator=(FragTrap const &other);
		~FragTrap();
		void	highFiveGuys();
		void	attack(std::string const &target);

	protected:
		FragTrap();
};

#endif
