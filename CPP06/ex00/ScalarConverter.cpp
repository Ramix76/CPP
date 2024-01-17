/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:34:24 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/17 15:10:15 by framos-p         ###   ########.fr       */
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
    // Puedes ajustar las condiciones según tus necesidades
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
    // Muestra la información para el int
    std::cout << "Int: " << asciiValue << std::endl;
}

// bool ScalarConverter::hasDotWithoutDecimal(const std::string& input)
// {
//     size_t dotPos = input.find('.');
//     return (dotPos != std::string::npos && dotPos < input.size() - 1 && isdigit(input[dotPos + 1]));
// }

bool ScalarConverter::hasDotWithoutDecimal(const std::string& input)
{
    size_t dotPos = input.find('.');
    return (dotPos == std::string::npos || (dotPos < input.size() - 1 && isdigit(input[dotPos + 1])));
}

void ScalarConverter::convert(const std::string &input)
{
    if (input.length() == 1 && !isdigit(input[0]))
    {
        char c = input[0];
        printCharInfo(c);
        return;
    }
   if (input == "inf" || input == "-inf" || input == "+inf")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << (input == "-inf" ? "-inf" : "inf") << "f" << std::endl;
        std::cout << "Double: " << (input == "-inf" ? "-inf" : "inf") << std::endl;
        return;
    }
    if (input == "nan" || input == "nanf")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
        return;
    }
    try
    {
        size_t endPos;
        long longValue = std::stoi(input, &endPos);

        if (endPos == input.size())
        {
            // Input is an integer
            std::cout << std::fixed << std::setprecision(1);

            if ((longValue >= 0 && longValue <= 31) || longValue == 127 || (longValue < 0 && longValue > -129))
            {
                std::cout << "Char: non displayable" << std::endl;
                std::cout << "Int: " << longValue << std::endl;
            }
            else if (longValue > std::numeric_limits<int>::max() || longValue < std::numeric_limits<int>::min())
            {
                std::cout << "Char: impossible" << std::endl;
                std::cout << "Int: impossible" << std::endl;
            }
            else if (longValue < -128 || longValue > 127)
            {
                std::cout << "Char: impossible" << std::endl;
                std::cout << "Int: " << longValue << std::endl;
            }
            else
            {
                char c = static_cast<char>(longValue);
                std::cout << "Char: " << c << std::endl;
                std::cout << "Int: " << longValue << std::endl;
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
                double doubleValue = std::stod(input);

                // Handle the casting to char for float values
                std::cout << "Char: ";
                if (std::isprint(static_cast<int>(doubleValue)))
                {
                    char c = static_cast<char>(doubleValue);
                    std::cout << c << std::endl;
                }
                else
                {
                    std::cout << "non displayable" << std::endl;
                }

                std::cout << "Int: " << static_cast<int>(doubleValue) << std::endl;
                std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << "f" << std::endl;
                std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
            }
            else
            {
                std::cout << "Invalid input: Decimal part not complete after dot" << std::endl;
            }
        }
    }
    catch (std::invalid_argument)
    {
        std::cout << "Invalid input" << std::endl;
    }
    catch (std::out_of_range)
    {
        std::cout << "Out of range" << std::endl;
    }
}

// void    ScalarConverter::convert(const std::string &input)
// {
//     if (input.length() == 1 && !isdigit(input[0]))
//     {
//         char c = input[0];
//         printCharInfo(c);
//         return;
//     }
//     if (hasDotWithoutDecimal(input) == false)
//     {
//         std::cout << "Invalid input: Decimal part not complete after dot" << std::endl;
//         return;
//     }
//     // Verificar si el argumento es un float con una 'f' al final
//     if (input.back() == 'f' && std::count(input.begin(), input.end(), 'f') == 1)
//     {
//         std::cout << "tiene f" << std::endl;
//         std::string modifiedInput = input.substr(0, input.length() - 1); // Eliminar 'f'
        
//         // // Verificar si hay solo una 'f' en el float
//         // if (input.find('f') != input.rfind('f'))
//         // {
//         //     std::cout << "Invalid input: Multiple 'f' characters in float" << std::endl;
//         //     return;
//         // }
       
//         std::istringstream ss(modifiedInput);
//         long double value;
//         ss >> value;
//         if (!ss.fail() && ss.eof())
//         {
//             // Resto de la lógica para imprimir la información
//             if ((value >= 0 && value <= 31) || value == 127 || (value < 0 && value > -129))
//             {
//                 std::cout << "Char: non displayable" << std::endl;
//                 std::cout << "Int: " << static_cast<int>(value) << std::endl;
//             }
//             else if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
//             {
//                 std::cout << "Char: impossible" << std::endl;
//                 std::cout << "Int: impossible" << std::endl;
//             }
//             else if (value < -128 || value > 127)
//             {
//                 std::cout << "Char: impossible" << std::endl;
//                 std::cout << "Int: " << static_cast<int>(value) << std::endl;
//             }
//             else
//             {
//                 char c = static_cast<char>(value); // Convertir a char
//                 std::cout << "Char: " << c << std::endl;
//                 std::cout << "Int: " << static_cast<int>(value) << std::endl;
//             }
//             std::cout << std::fixed << std::setprecision(1); // Mostrar un decimal
//             // Verificar los límites de float
//             if (value > FLT_MAX || value < -FLT_MAX)
//                 std::cout << "Float: impossible" << std::endl;
//             else
//                 std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
//             // Verificar los límites de double
//             if (value > DBL_MAX || value < -DBL_MAX)
//                 std::cout << "Double: impossible" << std::endl;
//             else
//                 std::cout << "Double: " << std::setprecision(1) << std::fixed << value << std::endl;

//             return;
//         }
//     }
//     if (input == "inf" || input == "-inf" || input == "+inf")
//     {
//         std::cout << "Char: impossible" << std::endl;
//         std::cout << "Int: impossible" << std::endl;
//         std::cout << "Float: " << (input == "-inf" ? "-inf" : "inf") << "f" << std::endl;
//         std::cout << "Double: " << (input == "-inf" ? "-inf" : "inf") << std::endl;
//         return;
//     }
//     if (input == "nan" || input == "nanf")
//     {
//         std::cout << "Char: impossible" << std::endl;
//         std::cout << "Int: impossible" << std::endl;
//         std::cout << "Float: nanf" << std::endl;
//         std::cout << "Double: nan" << std::endl;
//         return;
//     }
       
//     // std::istringstream ss(input);
//     long double value;
//     value = std::stold(input);
//     try
//     {
//         std::cout << value << std::endl;
//         std::cout << "sin f" << std::endl;
//         // Resto de la lógica para imprimir la información
//         if ((value >= 0 && value <= 31) || value == 127 || (value < 0 && value > -129))
//         {
//             std::cout << "Char: non displayable" << std::endl;
//             std::cout << "Int: " << static_cast<int>(value) << std::endl;
//         }
//         else if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
//         {
//             std::cout << "Char: impossible" << std::endl;
//             std::cout << "Int: impossible" << std::endl;
//         }
//         else if (value < -128 || value > 127)
//         {
//             std::cout << "Char: impossible" << std::endl;
//             std::cout << "Int: " << static_cast<int>(value) << std::endl;
//         }
//         else
//         {
//             char c = static_cast<char>(value); // Convertir a char
//             std::cout << "Char: " << c << std::endl;
//             std::cout << "Int: " << static_cast<int>(value) << std::endl;
//         }
//         std::cout << std::fixed << std::setprecision(1); // Mostrar un decimal
//         // Verificar los límites de float
//         if (value > FLT_MAX || value < -FLT_MAX)
//             std::cout << "Float: impossible" << std::endl;
//         else
//             std::cout << "Float: " << static_cast<float>(value) << "f" << std::endl;
//         // Verificar los límites de double
//         if (value > DBL_MAX || value < -DBL_MAX)
//             std::cout << "Double: impossible" << std::endl;
//         else
//             std::cout << "Double: " << std::setprecision(1) << std::fixed << value << std::endl;

//         return;
//     }
//     catch(std::invalid_argument)
//     {
//     // Mostrar mensaje de error para entrada no válida
//         std::cout << "Invalid input" << std::endl;
//     }
// }