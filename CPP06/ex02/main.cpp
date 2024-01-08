/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:37:05 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/08 12:46:19 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *  generate ( void );
void    identify(Base* p);
void    identify(Base& p);

int     main( void )
{
        Base *base = generate();
        std::cout <<  "<---- Identify with pointer ---->" << std::endl;
        identify(base);
        std::cout <<  "<---- Identify with reference ---->" << std::endl;
        identify(*base);

        delete base;

        return (0);
}
