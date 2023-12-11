/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:32:55 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/20 13:39:29 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &rrf);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

	std::string	const &getTarget() const;
	void		execute(Bureaucrat &executor) const;
};

std::ostream::&operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif
