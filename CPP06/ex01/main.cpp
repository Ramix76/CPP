/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:19:09 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/08 12:21:48 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int     main( void )
{
        Data data;
        data.value = 3;
        data.text = "hello";

        std::cout << "<---------- Before serialization and deserialization ---------->" << std::endl;
        std::cout << data.value << std::endl;
        std::cout << data.text << std::endl;

        uintptr_t data_serial = Serializer::serialize(&data);
        Data * data_deserial = Serializer::deserialize(data_serial);

        std::cout << "<---------- After serialization and deserialization ----------->" << std::endl;
        std::cout << data_deserial->value << std::endl;
        std::cout << data_deserial->text << std::endl;
}                  
