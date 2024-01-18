/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:34:24 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/18 11:02:01 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    //std::cout << "ScalarConverter default constructor called!" << std::endl;
    return ;
}

ScalarConverter::~ScalarConverter()
{
    //std::cout << "ScalarConverter destructor called!" << std::endl;
    return ;  
}

ScalarConverter::ScalarConverter(ScalarConverter const &sc)
{
    //std::cout "ScalarConverter copy constructor called!" << std::endl;
    *this = sc;
    return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    if (this == &other)
        return (*this);
    return (*this);    
}

bool ScalarConverter::isCharRepresentable(char c)
{
    return (std::isalnum(c) || std::ispunct(c) || std::isspace(c));
}

void ScalarConverter::printCharInfo(char c)
{
    if (isCharRepresentable(c))
    {
        int asciiValue = static_cast<double>(c);
        // Muestra la información para el char
        std::cout << "Char: " << c << std::endl;
        // Muestra la información para el int
        printAsciiInfo(asciiValue);
        // Muestra la información para el float
        std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(asciiValue) << "f" << std::endl;
        // Muestra la información para el double
        std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(asciiValue) << std::endl;
    }
    else
    {
        std::cout << "Char: non displayable" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: impossible" << std::endl;
        std::cout << "Double: impossible" << std::endl;
    }
}

void ScalarConverter::printAsciiInfo(int asciiValue)
{
    std::cout << "Int: " << asciiValue << std::endl;
}


void ScalarConverter::convert(const std::string &input)
{
    if (input.length() == 1 && !isdigit(input[0]))
    {
        char c = input[0];
        printCharInfo(c);
        return;
    }
   if (input == "inf" || input == "-inf" || input == "+inf" || input == "inff" | input == "-inff" | input == "+inff")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << (input == "-inf" ? "-inf" : "inf") << "f" << std::endl;
        std::cout << "Double: " << (input == "-inf" ? "-inf" : "inf") << std::endl;
        return;
    }
    if (input == "nan" || input == "nanf" || input == "nanff" || input == "-nanff" || input == "+nanff" || input == "-nanf" || input == "+nanf")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
        return;
    }
    try
    {
        // Check if input is a float (ends with 'f')
        if (input.size() > 1 && input.back() == 'f' && input[input.size() - 2] == '.')
        {
            std::string modifiedInput = input.substr(0, input.length() - 1); // Remove 'f'
            long double doubleValue = std::stold(modifiedInput);
            // Handle the casting to char for float values
            std::cout << "Char: ";
            if (std::isprint(static_cast<int>(doubleValue)))
            {
                char c = static_cast<char>(doubleValue);
                std::cout << c << std::endl;
            }
            else
                std::cout << "non displayable" << std::endl;
            std::cout << "Int: impossible" << std::endl;
            std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << "f" << std::endl;
            std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
            return;
        }
        size_t endPos;
        long double longValue = std::stold(input, &endPos);

        if (endPos == input.size())
        {
            // Input is an integer
            std::cout << std::fixed << std::setprecision(1);
            if ((longValue >= 0 && longValue <= 31) || longValue == 127 || (longValue < 0 && longValue > -129))
            {
                std::cout << "Char: non displayable" << std::endl;
                std::cout << "Int: " << static_cast<int>(longValue) << std::endl;
            }
            else if (longValue > std::numeric_limits<int>::max() || longValue < std::numeric_limits<int>::min())
            {
                std::cout << "Char: impossible" << std::endl;
                std::cout << "Int: impossible" << std::endl;
            }
            else if (longValue < -128 || longValue > 127)
            {
                std::cout << "Char: impossible" << std::endl;
                std::cout << "Int: " << static_cast<int>(longValue) << std::endl;
            }
            else
            {
                char c = static_cast<char>(longValue);
                std::cout << "Char: " << c << std::endl;
                std::cout << "Int: " << static_cast<int>(longValue) << std::endl;
            }

            if (longValue > FLT_MAX || longValue < -FLT_MAX)
                std::cout << "Float: impossible" << std::endl;
            else
                std::cout << "Float: " << static_cast<float>(longValue) << "f" << std::endl;

            if (longValue > DBL_MAX || longValue < -DBL_MAX)
                std::cout << "Double: impossible" << std::endl;
            else
                std::cout << "Double: " << static_cast<double>(longValue) << std::endl;
        }
        else
        {
            // Input is a float
            size_t dotPos = input.find('.');
            if (dotPos != std::string::npos && dotPos < input.size() - 1 && isdigit(input[dotPos + 1]))
            {
                long double doubleValue = std::stold(input);
                // Handle the casting to char for float values
                std::cout << "Char: ";
                if (std::isprint(static_cast<int>(doubleValue)))
                {
                    char c = static_cast<char>(doubleValue);
                    std::cout << c << std::endl;
                }
                else
                    std::cout << "non displayable" << std::endl;
                std::cout << "Int: " << static_cast<int>(doubleValue) << std::endl;
                std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << "f" << std::endl;
                std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
            }
            else
                std::cout << "Invalid input: Decimal part not complete after dot" << std::endl;
        }
    }
    catch (std::invalid_argument)
    {
        std::cout << "Invalid input" << std::endl;
    }
}