/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:59:23 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/20 12:54:55 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _isSigned(0), _gradeToSign(0), _gradeToExecute(0)
{
	//std::cout << "Form default constructor called!" << std::endl;
}

Form::~Form()
{
	//std::cout << "Form destructor called!" << std::endl;
}

Form::Form(Form const &form) : _name(form._name), _isSigned(form._isSigned), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	//std::cout << "Form copy constructor called!" << std::endl;
}

Form &Form::operator=(Form const &other)
{
	std::cout << "Assignation not allowed for Form's class" << std::endl;
	(void)other;
	return (*this);
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &buro)
{
	if (buro.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << std::endl
		<< "Signed Status: " << form.getIsSigned() << std::endl
		<< "Grade required to sign: " << form.getGradeToSign() << std::endl
		<< "Grade required   to execute: " << form.getGradeToExecute() << std::endl;
	return (out);
}
