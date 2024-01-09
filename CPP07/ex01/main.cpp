/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:16:50 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/09 11:26:23 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Example function to be used with iter
template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "Iterating over intArray:" << std::endl;
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "Iterating over doubleArray:" << std::endl;
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    return 0;
}
