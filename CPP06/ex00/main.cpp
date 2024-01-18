/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:02:11 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/18 11:01:21 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printError(const std::string& errorMessage)
{
    std::cout << "Error: " << errorMessage << std::endl;
}

bool isValidInput(const std::string& input)
{
    if (input == "inf" || input == "-inf" || input == "+inf" || input == "inff" || input == "-inff" || input == "+inff")
        return (true);
    if (input == "nan" || input == "nanf" || input == "nanff" || input == "-nanff" || input == "+nanff" || input == "-nanf" || input == "+nanf")
        return (true);
    // Permitir letras solas en la entrada
    if (input.size() == 1 && isalpha(static_cast<unsigned char>(input[0])))
        return (true);
    // Permitir que el argumento empiece con '+' o '-'
    if (!input.empty() && (input[0] == '+' || input[0] == '-'))
        return (true);
    // Verificar si la entrada es un número decimal con la letra 'f' al final
    size_t fPosition = input.find('f');
    if (fPosition != std::string::npos)
    {
        // Verificar que 'f' está al final
        if (fPosition == input.size() - 1)
        {
            // Verificar que los caracteres antes de 'f' son dígitos o un punto decimal
            bool validNumericPart = true;
            bool decimalFound = false;
            size_t dotCount = 0;
            for (size_t i = 0; i < fPosition; ++i)
            {
                char c = input[i];

                if (!isdigit(static_cast<unsigned char>(c)) && c != '.')
                {
                    validNumericPart = false;
                    break;
                }
                if (c == '.')
                {
                    if (i == fPosition - 1)
                    {
                        printError("Invalid input: 'f' should not immediately follow a decimal point");
                        return (false);
                    }
                    // Check if there are digits after the decimal point
                    decimalFound = true;
                    ++dotCount;
                    if (dotCount > 1)
                    {
                        printError("Invalid input: More than one decimal point found");
                        return (false);
                    }
                }
            }
            if (!validNumericPart || !decimalFound)
            {
                printError("Invalid input: Invalid numeric part before 'f'");
                return (false);
            }
            return (true);
        }
        else
        {
            printError("Invalid input: 'f' must be at the end");
            return (false);
        }
    }
    else
    {
        // Permitir letras, números y caracteres especiales
        bool decimalFound = false;
        size_t dotCount = 0;
        for (size_t i = 0; i < input.size(); ++i)
        {
            char c = input[i];
            if (!isdigit(static_cast<unsigned char>(c)) && c != '.')
            {
                if (c == 'f' && i == input.size() - 1 && decimalFound)
                {
                    // 'f' at the end is allowed after decimal numbers
                    return (true);
                }
                else
                {
                    printError("Invalid input: Contains non-numeric characters");
                    return (false);
                }
            }
            else if (c == '.')
            {
                if (input[i + 1] == '\0')
                {
                    printError("Invalid input: Decimal point at the end");
                    return (false);
                }
                // Check if there are digits after the decimal point
                decimalFound = true;
                ++dotCount;
                if (dotCount > 1)
                {
                    printError("Invalid input: More than one decimal point found");
                    return (false);
                }
            }
        }
        return (true);
    }
}

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cout << "Usage: ./convert arg" << std::endl;
            return (1);
        }
        // Convertir el argumento a std::string
        std::string input(argv[1]); 
        // Validar la entrada antes de intentar procesarla
        if (!isValidInput(input))
            return (1);
        ScalarConverter::convert(input);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}