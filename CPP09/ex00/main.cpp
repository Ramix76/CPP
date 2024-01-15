/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:40 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/15 10:26:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Missing input file argument." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, float> exchangeRates;
    if (!exchange.loadExchangeRates("data.csv", exchangeRates)) {
        std::cerr << "Error: Could not load exchange rates." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date;
        float value;

        if (!(iss >> date >> value)) {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }

        try {
            float exchangeRate = exchange.getExchangeRate(date, exchangeRates);
            std::cout << date << " => " << value << " = " << (value * exchangeRate) << std::endl;
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}