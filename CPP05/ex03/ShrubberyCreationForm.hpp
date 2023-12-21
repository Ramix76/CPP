/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:44:20 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 11:30:16 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
		ShrubberyCreationForm();

	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &scf);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

		std::string	const &getTarget() const;
		void		execute(Bureaucrat &executor) const;
		AForm 		*clone( void ) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif
