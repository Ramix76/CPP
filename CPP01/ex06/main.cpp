/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:06:09 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/02 12:59:28 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}

	std::string level = argv[1];
	Harl harl;

	switch (harl.getLevelCode(level))
	{
		case Harl::DEBUG:
			harl.complain("DEBUG");
		case Harl::INFO:
			harl.complain("INFO");
		case Harl::WARNING:
			harl.complain("WARNING");
		case Harl::ERROR:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << level << std::endl;
			break;
	}
	return (0);
}
