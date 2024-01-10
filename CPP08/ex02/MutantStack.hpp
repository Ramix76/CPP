/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:57:50 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/10 15:17:46 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <algorithm>
# include <string>

template <typename T>

class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &mut);
        virtual ~MutantStack();
        MutantStack &operator=(const MutantStack &other);

        typedef typename std::stack<T>::container_type::iterator container_iterator;
        container_iterator begin();
        container_iterator end();
        
    private:
};

#endif
