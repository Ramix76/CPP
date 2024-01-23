/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:05 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/22 14:37:07 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <vector>
# include <iomanip>
# include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> exchangeRates;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &csvFileName);
        BitcoinExchange(BitcoinExchange const &btc);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &other);

        class BitcoinException : public std::exception
        {
            private:
                std::string message;
            
            public:
                BitcoinException(const std::string &msg) : message(msg) {}
                virtual const char *what() const throw()
                {
                    return (message.c_str());
                }
                virtual ~BitcoinException() throw() {}
        };

        bool loadExchangeRates(const std::string& filename, std::map<std::string, float>& exchangeRates);
        float getExchangeRate(const std::string& date, const std::map<std::string, float>& exchangeRates);          
};

#endif
