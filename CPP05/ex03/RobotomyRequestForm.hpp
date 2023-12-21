/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:32:55 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 11:29:38 by framos-p         ###   ########.fr       */
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
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &rrf);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

		std::string	const &getTarget() const;
		void		execute(Bureaucrat &executor) const;
		AForm 		*clone( void ) const;

	private:
		const std::string _target;
		RobotomyRequestForm();
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif
