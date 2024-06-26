/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:32:55 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/27 18:01:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &rrf);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

		std::string	const &getTarget() const;
		void		execute(Bureaucrat &executor) const;

	private:
		const std::string _target;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif
