/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:47:18 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/08 12:48:09 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cmath>
#include <iostream>

Base* generate() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int choice = rand() % 3;
    switch(choice) {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != nullptr) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != nullptr) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    identify(&p);
}