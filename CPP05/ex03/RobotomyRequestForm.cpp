/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:01:20 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 11:48:56 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
	//std:cout << "RobotomyRequestForm default constructor called!" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm destructor called!" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rrf) : AForm(rrf), _target(rrf._target)
{
	//std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	//std::cout << "RobotomyRequestForm constructor called!" << std::endl;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	std::cout << "RobotomyRequestForm not allowed for RobotomyRequestForm's class!" << std::endl;
	(void)other;
	return (*this);
}

std::string const &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

AForm *RobotomyRequestForm::clone( void ) const
{
	AForm *clone = new RobotomyRequestForm(*this);
	return (clone);
}

void	RobotomyRequestForm::execute(Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	srand(time(0));
	std::cout << this->getTarget();
	if (rand() % 2)
		std::cout << " has been robotomized!." << std::endl;
	else
		std::cout << " robotomization failed!." << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form)
{
	out << "Name: " << form.getName() << std::endl
	<< "Signed Status: " << form.getIsSigned() << std::endl
	<< "Grade required to sign: " << form.getGradeToSign() << std::endl
	<< "Grade required to execute: " << form.getGradeToExecute() << std::endl
	<< "Target: " << form.getTarget() << std::endl;
	return (out);
}
