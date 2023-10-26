/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:52:34 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/26 15:17:18 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cctype>
# include "phonebook.hpp"
# include "contact.hpp"

class Phonebook
{
	private:
		Contact		contacts[8];
		int			numContacts;
		int			counter;

	public:
		Phonebook();
		~Phonebook();
		bool		addContact(Contact &newContact);
		void		printContacts() const;
		void		addContactToPhonebook(Phonebook &phonebook);
		void		searchContacts(const Phonebook &phonebook);
		int			getNumberOfContacts() const;
		Contact		getContact(int index) const;
};

#endif
