/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:43:34 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/09 14:54:44 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

struct ValueFoundException : public std::exception
{
    const char *what() const throw()
    {
        return ("Value not found in container");
    } 
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = container.begin();
    for (; it != container.end(); ++it)
    {
        if (*it == value)
            return (it);
    }
    throw ValueFoundException();
}

#endif