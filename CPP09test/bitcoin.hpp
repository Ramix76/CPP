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
};

void extraerFecha(const std::string& linea, Fecha& fecha);
int compararFechas(const Fecha& fecha1, const Fecha& fecha2);
bool buscarCoincidenciaExacta(const std::vector<Fecha>& fechasData, const Fecha& fechaInput);
int buscarFechaCercana(const std::vector<Fecha>& fechasData, const Fecha& fechaInput);
void procesarArchivos(const char* inputFileName);

#endif