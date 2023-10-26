/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:55:11 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/26 12:16:03 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>
# include "contact.hpp"

class Contact
{
	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nick_name;
		std::string		_phone_number;
		std::string		_darkest_secret;

	public:
		Contact();
		~Contact();
		Contact(const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds);
		void			setFirstName(const std::string &fn);
		void			setLastName(const std::string &ln);
		void			setNickName(const std::string &nn);
		void			setPhoneNumber(const std::string &pn);
		void			setDarkestSecret(const std::string &ds);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif
