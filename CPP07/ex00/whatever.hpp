/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:20:03 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/08 13:30:52 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
T const &min(T const &x, T const &y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

template <typename T>
T const &max(T const &x, T const &y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

#endif