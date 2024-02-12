#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "BitcoinExchange.hpp"

float calculateResult(float inputValue, float exchangeRate)
{
    return inputValue * exchangeRate;
}

std::tm parseDate(const std::string& dateStr)
{
    std::tm tm = {};
    std::istringstream dateStream(dateStr);
    // Intenta leer las partes de la fecha
    int year, month, day;
    char dash1, dash2;

    dateStream >> year >> dash1 >> month >> dash2 >> day;
    if (dateStream.fail() || dash1 != '-' || dash2 != '-')
        throw std::invalid_argument("Invalid date format");
    tm.tm_year = year - 1900; // Año desde 1900 en std::tm
    tm.tm_mon = month - 1;    // Meses en std::tm van de 0 a 11
    tm.tm_mday = day;
    // Validación del año (4 dígitos)
    if (tm.tm_year < 0 || tm.tm_year > 9999)
        throw std::invalid_argument("Invalid year format");
    // Validación del mes (rango de 0 a 11)
    if (tm.tm_mon < 0 || tm.tm_mon > 11)
        throw std::invalid_argument("Invalid month format");
    // Validación del día (rango de 1 a 31)
    if (tm.tm_mday < 1 || tm.tm_mday > 31)
        throw std::invalid_argument("Invalid day format");
    // Validación de días según el mes
    if ((tm.tm_mon == 0 || tm.tm_mon == 2 || tm.tm_mon == 4 || tm.tm_mon == 6 ||
         tm.tm_mon == 7 || tm.tm_mon == 9 || tm.tm_mon == 11) && tm.tm_mday > 31)
        throw std::invalid_argument("Invalid day for this month");
    else if ((tm.tm_mon == 3 || tm.tm_mon == 5 || tm.tm_mon == 8 || tm.tm_mon == 10) && tm.tm_mday > 30)
        throw std::invalid_argument("Invalid day for this month");
    else if (tm.tm_mon == 1)
    {
        // Febrero: 28 días en condiciones normales, 29 días en años bisiestos
        bool leapYear = (tm.tm_year % 4 == 0 && tm.tm_year % 100 != 0) || (tm.tm_year % 400 == 0);
        if (leapYear && tm.tm_mday > 29)
            throw std::invalid_argument("Invalid day for this month");
        else if (!leapYear && tm.tm_mday > 28)
            throw std::invalid_argument("Invalid day for this month");
    }
    return tm;
}

bool validateInput(float value)
{
    if (value < 0.0f)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000.0f)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " input.txt" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.loadDatabase("data.csv");
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        float value;
        if (std::getline(iss, dateStr, '|') && std::getline(iss, valueStr))
        {
            std::istringstream valueStream(valueStr);
            valueStream >> value;
            if (valueStream.fail())
            {
                std::cerr << "Error: Invalid float value." << std::endl;
                continue;
            }
            try
            {
                // Validar el valor antes de continuar
                if (!validateInput(value))
                    continue;
                std::tm parsedDate = parseDate(dateStr);
                std::ostringstream formattedDate;
                formattedDate << std::put_time(&parsedDate, "%Y-%m-%d");
                std::string parsedDateString = formattedDate.str();
                std::string closestDate = exchange.getClosestDate(parsedDateString);
                float exchangeRate = exchange.getExchangeRate(closestDate);
                float result = calculateResult(value, exchangeRate);
                if (result > std::numeric_limits<int>::max())
                {
                    std::cerr << "Error: Result exceeds the maximum int value." << std::endl;
                    continue;
                }
                std::cout << parsedDateString << " => " << value << " * " << exchangeRate << " = " << result << std::endl;
            }
            catch (const std::invalid_argument& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
                continue;
            }
            catch (const std::out_of_range& e)
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
    return 0;
}