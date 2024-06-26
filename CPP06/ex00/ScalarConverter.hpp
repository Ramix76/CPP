/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:34:16 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/18 10:59:49 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <iomanip>
# include <cmath>
# include <cfloat>
# include <cctype>
# include <cstdlib>

class ScalarConverter
{
    public:
        static void convert(const std::string &str);
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &sc);
        ScalarConverter &operator=(ScalarConverter const &other);
        static bool isCharRepresentable(char c);
        static void printCharInfo(char c);
        static void printAsciiInfo(int asciiValue);
};

#endif