/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:59:26 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/20 12:28:02 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        std::cout << "1. Try to create a form with Grade required to sign of 0" << std::endl;
        Form form1("Form1", 0, 20);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    try {
        std::cout << "2. Try to create a Bureaucrat a form with Grade required to sign of 151" << std::endl;
        Form form2("Form2", 151, 20);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    try {
        std::cout << "3. Try to create a Bureaucrat a form with Grade required to execute of 0" << std::endl;
        Form form3("Form3", 20, 0);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    try {
        std::cout << "4. Try to create a Bureaucrat a form with Grade required to execute of 151" << std::endl;
        Form form4("Form4", 20, 151);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    try {
        std::cout << "5. Creating a copy of a Form" << std::endl;
        Form form5("Ana", 20, 20);
        Form form6(form5);
        std::cout << "<-------------  SRC  ------------->" << std::endl;
        std::cout << form5 << std::endl;
        std::cout << "<------------- COPY -------------->" << std::endl;
        std::cout << form6;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    try {
        std::cout << "6. Assignation of a Form" << std::endl;
        Form form7("Form1", 20, 20);
        Form form8("Form2", 30, 30);
        form7 = form8;
        std::cout << "<------------- Form1 --------------->" << std::endl;
        std::cout << form7 << std::endl;
        std::cout << "<-----Form2 should be different----->" << std::endl;
        std::cout << form8;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    try {
        std::cout << "7. Sign a Form without authorization" << std::endl;
        Form form9("Form1", 20, 20);
        Bureaucrat ana("Ana", 35);

        std::cout << form9 << std::endl << std::endl << ana << std::endl << std::endl;

        ana.signForm(form9);
        std::cout << form9;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    try {
        std::cout << "8. Sign a Form" << std::endl;
        Form form10("Form1", 19, 19);
        Bureaucrat ana("Ana", 19);

        std::cout << form10 << std::endl << std::endl << ana << std::endl << std::endl;

        ana.signForm(form10);
        std::cout << form10;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    try {
        std::cout << "9. Try to sign a Form already signed" << std::endl;
        Form form11("Form1", 19, 19);
        Bureaucrat ana("Ana", 19);

        ana.signForm(form11);
        std::cout << form11 << std::endl << std::endl << ana << std::endl << std::endl;
        ana.signForm(form11);
        std::cout << form11;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

    return 0;
}

/*
int	main( void )
{
	std::cout << std::endl << "1. Try to create a form with Grade required to sign of 0" << std::endl;
		try
		{
			Form	test = Form("Ana", 0, 20);
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "2. Try to create a Bureaucrat a form with Grade required to sign of 151" << std::endl;
		try
		{
			Form	test = Form("Ana", 151, 20);
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "3. Try to create a Bureaucrat a form with Grade required to execute of 0" << std::endl;
		try
		{
			Form	test = Form("Ana", 20, 0);
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "4. Try to create a Bureaucrat a form with Grade required to execute of 151" << std::endl;
		try
		{
			Form	test = Form("Ana", 20, 151);
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "5. Creating a copy of a Form " << std::endl;
		try
		{
			Form	test = Form("Ana", 20, 20);
			Form	test1 = Form(test);
			std::cout << "<-------------  SRC  ------------->" << std::endl;
			std::cout << test << std::endl;
			std::cout << "<------------- COPY -------------->" << std::endl;
			std::cout << test1;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "6. Assignation of a Form" << std::endl;
		try
		{
			Form	test = Form("Form1", 20, 20);
			Form	test1 = Form("Form2", 30, 30);
			test = test1;
			std::cout << "<------------- Form1 --------------->" << std::endl;
			std::cout << test << std::endl;
			std::cout << "<-----Form2 should be different----->" << std::endl;
			std::cout << test1;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "7. Sign a Form without authorization" << std::endl;
		try
		{
			Form			test = Form("Form1", 20, 20);
			Bureaucrat		ana = Bureaucrat("Ana", 35);
			std::cout << test << std::endl << std::endl << ana << std::endl << std::endl;

			ana.signForm(test);
			std::cout << test;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "8. Sign a Form" << std::endl;
		try
		{
			Form			test = Form("Form1", 19, 19);
			Bureaucrat		ana = Bureaucrat("Ana", 19);
				
			std::cout << test << std::endl << std::endl << ana << std::endl << std::endl;

			ana.signForm(test);
			std::cout << test;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "9. Try to sign a Form already signed" << std::endl;
		try
		{
			Form			test = Form("Form1", 19, 19);
			Bureaucrat		ana = Bureaucrat("Ana", 19);
				
			ana.signForm(test);
			std::cout << test << std::endl << std::endl << ana << std::endl << std::endl;
			ana.signForm(test);
			std::cout << test;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	return (0);
}*/
