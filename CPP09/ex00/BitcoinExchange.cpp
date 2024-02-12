#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        // Handle error opening file
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        if (std::getline(iss, dateStr, ',') && std::getline(iss, valueStr))
        {
            try
            {
                float value = std::stof(valueStr);
                exchangeRates[dateStr] = value;
            }
            catch (const std::invalid_argument& e)
            {
                // Handle invalid argument
            }
            catch (const std::out_of_range& e)
            {
                // Handle out of range
            }
        }
    }
}

std::string BitcoinExchange::getClosestDate(const std::string& inputDate) const
{
    if (exchangeRates.empty())
    {
        return "";  // No closest date if the exchangeRates map is empty
    }
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(inputDate);
    if (it == exchangeRates.begin())
    {
        return it->first;  // Input date is before the first date in the map
    }
    if (it == exchangeRates.end())
    {
        --it;  // Input date is after the last date in the map
    }
    else
    {
        // Check which date is closer, the one at 'it' or the one before it
        std::map<std::string, float>::const_iterator prevIt = std::prev(it);
        if (inputDate.compare(prevIt->first) - inputDate.compare(it->first) > 0)
        {
            it = prevIt;
        }
    }
    return it->first;
}
float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
    if (it != exchangeRates.end())
    {
        return it->second;
    }
    else
    {
        // Handle the case where the date is not found
        return 0.0f; // Placeholder, replace with actual implementation
    }
}