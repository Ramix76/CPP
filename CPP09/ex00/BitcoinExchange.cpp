#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    //std::cout << "BitcoinExchange default constructor called!" << std::endl;
    return ;
}

// BitcoinExchange::BitcoinExchange(const std::string &csvFileName)
// {
//     // try
//     // {
//     //     // Pass the second argument, which is a reference to exchangeRates
//     //     loadExchangeRates(csvFileName, exchangeRates);
//     // }
//     // catch (const BitcoinException &e)
//     // {
//     //     // Propagate the exception with a more informative message
//     //     throw BitcoinException("Error opening exchange rate file: " + std::string(e.what()));
//     // }
// }

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

// Implementación del método compareDates
void BitcoinExchange::compareDates(const std::string &inputFileName)
{
    std::ifstream inputFile(inputFileName);
    std::string line;

    if (!inputFile.is_open())
    {
        throw BitcoinException("Error opening input file");
    }

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string date, value;

        // Leer fecha y valor desde el archivo input.txt
        if (!(iss >> date >> value))
        {
            throw BitcoinException("Invalid format in input file");
        }

        // Comprobar si la fecha existe en el mapa de tasas de cambio
        if (exchangeRates.find(date) != exchangeRates.end())
        {
            std::cout << "Fecha encontrada: " << date << " Valor: " << exchangeRates[date] << std::endl;
        }
        else
        {
            std::cout << "Fecha no encontrada: " << date << std::endl;
        }
    }

    inputFile.close();
}