#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <input.txt>" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange bitcoinExchange("data.csv");
        bitcoinExchange.compareDates(argv[1]);
    }
    catch (const BitcoinExchange::BitcoinException &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}