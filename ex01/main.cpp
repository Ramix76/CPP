/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:52 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/26 12:48:04 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	Phonebook	phonebook;
	Contact		newContact;
	int			index;

	while (true)
	{
		std::cout << "Options: ADD, SEARCH, EXIT" << std::endl;
		std::string choice;
		std::getline(std::cin, choice);
		if (!std::cin)
			break;
		else if (choice == "ADD")
		{
			std::string fn, ln, nn, pn, ds;
			while (true)
			{
				if (!std::cin)
					break;
				std::cout << "Enter First Name: ";
				std::getline(std::cin, fn);
				if (!fn.empty())
					break;
				std::cout << "First Name cannot be empty. Please try again." << std::endl;
			}
			if (!std::cin)
				break;
			while (true)
			{
				std::cout << "Enter Last Name: ";
				std::getline(std::cin, ln);
				if (!ln.empty())
					break;
				std::cout << "Last Name cannot be empty. Please try again." << std::endl;
			}
			while (true)
			{
				std::cout << "Enter Nickname: ";
				std::getline(std::cin, nn);
				if (!nn.empty())
					break;
				std::cout << "Nickname cannot be empty. Please try again." << std::endl;
			}
			while (true)
			{
				std::cout << "Enter Phone Number: ";
				std::getline(std::cin, pn);
				if (!pn.empty())
					break;
				std::cout << "Phone Number cannot be empty. Please try again." << std::endl;
			}
			while (true)
			{
				std::cout << "Enter Darkest Secret: ";
				std::getline(std::cin, ds);
				if (!ds.empty())
					break;
				std::cout << "Darkest Secret cannot be empty. Please try again." << std::endl;
			}
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
		else if (choice == "SEARCH")
		{
			phonebook.printContacts();
			if (phonebook.getNumberOfContacts() > 0)
			{
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
			}
		}
		else if (choice == "EXIT")
			break;
		else
			std::cout << "Invalid option. Please choose ADD, SEARCH, or EXIT." << std::endl;
	}
	return (0);
}
