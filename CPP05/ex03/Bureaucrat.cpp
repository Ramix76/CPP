/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:28:01 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 12:24:39 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
	//std::cout << "Bureaucrat default constructor called!" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat destructor called!" << std::endl;
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(0)
{
	//std::cout << "Bureaucrat constructor called!" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &buro) : _name(buro.getName())
{
	//std::cout << "Bureaucrat copy constructor called!" << std::endl;
	*this = buro;
	return ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::string const &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return(_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
	return ;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
	return ;
}

void	Bureaucrat::signForm(AForm &form)
{
	std::cout << _name;
	if (form.getIsSigned())
	{
		std::cout << " cannot sign " << form.getName() << " because form is already signed" << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;

	}
	return ;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (ShrubberyCreationForm::FormNotSignedException &e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because form is not signed" << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << "because bureaucrat has not enough clearance" << std::endl;
	}
	return ;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (out);
}
