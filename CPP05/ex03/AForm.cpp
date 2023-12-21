/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:59:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 12:42:01 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(0), _gradeToSign(0), _gradeToExecute(0)
{
	//std::cout << "AForm default constructor called!" << std::endl;
	return ;
}

AForm::~AForm()
{
	//std::cout << "AForm destructor called!" << std::endl;
	return ;
}

AForm::AForm(AForm const &form) : _name(form._name), _isSigned(form._isSigned), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	//std::cout << "AForm copy constructor called!" << std::endl;
	return ;
}

AForm &AForm::operator=(AForm const &other)
{
	std::cout << "Assignation not allowed for AForm's class" << std::endl;
	(void)other;
	return (*this);
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	//std::cout << "AForm constructor called!" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	return ;
}

std::string const &AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &buro)
{
	if (buro.getGrade() <= _gradeToSign)
		_isSigned = 1;
	else
		throw GradeTooLowException();
	return ;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Name: " << form.getName() << std::endl
		<< "Signed Status: " << form.getIsSigned() << std::endl
		<< "Grade required to sign: " << form.getGradeToSign() << std::endl
		<< "Grade required   to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}
