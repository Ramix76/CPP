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
        // BitcoinExchange(const std::string &csvFileName);
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

        void compareDates(const std::string &inputFileName);
};

#endif