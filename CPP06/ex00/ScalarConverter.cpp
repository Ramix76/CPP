/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:34:24 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 15:13:15 by framos-p         ###   ########.fr       */
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

void    ScalarConverter::convert(const std::string &input)
{
    std::istringstream ss(input);
    
    char c;
    ss >> c;
    std::cout << "Char: " << c << std::endl;

    int i;
    ss.clear();
    ss.seekg(0);
    ss >> i;
    if (!ss.fail()) {
        std::cout << "Int: " << i << std::endl;
    } else {
        std::cout << "Invalid int input" << std::endl;
    }

    float f;
    ss.clear();
    ss.seekg(0);
    ss >> f;
    if (!ss.fail()) {
        std::cout << "Float: " << f << std::endl;
    } else {
        std::cout << "Invalid float input" << std::endl;
    }

    double d;
    ss.clear();
    ss.seekg(0);
    ss >> d;
    if (!ss.fail()) {
        std::cout << "Double: " << d << std::endl;
    } else {
        std::cout << "Invalid double input" << std::endl;
    }

    if (input == "inf" || input == "-inf" || input == "+inf") {
        std::cout << "Special Float: " << (input == "-inf" ? -std::numeric_limits<float>::infinity()
                                                            : std::numeric_limits<float>::infinity()) << std::endl;
    }

    if (input == "nan") {
        std::cout << "Special Double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
    }
}