/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:54:58 by framos-p          #+#    #+#             */
/*   Updated: 2023/10/26 12:15:43 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"


Contact::Contact()
{
	return;
}

Contact::~Contact()
{
	return;
}

Contact::Contact(const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds)
    : _first_name(fn), _last_name(ln), _nick_name(nn), _phone_number(pn), _darkest_secret(ds)
{
}

void Contact::setFirstName(const std::string &fn)
{
    _first_name = fn;
}

void Contact::setLastName(const std::string &ln)
{
    _last_name = ln;
}

void Contact::setNickName(const std::string &nn)
{
    _nick_name = nn;
}

void Contact::setPhoneNumber(const std::string &pn)
{
    _phone_number = pn;
}

void Contact::setDarkestSecret(const std::string &ds)
{
    _darkest_secret = ds;
}

std::string Contact::getFirstName() const
{
    return (_first_name);
}

std::string Contact::getLastName() const
{
    return (_last_name);
}

std::string Contact::getNickName() const
{
    return (_nick_name);
}

std::string Contact::getPhoneNumber() const
{
    return (_phone_number);
}

std::string Contact::getDarkestSecret() const
{
    return (_darkest_secret);
}
