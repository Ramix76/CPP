/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:52 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/26 15:56:19 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	Phonebook	phonebook;
	while (true)
	{
		if (std::cin.eof())
			break;
		std::cout << "Options: ADD, SEARCH, EXIT" << std::endl;
		std::string choice;
		std::getline(std::cin, choice);
		if (std::cin.eof())
			break;
		else if (choice == "ADD")
			phonebook.addContactToPhonebook(phonebook);
		else if (choice == "SEARCH")
			phonebook.searchContacts(phonebook);
		else if (choice == "EXIT")
			break;
		else
			std::cout << "Invalid option. Please choose ADD, SEARCH, or EXIT." << std::endl;
	}
	return (0);
}
