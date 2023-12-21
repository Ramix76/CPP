/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:59:26 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 13:19:12 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <stdio.h>
#include <stdlib.h>

int	main( void )
{
	std::cout << std::endl << "1. Intern creates a shrubbery creation form" << std::endl;
		try
		{
			Intern	Ana;
			AForm *	form;
			form = Ana.makeForm("ShrubberyCreationForm", "Pedro");
			std::cout << *form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "2. Intern creates a robotomy request" << std::endl;
		try
		{
			Intern	Ana;
			AForm *	form;

			form = Ana.makeForm("RobotomyRequestForm", "Pedro");
			std::cout << *form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "3. Intern creates a presidential pardon form" << std::endl;
		try
		{
			Intern	Ana;
			AForm *	form;

			form = Ana.makeForm("PresidentialPardonForm", "Pedro");
			std::cout << *form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "4. Intern intents to create an invalid form" << std::endl;
		try
		{
			Intern	Ana;
			AForm *	form;

			form = Ana.makeForm("hgello", "Pedro");
			std::cout << "Should be NULL: " << form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;
	return (0);
}