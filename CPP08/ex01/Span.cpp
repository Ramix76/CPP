/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:36:48 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/10 11:48:13 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    //std::cout << "Span default constructor called!" << std::endl;
    return ;
}

Span::Span(Span const &sp)
{
    //std::cout << "Span copy constructor called!" << std::endl;
    *this = sp;
    return ;
}

Span::Span(unsigned int size) : N(size)
{
    //std::cout << "Span constructor called!" << std::endl;
    return ;
}

Span::~Span()
{
    //std::cout << "Span destructor called!" << std::endl;
    return ;
}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
        return (*this);
    return (*this);
}

void Span::addNumber(int num)
{
    if (numbers.size() >= N)
        throw SpanException("Span id full");
    numbers.push_back(num);
}

void Span::addRange(const std::vector<int> &newNumbers)
{
    if (numbers.size() + newNumbers.size() > N)
        throw SpanException("Adding this range exceeds the size limit of Span");
    for (size_t i = 0; i < newNumbers.size(); ++i)
        addNumber(newNumbers[i]);
}

int Span::shortestSpan() const
{
    if (numbers.size() <= 1)
        throw SpanException("Cannot find span with fewer than 2 numbers");
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 2; i < sortedNumbers.size(); ++i)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return (minSpan);
}

int Span::longestSpan() const
{
    if (numbers.size() <= 1)
        throw SpanException("Cannot find span with fewer than 2 numbers");
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return (max - min);
}

unsigned int Span::getSize() const
{
    return (numbers.size());
}

int Span::getElementAt(unsigned int index) const
{
    if (index >= numbers.size())
        throw SpanException("Index out of range");
    return (numbers[index]);
}