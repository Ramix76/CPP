#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    public:
        void loadDatabase(const std::string& filename);
        std::string getClosestDate(const std::string& inputDate) const;
        float getExchangeRate(const std::string& date) const;

    private:
        std::map<std::string, float> exchangeRates;
};

#endif 