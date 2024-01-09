/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:47:10 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/09 12:01:57 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(nullptr), arrSize(0) {}

template <typename T>        
Array<T>::Array(unsigned int n) : arr(new T[n]), arrSize(n)
{
    for (unsigned int i = 0; i < arrSize; ++i)
        arr[i] = T();
}

template <typename T>        
Array<T>::Array(const Array &other) : arr(new T[other.arrSize]), arrSize(other.arrSize)
{
    for (unsigned int i = 0; i < arrSize; ++i)
        arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != other)
    {
        delete[] arr;
        arrSize = other.arrSize;
        arr = new T[arrSize];
        for (unsigned int i = 0; i < arrSize; ++i)
        arr[i] = other.arr[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= arrSize)
        throw std::out_of_range("Index out of bounds");
    return (arr[index]);
}

template <typename T>        
unsigned int Array<T>::size() const
{
    return (arrSize);
}

#endif