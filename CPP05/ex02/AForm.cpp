/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:59:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/27 17:51:50 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(0), _gradeToSign(0), _gradeToExecute(0)
{
	//std::cout << "Form default constructor called!" << std::endl;
}

AForm::~AForm()
{
	//std::cout << "Form destructor called!" << std::endl;
}

AForm::AForm(AForm const &form) : _name(form._name), _isSigned(form._isSigned), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	//std::cout << "Form copy constructor called!" << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
	std::cout << "Assignation not allowed for Form's class" << std::endl;
	(void)other;
	return (*this);
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

const std::string &AForm::getName() const
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
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << std::endl
		<< "Signed Status: " << form.getIsSigned() << std::endl
		<< "Grade required to sign: " << form.getGradeToSign() << std::endl
		<< "Grade required   to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}
