/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:12 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/18 14:13:40 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    //std::cout << "BitcoinExchange default constructor called!" << std::endl;
    return ;
}

BitcoinExchange::BitcoinExchange(const std::string &csvFileName)
{
    try
    {
        // Pass the second argument, which is a reference to exchangeRates
        loadExchangeRates(csvFileName, exchangeRates);
    }
    catch (const BitcoinException &e)
    {
        // Propagate the exception with a more informative message
        throw BitcoinException("Error opening exchange rate file: " + std::string(e.what()));
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &btc)
{
    //std::cout << "BitcoinExchange copy constructor called!" << std::endl;
    exchangeRates = btc.exchangeRates;
}

BitcoinExchange::~BitcoinExchange()
{
    //std::cout << "BitcoinExchange destructor called!" << std::endl;
    return ;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        exchangeRates = other.exchangeRates;
    return (*this);
}

bool BitcoinExchange::loadExchangeRates(const std::string& filename, std::map<std::string, float>& exchangeRates) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float rate;

        if (iss >> date >> rate) {
            exchangeRates[date] = rate;
        }
    }

    return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date, const std::map<std::string, float>& exchangeRates) {
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);

    if (it == exchangeRates.begin() && it->first > date) {
        throw std::runtime_error("Date not found in the database.");
    }

    if (it == exchangeRates.end()) {
        --it; // Use the closest lower date
    } else if (it->first != date && it != exchangeRates.begin()) {
        --it; // Use the closest lower date
    }

    return it->second;
}