/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:02:11 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/17 16:23:49 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// bool isValidInput(const std::string& input)
// {
//     // Permitir letras solas en la entrada
//     if (input.size() == 1 && isalpha(input[0]))
//     {
//         return true;
//     }

//     // Verificar si la entrada es un número decimal con la letra 'f' al final
//     size_t fPosition = input.find('f');

//     if (fPosition != std::string::npos)
//     {
//         // Verificar que 'f' está al final
//         if (fPosition == input.size() - 1)
//         {
//             // Verificar que los caracteres antes de 'f' son dígitos o un punto decimal
//             bool validNumericPart = true;
//             for (size_t i = 0; i < fPosition; ++i)
//             {
//                 char c = input[i];
//                 if (!isdigit(c) && c != '.')
//                 {
//                     validNumericPart = false;
//                     break;
//                 }
//             }

//             if (validNumericPart)
//             {
//                 return true;
//             }
//             else
//             {
//                 std::cout << "Invalid input: Contains non-numeric characters before 'f'" << std::endl;
//                 return false;
//             }
//         }
//         else
//         {
//             std::cout << "Invalid input: 'f' must be at the end" << std::endl;
//             return false;
//         }
//     }
//     else
//     {
//         // Permitir letras, números y caracteres especiales
//         for (size_t i = 0; i < input.size(); ++i)
//         {
//             char c = input[i];
//             if (!isdigit(c) && c != '.' && !isalpha(c))
//             {
//                 std::cout << "Invalid input: Contains non-numeric characters" << std::endl;
//                 return false;
//             }
//         }

//         return true;
//     }
// }

void printError(const std::string& errorMessage)
{
    std::cout << "Error: " << errorMessage << std::endl;
}

bool isValidInput(const std::string& input)
{
    if (input == "inf" || input == "-inf" || input == "+inf")
        return true;
    if (input == "nan" || input == "nanf")
        return true;
    // Permitir letras solas en la entrada
    if (input.size() == 1 && isalpha(static_cast<unsigned char>(input[0])))
    {
        return true;
    }
    // Permitir que el argumento empiece con '+' o '-'
    if (!input.empty() && (input[0] == '+' || input[0] == '-'))
        return true;
    // Verificar si la entrada es un número decimal con la letra 'f' al final
    size_t fPosition = input.find('f');

    if (fPosition != std::string::npos)
    {
        // Verificar que 'f' está al final
        if (fPosition == input.size() - 1)
        {
            // Verificar que los caracteres antes de 'f' son dígitos o un punto decimal
            bool validNumericPart = true;
            for (size_t i = 0; i < fPosition; ++i)
            {
                char c = input[i];
                if (!isdigit(static_cast<unsigned char>(c)) && c != '.')
                {
                    validNumericPart = false;
                    break;
                }
            }

            if (validNumericPart)
            {
                return true;
            }
            else
            {
                printError("Invalid input: Contains non-numeric characters before 'f'");
                return false;
            }
        }
        else
        {
            printError("Invalid input: 'f' must be at the end");
            return false;
        }
    }
    else
    {
        // Permitir letras, números y caracteres especiales
        bool decimalFound = false;
        for (size_t i = 0; i < input.size(); ++i)
        {
            char c = input[i];
            if (!isdigit(static_cast<unsigned char>(c)) && c != '.')
            {
                if (c == 'f' && i == input.size() - 1 && decimalFound)
                {
                    // 'f' at the end is allowed after decimal numbers
                    return true;
                }
                else
                {
                    printError("Invalid input: Contains non-numeric characters");
                    return false;
                }
            }
            else if (c == '.')
            {
                if(input[i + 1] == '\0')
                {
                    printError("Invalid input: Contains non-numeric characters");
                    return false;
                }
                // Check if there are digits after the decimal point
                decimalFound = true;
            }
        }

        return true;
    }
}

int main(int argc, char **argv)
{
    try {
        if (argc != 2) {
            std::cout << "Usage: ./convert arg" << std::endl;
            return 1;
        }
        std::string input(argv[1]); // Convertir el argumento a std::string
        // Validar la entrada antes de intentar procesarla
        if (!isValidInput(input)) {
            return 1; // Salir con código de error
        }
        ScalarConverter::convert(input);
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}