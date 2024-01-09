/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:28:36 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/09 12:05:50 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Crear un array vacío y mostrar su tamaño
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl;

        // Crear un array de 5 elementos e inicializarlos con valores
        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl;

        for (unsigned int i = 0; i < arr2.size(); ++i) {
            arr2[i] = i * 2;
        }

        std::cout << "Elements of arr2: ";
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        // Copiar un array y modificar la copia
        Array<int> arr3 = arr2;
        arr3[2] = 100;

        std::cout << "Elements of arr2 after modifying arr3: ";
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Elements of arr3: ";
        for (unsigned int i = 0; i < arr3.size(); ++i) {
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;

        // Intentar acceder a un índice fuera de los límites del array
        std::cout << "Trying to access out-of-bounds index..." << std::endl;
        std::cout << arr2[10] << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
