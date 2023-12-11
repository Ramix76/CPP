/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:43:43 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/20 13:22:59 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm();
		~AForm();
		AForm(const std::string name, const int gradeToSgin, const int gradeToExecute);
		AForm(AForm const &form);
		AForm &operator=(AForm const &other);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class FornNotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};

		const std::string	&getName() const;
		bool			getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat &buro);
		void		signForm(const Bureaucrat &buro);
		virtual void	execute(Bureaucrat &executor) const = 0;

};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
