/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:32:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 10:42:48 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	//std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "shrubberyCreationForm destructor called!" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) , _target(target)
{
	//std::cout << "ShrubberyCreationForm constructor called!" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &scf) : AForm(scf), _target(scf._target)
{
	//std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	std::cout << "Assignation not allowed for ShrubberyCreationForm's class!" << std::endl;
	(void)other;
	return (*this);
}

std::string const &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "       _-_       " << std::endl;
	file << "    /~~   ~~\\   " << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~ " << std::endl;
	file << "_- -   | | _- _  " << std::endl;
	file << "  _ -  | |   -_  " << std::endl;
	file << "      // \\\\    " << std::endl;
	file.close();
	return ;
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form)
{
	out << "Name: " << form.getName() << std::endl
	<< "Signed Status: " << form.getIsSigned() << std::endl
	<< "Grade required to sign: " << form.getGradeToSign() << std::endl
	<< "Grade required to execute: " << form.getGradeToExecute() << std::endl
	<< "Target: " << form.getTarget() << std::endl;
	return (out);
}
