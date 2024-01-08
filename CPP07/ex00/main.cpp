/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:19:54 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/08 13:38:03 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void )
{
    int a = 2;
    int b = 3;
    
    std::cout << "Initial: a = " << a << " ,Initial: b = " << b << std::endl;
    ::swap( a, b );
    std::cout << "Swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::cout << "\n" << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    std::cout << "Initial: c = " << c << ",Initial d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "Swap: c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return (0);
}
