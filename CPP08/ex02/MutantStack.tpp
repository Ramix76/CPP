/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:20 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/10 15:18:23 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &mut) : std::stack<T>(mut)
{
    //std::cout << "MutantStack copy constructor called!" << std::endl;
    return ;
}

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    //std::cout << "MutantStack constructor called!" << std::endl;
    return ;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    //std::cout << "MutantStack destructor called!" << std::endl;
    return ;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return (*this);
}

template <typename T>
typename MutantStack<T>::container_iterator MutantStack<T>::begin()
{
   return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::container_iterator MutantStack<T>::end()
{
   return (this->c.end());
}

#endif
