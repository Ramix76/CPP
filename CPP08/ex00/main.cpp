/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:54:14 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/10 10:40:05 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "Container size: " << vec.size() << std::endl;
    std::cout << "\n";
    try
    {
        std::cout << "Looking for Value 3 position..." << std::endl;
        std::vector<int>::iterator result = easyfind(vec, 3);

        std::cout << "Value 3 found at position: " << std::distance(vec.begin(), result) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n";
    try
    {
        std::cout << "Looking for Value 6 position..." << std::endl;
        std::vector<int>::iterator result = easyfind(vec, 6);
        std::cout << "Value 6 found at position: " << std::distance(vec.begin(), result) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n";
    return 0;
}
