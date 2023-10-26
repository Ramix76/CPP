/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:52:18 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/26 12:39:54 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>

Phonebook::Phonebook()
{
	numContacts = 0;
	counter = 0;
}

Phonebook::~Phonebook()
{
	return;
}

int	Phonebook::getNumberOfContacts() const
{
	return (numContacts);
}

Contact Phonebook::getContact(int index) const
{
	if (index >= 0 && index < numContacts)
		return (contacts[index]);
	return (Contact());
}

std::string add_dot_if_length_is_greater_than_9(std::string str)
{
	if (str.length() > 9)
		str = str.substr(0, 9) + ".";
	return (str);
}

bool	Phonebook::addContact(Contact &newContact)
{
	if (numContacts < 3)
	{
		contacts[counter] = newContact;
		numContacts++;
		counter++;
		return (true);
	}
	else
	{
		if (counter == 3)
			counter = 0;
		contacts[counter] = newContact;
		counter++;
		std::cout << "Phonebook is full.replacing the oldest contact." << std::endl;
		return (true);
	}
}

void Phonebook::printContacts() const
{
	// Create the table
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << std::setw(38) << "     ---------------------------------------" << std::endl;
	for (int i = 0; i < numContacts; i++)
	{
		// Declare variables
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickName();
		// Apply the function to each string
		firstName = add_dot_if_length_is_greater_than_9(firstName);
		lastName = add_dot_if_length_is_greater_than_9(lastName);
		nickname = add_dot_if_length_is_greater_than_9(nickname);
		// Print the field name
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << std::right << firstName << "|";
		std::cout << std::setw(10) << std::right << lastName << "|";
		std::cout << std::setw(10) << std::right << nickname << "|" << std::endl;
	}
}
