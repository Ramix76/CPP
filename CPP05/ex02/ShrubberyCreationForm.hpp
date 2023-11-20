/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:44:20 by framos-p          #+#    #+#             */
/*   Updated: 2023/11/20 13:50:02 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AFomr.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &scf);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

		std::string	const &getTarget() const;
		void		execute(Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif
