/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:36:30 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/10 11:54:05 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void printNumbers(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    try {
        // Caso de éxito
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::vector<int> numbersInSpan;
        for (unsigned int i = 0; i < sp.getSize(); ++i) {
            try {
                numbersInSpan.push_back(sp.getElementAt(i));
            } catch (const std::exception& e) {
                break; // Salir si se produce una excepción al acceder a los números
            }
        }

        std::cout << "Successful Case:" << std::endl;
        std::cout << "Numbers in Span: ";
        printNumbers(numbersInSpan);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Intentar agregar más elementos de los permitidos
        int numToAdd = 5;
        std::cout << "Trying to add number: " << numToAdd << std::endl;
        sp.addNumber(numToAdd); // Esto debería lanzar una excepción

        // Agregar un rango que excede el límite
        std::vector<int> rangeExceedingLimit;
        rangeExceedingLimit.push_back(1);
        rangeExceedingLimit.push_back(2);
        rangeExceedingLimit.push_back(3);
        rangeExceedingLimit.push_back(4);
        rangeExceedingLimit.push_back(5);
        rangeExceedingLimit.push_back(6);
        rangeExceedingLimit.push_back(7);

        std::cout << "Trying to add range: ";
        printNumbers(rangeExceedingLimit);

        sp.addRange(rangeExceedingLimit); // Esto también debería lanzar una excepción
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Caso sin suficientes elementos para calcular el span
        Span spEmpty = Span(2);
        spEmpty.addNumber(6);

        std::vector<int> numbersInEmptySpan;
        for (unsigned int i = 0; i < spEmpty.getSize(); ++i) {
            try {
                numbersInEmptySpan.push_back(spEmpty.getElementAt(i));
            } catch (const std::exception& e) {
                break; // Salir si se produce una excepción al acceder a los números
            }
        }

        std::cout << "\nEmpty Span Case:" << std::endl;
        std::cout << "Numbers in Empty Span: ";
        printNumbers(numbersInEmptySpan);
        std::cout << "Shortest Span: " << spEmpty.shortestSpan() << std::endl; // Debería lanzar una excepción
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}