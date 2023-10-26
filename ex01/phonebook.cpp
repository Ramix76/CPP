/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:52:18 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/26 15:56:17 by framos-p         ###   ########.fr       */
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
	if (numContacts < 8)
	{
		contacts[counter] = newContact;
		numContacts++;
		counter++;
		return (true);
	}
	else
	{
		if (counter == 8)
			counter = 0;
		contacts[counter] = newContact;
		counter++;
		std::cout << "Phonebook is full.replacing the oldest contact." << std::endl;
		return (true);
	}
}

void	Phonebook::printContacts() const
{
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << std::setw(38) << "     ---------------------------------------" << std::endl;
	for (int i = 0; i < numContacts; i++)
	{
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickName();
		firstName = add_dot_if_length_is_greater_than_9(firstName);
		lastName = add_dot_if_length_is_greater_than_9(lastName);
		nickname = add_dot_if_length_is_greater_than_9(nickname);
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << std::right << firstName << "|";
		std::cout << std::setw(10) << std::right << lastName << "|";
		std::cout << std::setw(10) << std::right << nickname << "|" << std::endl;
	}
}

std::string getNonEmptyInput(const std::string &prompt)
{
	std::string	input;
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
			return (input);
		else if (!std::cin)
			break;
		std::cout << "Input cannot be empty. Please try again." << std::endl;
	}
	return (input);
}

void	Phonebook::addContactToPhonebook(Phonebook &phonebook)
{
	std::string fn, ln, nn, pn, ds;

	fn = getNonEmptyInput("Enter First Name: ");
	if (fn == "")
		return;
	ln = getNonEmptyInput("Enter Last Name: ");
	if (ln == "")
		return;
	nn = getNonEmptyInput("Enter Nickname: ");
	if (nn == "")
		return;
	pn = getNonEmptyInput("Enter Phone Number: ");
	if (pn == "")
		return;
	ds = getNonEmptyInput("Enter Darkest Secret: ");
	if (ds == "")
		return;

	Contact newContact;
	newContact.setFirstName(fn);
	newContact.setLastName(ln);
	newContact.setNickName(nn);
	newContact.setPhoneNumber(pn);
	newContact.setDarkestSecret(ds);

	if (phonebook.addContact(newContact))
		std::cout << "Contact added successfully." << std::endl;
	else
		std::cout << "Phonebook is full. Contact not added." << std::endl;
}

void	Phonebook::searchContacts(const Phonebook &phonebook)
{
	phonebook.printContacts();
	if (phonebook.getNumberOfContacts() > 0)
	{
		int	index;
		std::cout << "Enter the index of the contact you want to display: ";
		std::cin >> index;
		if (index >= 0 && index < phonebook.getNumberOfContacts())
		{
			Contact contact = phonebook.getContact(index);
			std::cout << "Contact Details:" << std::endl;
			std::cout << "First Name: " << contact.getFirstName() << std::endl;
			std::cout << "Last Name: " << contact.getLastName() << std::endl;
			std::cout << "Nickname: " << contact.getNickName() << std::endl;
			std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
		}
		else
			std::cout << "Invalid index. Please enter a valid index." << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
