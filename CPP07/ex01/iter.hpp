/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:13:15 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/09 11:19:48 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename Func>
    void iter(T *arr, size_t length, Func funct)
    {
        for (size_t i = 0; i < length; ++i)
            funct(arr[i]);
    }

#endif