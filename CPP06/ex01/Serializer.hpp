/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:54:00 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/08 12:20:53 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer const &serial);
        Serializer &operator=(Serializer const &other);
    public:
         static uintptr_t serialize(Data* ptr);
         static Data* deserialize(uintptr_t raw);   
};

#endif