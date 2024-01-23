/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:40 by framos-p          #+#    #+#             */
/*   Updated: 2024/01/22 14:37:19 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

struct DataEntry {
    std::string date;
    double exchange_rate;
};

struct InputEntry {
    std::string date;
    double bitcoins;
};

DataEntry parseCSVLine(const std::string& line) {
    DataEntry entry;
    std::istringstream ss(line);
    std::getline(ss, entry.date, ',');
    ss >> entry.exchange_rate;
    return entry;
}

InputEntry parseInputLine(const std::string &line)
{
    InputEntry entry;
    std::istringstream ss(line);
    char delimiter;

    if (!(std::getline(ss, entry.date, '|') && ss >> entry.bitcoins >> delimiter))
    {
        entry.date = ""; // Marcar la fecha como inválida
    }
    return entry;
}

std::vector<DataEntry> readCSVFile(const std::string& filename) {
    std::vector<DataEntry> data;
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return data;
    }

    std::string line;
    std::getline(file, line); // Saltar la primera línea que contiene los encabezados

    while (std::getline(file, line)) {
        data.push_back(parseCSVLine(line));
    }

    file.close();
    return data;
}

std::vector<InputEntry> readInputFile(const std::string& filename) {
    std::vector<InputEntry> input;
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return input;
    }

    std::string line;
    while (std::getline(file, line)) {
        input.push_back(parseInputLine(line));
    }

    file.close();
    return input;
}

std::tm convertToDateCSV(const std::string& date) {
    std::tm time = {};
    std::istringstream ss(date);
    char dash;
    if (!(ss >> std::get_time(&time, "%Y-%m-%d") && (ss >> dash || ss >> time.tm_sec))) {
        // Manejar el formato de fecha inválido
        throw BitcoinExchange::BitcoinException("Formato de fecha inválido en data.csv: " + date);
    }
    return time;
}

std::tm convertToDateInput(const std::string& date) {
    std::tm time = {};
    std::istringstream ss(date);
    char dash;
    if (!(ss >> std::get_time(&time, "%Y-%m-%d") && ss >> dash && dash == '|' && ss >> time.tm_sec)) {
        // Manejar el formato de fecha inválido
        throw BitcoinExchange::BitcoinException("Formato de fecha inválido en input.txt: " + date);
    }
    return time;
}

int dateDifference(const std::string& date1, const std::string& date2) {
    std::tm tm1 = convertToDateCSV(date1);
    std::tm tm2 = convertToDateInput(date2);

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    const int secondsPerDay = 60 * 60 * 24;
    return std::abs(static_cast<int>(std::difftime(time1, time2) / secondsPerDay));
}

bool findDate(const std::vector<DataEntry> &data, const std::string &targetDate, DataEntry &result)
{
    for (std::vector<DataEntry>::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        if (it->date == targetDate)
        {
            result = *it;
            return true; // Fecha exacta encontrada
        }
    }
    return false; // Fecha exacta no encontrada
}

bool findClosestDate(const std::vector<DataEntry> &data, const std::string &targetDate, DataEntry &result)
{
    int closestDifference = std::numeric_limits<int>::max();

    for (std::vector<DataEntry>::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        const DataEntry &entry = *it;
        int difference = dateDifference(entry.date, targetDate);
        if (difference <= closestDifference)
        {
            closestDifference = difference;
            result = entry;
        }
    }

    return closestDifference != std::numeric_limits<int>::max();
}

int main() {
    std::vector<DataEntry> data = readCSVFile("data.csv");
    std::vector<InputEntry> input = readInputFile("input.txt");

    if (input.empty() || data.empty()) {
        std::cerr << "Error: Archivos de entrada vacíos." << std::endl;
        return 1;
    }

    for (std::vector<InputEntry>::iterator inputIt = input.begin(); inputIt != input.end(); ++inputIt) {
        if (inputIt->date.empty()) {
            std::cerr << "Error: Formato de fecha incorrecto en input.txt para la entrada con bitcoins " << inputIt->bitcoins << std::endl;
            continue;  // Salta a la siguiente iteración si hay un error en el formato de fecha
        }

        std::string targetDate = inputIt->date;
        DataEntry result;

        if (findDate(data, targetDate, result) || findClosestDate(data, targetDate, result)) {
            std::cout << "Fecha: " << result.date << ", Tipo de cambio: " << result.exchange_rate << ", Bitcoins: " << inputIt->bitcoins;
            double inputValue = inputIt->bitcoins;
            double resultado = inputValue * result.exchange_rate;
            std::cout << ", Resultado de la multiplicación: " << resultado << std::endl;
        } else {
            std::cerr << "No se encontró una fecha válida en data.csv para la entrada: " << targetDate << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }

    return 0;
}

// struct DataEntry {
//     std::string date;
//     double exchange_rate;
// };

// struct InputEntry {
//     std::string date;
//     double bitcoins;
// };

// DataEntry parseCSVLine(const std::string& line) {
//     DataEntry entry;
//     std::istringstream ss(line);
//     std::getline(ss, entry.date, ',');
//     ss >> entry.exchange_rate;
//     return entry;
// }

// InputEntry parseInputLine(const std::string& line) {
//     InputEntry entry;
//     std::istringstream ss(line);
//     if (!(std::getline(ss, entry.date, '|') && ss >> entry.bitcoins)) {
//         // Error de formato en la línea
//         entry.date = "";  // Marcar la fecha como inválida
//     }
//     return entry;
// }

// std::vector<DataEntry> readCSVFile(const std::string& filename) {
//     std::vector<DataEntry> data;
//     std::ifstream file(filename.c_str());
    
//     if (!file.is_open()) {
//         std::cerr << "Error al abrir el archivo: " << filename << std::endl;
//         return data;
//     }

//     std::string line;
//     std::getline(file, line); // Saltar la primera línea que contiene los encabezados

//     while (std::getline(file, line)) {
//         data.push_back(parseCSVLine(line));
//     }

//     file.close();
//     return data;
// }

// std::vector<InputEntry> readInputFile(const std::string& filename) {
//     std::vector<InputEntry> input;
//     std::ifstream file(filename.c_str());
    
//     if (!file.is_open()) {
//         std::cerr << "Error al abrir el archivo: " << filename << std::endl;
//         return input;
//     }

//     std::string line;
//     while (std::getline(file, line)) {
//         input.push_back(parseInputLine(line));
//     }

//     file.close();
//     return input;
// }

// std::tm convertToDate(const std::string& date, const std::string& format) {
//     std::tm time = {};
//     std::istringstream ss(date);
//     ss >> std::get_time(&time, format.c_str());
//     return time;
// }

// bool findDate(const std::vector<DataEntry>& data, const std::string& targetDate, DataEntry& result) {
//     for (std::vector<DataEntry>::const_iterator it = data.begin(); it != data.end(); ++it) {
//         if (it->date == targetDate) {
//             result = *it;
//             return true; // Fecha exacta encontrada
//         }
//     }
//     return false; // Fecha exacta no encontrada
// }

// bool findClosestDate(const std::vector<DataEntry>& data, const std::string& targetDate, DataEntry& result) {
//     for (std::vector<DataEntry>::const_iterator it = data.begin(); it != data.end(); ++it) {
//         if (it->date >= targetDate) {
//             // Encontramos una fecha mayor o igual, retrocedemos una posición
//             if (it != data.begin()) {
//                 --it;
//             }
//             result = *it;
//             return true;
//         }
//     }

//     // Si no se encontró ninguna fecha mayor o igual, tomar la última como la más cercana (anterior)
//     if (!data.empty()) {
//         result = data.back();
//         return true;
//     }

//     return false;
// }

// int main() {
//     std::vector<DataEntry> data = readCSVFile("data.csv");
//     std::vector<InputEntry> input = readInputFile("input.txt");

//     if (input.empty() || data.empty()) {
//         std::cerr << "Error: Archivos de entrada vacíos." << std::endl;
//         return 1;
//     }

//     for (std::vector<InputEntry>::iterator inputIt = input.begin(); inputIt != input.end(); ++inputIt) {
//         if (inputIt->date.empty()) {
//             std::cerr << "Error: Formato de fecha incorrecto en input.txt para la entrada con bitcoins " << inputIt->bitcoins << std::endl;
//             continue;  // Salta a la siguiente iteración si hay un error en el formato de fecha
//         }

//         std::string targetDate = inputIt->date;
//         DataEntry result;

//         if (findDate(data, targetDate, result)) {
//             std::cout << "Fecha exacta encontrada: " << targetDate << ", Tipo de cambio: " << result.exchange_rate << std::endl;
//             std::cout << "Bitcoins: " << inputIt->bitcoins << std::endl;
//             double inputValue = inputIt->bitcoins;
//             double resultado = inputValue * result.exchange_rate;
//             std::cout << "Resultado de la multiplicación: " << resultado << std::endl;
//         } else if (findClosestDate(data, targetDate, result)) {
//             std::cout << "Fecha más cercana (anterior): " << result.date << ", Tipo de cambio: " << result.exchange_rate << std::endl;
//             std::cout << "Bitcoins: " << inputIt->bitcoins << std::endl;
//             double inputValue = inputIt->bitcoins;
//             double resultado = inputValue * result.exchange_rate;
//             std::cout << "Resultado de la multiplicación: " << resultado << std::endl;
//         } else {
//             std::cerr << "No se encontró una fecha válida en data.csv para la entrada: " << targetDate << std::endl;
//         }
//         std::cout << "---------------------------------" << std::endl;
//     }

//     return 0;
// }