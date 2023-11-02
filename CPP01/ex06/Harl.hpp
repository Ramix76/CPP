/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:50:59 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/02 13:02:50 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <map>
# include <functional>
# include <iostream>

class Harl
{
	public:
		enum Level { DEBUG, INFO, WARNING, ERROR, UNKNOW };
		
		Harl();
		~Harl();
		void	complain(std::string level);
		Level getLevelCode(std::string level);

	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

		void	complainDebug();
		void	complainInfo();
		void	complainWarning();
		void	complainError();

		typedef void (Harl::*ComplainFunc)();

		static const int numLevels = 4;
		static const std::string complaintLevelString[numLevels];
		ComplainFunc complaintFunctions[numLevels];
};

#endif
