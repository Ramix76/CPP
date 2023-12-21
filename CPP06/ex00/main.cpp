/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:02:11 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/21 15:16:43 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    try {
        if (argc != 2) {
            std::cout << "Usage: ./convert arg" << std::endl;
            return 1;
        }
        std::string input(argv[1]); // Convertir el argumento a std::string
        ScalarConverter::convert(input);
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}