/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:55:21 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/27 18:06:18 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include "AForm.hpp"
# include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &buro);
		Bureaucrat &operator=(Bureaucrat const &other);

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

		void	signForm(AForm &form);
		void	executeForm(AForm const &form);
		void	incrementGrade();
		void	decrementGrade();
		int	getGrade() const;
		const std::string &getName() const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);


#endif
