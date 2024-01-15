/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:34:24 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/15 16:10:42 by framos-p         ###   ########.fr       */
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

bool hasDotWithoutDecimal(const std::string& input) {
    size_t dotPos = input.find('.');
    return (dotPos != std::string::npos && dotPos == input.size() - 1);
}

void    ScalarConverter::convert(const std::string &input)
{
    // Verificar si el número tiene un punto pero sin un decimal
    if (hasDotWithoutDecimal(input))
    {
        std::cout << "Invalid input: Missing decimal part after dot." << std::endl;
        return;
    }
    // Eliminar 'f' al final del número si está seguido por un '.' pero no por un número
    std::string modifiedInput = input;
    size_t dotPos = modifiedInput.find('.');
    if (dotPos != std::string::npos && dotPos < modifiedInput.size() - 1) {
        if (modifiedInput[dotPos + 1] == 'f') {
            std::cout << "Invalid input: 'f' should be preceded by a number after the dot." << std::endl;
            return;
        }
        modifiedInput.pop_back();  // Eliminar 'f'
    }
    if (input == "inf" || input == "-inf" || input == "+inf")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << (input == "-inf" ? "-inf" : "inf") << "f" << std::endl;
        std::cout << "Double: " << (input == "-inf" ? "-inf" : "inf") << std::endl;
        return;
    }
    if (input == "nan")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: nan" << std::endl;
        std::cout << "Double: nan" << std::endl;
        return;
    }
    std::istringstream ss(modifiedInput);
    long double value;
    ss >> value;
    if (!ss.fail())
    {
        // Verificar si el valor está dentro del rango de int
        if ((value >= 0 && value <= 31) || value == 127 || (value < 0 && value > -129))
        {
            std::cout << "Char: non displayable" << std::endl;
            std::cout << "Int: " << static_cast<int>(value) << std::endl;
        }
        
        else if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        {
            std::cout << "Char: impossible" << std::endl;
            std::cout << "Int: impossible" << std::endl;
        }
        else if (value < -128 || value > 127)
        {
            std::cout << "Char: impossible" << std::endl;
            std::cout << "Int: " << static_cast<int>(value) << std::endl;
        }
        else
        {
            char c = static_cast<char>(value); // Convertir a char
            std::cout << "Char: " << c << std::endl;
            std::cout << "Int: " << static_cast<int>(value) << std::endl;
        }
        std::cout << std::fixed << std::setprecision(1); // Mostrar un decimal
        // Verificar los límites de float
        if (value > FLT_MAX || value < -FLT_MAX)
            std::cout << "Float: impossible" << std::endl;
        else
            std::cout << "Float: " << static_cast<float>(value) << "f" << std::endl;
        // Verificar los límites de double
        if (value > DBL_MAX || value < -DBL_MAX)
            std::cout << "Double: impossible" << std::endl;
        else
            std::cout << "Double: " << std::setprecision(1) << std::fixed << value << std::endl;
    }
    else
        std::cout << "Invalid input" << std::endl;
}