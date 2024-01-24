#ifndef BITCOIN_HPP
#define BITCOIN_HPP

# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <vector>
# include <iomanip>
# include <iostream>

// Estructura para representar una fecha
struct Fecha {
    int anio;
    int mes;
    int dia;

    // Add comparison operator for Fecha
    bool operator<(const Fecha& other) const {
        if (anio != other.anio) return anio < other.anio;
        if (mes != other.mes) return mes < other.mes;
        return dia < other.dia;
    }
};

void extraerFecha(const std::string& linea, Fecha& fecha);
bool buscarCoincidenciaExacta(const std::map<Fecha, bool>& fechasData, const Fecha& fechaInput);
Fecha buscarFechaCercana(const std::map<Fecha, bool>& fechasData, const Fecha& fechaInput);
void procesarArchivos(const char* inputFileName);

#endif