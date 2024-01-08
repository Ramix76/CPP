/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:34:24 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/08 11:37:09 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath>


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

void    ScalarConverter::convert(const std::string &input)
{
    if (input == "inf" || input == "-inf" || input == "+inf") {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << (input == "-inf" ? -std::numeric_limits<float>::infinity()
                                                  : std::numeric_limits<float>::infinity()) << "f" << std::endl;
        std::cout << "Double: " << (input == "-inf" ? -std::numeric_limits<double>::infinity()
                                                   : std::numeric_limits<double>::infinity()) << std::endl;
        return;
    }

    if (input == "nan") {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: nan" << std::endl;
        std::cout << "Double: nan" << std::endl;
        return;
    }
    
    std::istringstream ss(input);
    
    double value;
    ss >> value;

    if (!ss.fail())
    {
        char c = static_cast<char>(value); // Convertir a char
        std::cout << "Char: " << c << std::endl;
        std::cout << "Int: " << static_cast<int>(value) << std::endl;
        std::cout << std::fixed << std::setprecision(1); // Mostrar un decimal
        std::cout << "Float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "Double: " << std::setprecision(1) << std::fixed << value << std::endl;
        
    }
    else
        std::cout << "Invalid input" << std::endl;
           
}