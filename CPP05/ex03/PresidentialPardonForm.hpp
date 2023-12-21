/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:23:34 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 11:28:26 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
		PresidentialPardonForm();

	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &ppf);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

		std::string	const &getTarget() const;
		void		execute(Bureaucrat &executor) const;
		AForm 		*clone( void ) const; 
};

std::ostream &	operator<<( std::ostream & out, PresidentialPardonForm const &form);

#endif
