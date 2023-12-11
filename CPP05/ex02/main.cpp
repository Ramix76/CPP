/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:59:26 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/27 18:06:44 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <stdio.h>
#include <stdlib.h>

int	main( void )
{
	std::cout << std::endl << "1. Create a ShruberryCreationForm" << std::endl;
		try
		{
			ShrubberyCreationForm	test = ShrubberyCreationForm("Ferran");
			std::cout << test << std::endl<< std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "2. Sign a ShruberryCreationForm" << std::endl;
		try
		{
			ShrubberyCreationForm	test = ShrubberyCreationForm("Ferran");
			std::cout << test << std::endl<< std::endl;
			Bureaucrat	Ana = Bureaucrat("Ana", 20);
			std::cout << Ana << std::endl;
			
			Ana.signForm(test);
			std::cout << std::endl << test << std::endl << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "3. Try to sign a ShruberryCreationForm without clearence " << std::endl;
		try
		{
			ShrubberyCreationForm	test = ShrubberyCreationForm("Ferran");
			std::cout << test << std::endl<< std::endl;
			Bureaucrat	Ana = Bureaucrat("Ana", 150);
			std::cout << Ana << std::endl;

			Ana.signForm(test);
			std::cout << std::endl << test << std::endl << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "4. Try to execute ShruberryCreationForm that is not signed" << std::endl;
		try
		{
			ShrubberyCreationForm	test = ShrubberyCreationForm("Ferran");
			std::cout << test << std::endl<< std::endl;
			Bureaucrat	Ana = Bureaucrat("Ana", 150);
			std::cout << Ana << std::endl;
			
			Ana.executeForm(test);
			std::cout << std::endl;
			system("#/bin/bash \n cat Ferran_shrubbery"); 
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;
	
	std::cout << std::endl << "5. Try to execute signed ShruberryCreationForm without clearence" << std::endl;
		try
		{
			ShrubberyCreationForm	test = ShrubberyCreationForm("Ferran");
			std::cout << test << std::endl<< std::endl;
			Bureaucrat	Ana = Bureaucrat("Ana", 140);
			std::cout << Ana << std::endl;
			
			Ana.signForm(test);
			std::cout << std::endl;
			Ana.executeForm(test);
			std::cout << std::endl;
			system("#/bin/bash \n cat Ferran_shrubbery");
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;
	
	std::cout << std::endl << "6. Execute ShruberryCreationForm" << std::endl;
		try
		{
			ShrubberyCreationForm	test = ShrubberyCreationForm("Ferran");
			std::cout << test << std::endl<< std::endl;
			Bureaucrat	Ana = Bureaucrat("Ana", 10);
			std::cout << Ana << std::endl;
			
			Ana.signForm(test);
			std::cout << std::endl;
			Ana.executeForm(test);
			std::cout << std::endl;
			system("#/bin/bash \n cat Ferran_shrubbery");
			system("#/bin/bash \n rm Ferran_shrubbery"); 
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;
	
	std::cout << std::endl << "7. Execute RobotomyRequestForm" << std::endl;
		try
		{
			RobotomyRequestForm	test = RobotomyRequestForm("Ferran");
			std::cout << test << std::endl<< std::endl;
			Bureaucrat	Ana = Bureaucrat("Ana", 20);
			std::cout << Ana << std::endl;
			
			Ana.signForm(test);
			std::cout << std::endl;
			Ana.executeForm(test);
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;
	
	
	std::cout << std::endl << "8. Execute PresidentialPardonForm" << std::endl;
		try
		{
			PresidentialPardonForm	test = PresidentialPardonForm("Ferran");
			std::cout << test << std::endl<< std::endl;
			Bureaucrat	Ana = Bureaucrat("Ana", 3);
			std::cout << Ana << std::endl;
			
			Ana.signForm(test);
			std::cout << std::endl;
			Ana.executeForm(test);
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

}
