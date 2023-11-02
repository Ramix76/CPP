/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:54:21 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/02 13:03:02 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::complaintLevelString[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl()
{
	complaintFunctions[0] = &Harl::complainDebug;
	complaintFunctions[1] = &Harl::complainInfo;
	complaintFunctions[2] = &Harl::complainWarning;
	complaintFunctions[3] = &Harl::complainError;
}

Harl::~Harl()
{
	return;
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "[ I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do! ]" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "[ I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! ]" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "[ I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month. ]" << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "[ This is unacceptable! I want to speak to the manager now. ]" << std::endl;
}

Harl::Level Harl::getLevelCode(std::string level)
{
	if (level == "DEBUG") return DEBUG;
	else if (level == "INFO") return INFO;
	else if (level == "WARNING") return WARNING;
	else if (level == "ERROR") return ERROR;
	return UNKNOW;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < numLevels; ++i)
	{
		if (level == complaintLevelString[i])
		{
			(this->*complaintFunctions[i])();
			return;
		}
	}
	std::cout << "Invalid complaint level: " << level << std::endl;
}

void Harl::complainDebug()
{
	debug();
}

void Harl::complainInfo()
{
	info();
}

void Harl::complainWarning()
{
	warning();
}

void Harl::complainError()
{
	error();
}
