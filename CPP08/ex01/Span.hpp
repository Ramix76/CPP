/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:36:41 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/10 11:45:55 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <string>

class Span
{
    public:
        Span(unsigned int size);
        Span(Span const &sp);
        ~Span();
        Span &operator=(Span const &other);
        
        void addNumber(int num);
        void addRange(const std::vector<int> &newNumbers);
        int shortestSpan() const;
        int longestSpan() const;
        unsigned int getSize() const;
        int getElementAt(unsigned int index) const;
                
    private:
        unsigned int N;
        std::vector<int> numbers;
        Span();

        class SpanException : public std::exception
        {
            private:
                std::string message;
            
            public:
                SpanException(const std::string &msg) : message(msg) {}
                virtual const char *what() const throw()
                {
                    return (message.c_str());
                }
                virtual ~SpanException() throw() {}
        };
};

#endif
