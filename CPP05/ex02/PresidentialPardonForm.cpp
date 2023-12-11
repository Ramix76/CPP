/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:33:42 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/27 18:14:43 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
	//std::cout << "PresidentialPardonForm default constructor called!" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//srd::cout << "PresidentialPardonForm destructor called!" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	//std::cout << "PresidentialPardonForm constructor called!" << srd::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ppf) : AForm(ppf), _target(ppf._target)
{
	//std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	std::cout << "Assignation not allowed for PresidentialPardonForm's class" << std::endl;
	(void)other;
	return (*this);
}

std::string const &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}

std::ostream &operator<(std::ostream &out, PresidentialPardonForm const &form)
{
	out << "Name: " << form.getName() << std::endl
	<< "Signed Status: " << form.getIsSigned() << std::endl
	<< "Grade required to sign: " << form.getGradeToSign() << std::endl
	<< "Grade required to execute: " << form.getGradeToExecute() << std::endl
	<< "Target: " << form.getTarget() << std::endl;
	return (out);
}
