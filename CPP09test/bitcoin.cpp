#include "bitcoin.hpp"

// Función para extraer la fecha del formato "año-mes-dia"
void extraerFecha(const std::string& linea, Fecha& fecha) {
    sscanf(linea.c_str(), "%d-%d-%d", &fecha.anio, &fecha.mes, &fecha.dia);
}

// Función para comparar dos fechas
int compararFechas(const Fecha& fecha1, const Fecha& fecha2) {
    if (fecha1.anio != fecha2.anio) return fecha1.anio - fecha2.anio;
    if (fecha1.mes != fecha2.mes) return fecha1.mes - fecha2.mes;
    return fecha1.dia - fecha2.dia;
}

// Función para buscar coincidencia exacta
bool buscarCoincidenciaExacta(const std::vector<Fecha>& fechasData, const Fecha& fechaInput) {
    for (size_t j = 0; j < fechasData.size(); ++j) {
        if (compararFechas(fechaInput, fechasData[j]) == 0) {
            return true;
        }
    }
    return false;
}

// Función para buscar la fecha más cercana
int buscarFechaCercana(const std::vector<Fecha>& fechasData, const Fecha& fechaInput) {
    int mejorCoincidencia = 0;
    for (size_t j = 1; j < fechasData.size(); ++j) {
        if (compararFechas(fechasData[j], fechaInput) <= 0 &&
            compararFechas(fechasData[j], fechaInput) > compararFechas(fechasData[mejorCoincidencia], fechaInput)) {
            mejorCoincidencia = j;
        } else if (compararFechas(fechasData[j], fechaInput) > 0 &&
                   compararFechas(fechasData[j], fechaInput) < compararFechas(fechasData[mejorCoincidencia], fechaInput)) {
            mejorCoincidencia = j;
        }
    }
    return mejorCoincidencia;
}

// Función principal para procesar el archivo de entrada
void procesarArchivos(const char* inputFileName) {
    std::ifstream archivo1("data.csv");
    std::ifstream archivo2(inputFileName);

    if (!archivo1.is_open() || !archivo2.is_open()) {
        std::cerr << "Error al abrir los archivos." << std::endl;
        return;
    }

    std::vector<Fecha> fechasData;

    // Leer fechas de data.csv
    std::string linea1;
    while (getline(archivo1, linea1)) {
        Fecha fecha;
        extraerFecha(linea1, fecha);
        fechasData.push_back(fecha);
    }

    // Procesar cada línea de input.txt por separado
    std::string linea2;
    while (getline(archivo2, linea2)) {
        Fecha fechaInput;
        extraerFecha(linea2, fechaInput);

        // Buscar coincidencia exacta
        if (buscarCoincidenciaExacta(fechasData, fechaInput)) {
            std::cout << "Se encontró una coincidencia exacta para la fecha en " << inputFileName << "." << std::endl;
        } else {
            // Buscar fecha más cercana
            int mejorCoincidencia = buscarFechaCercana(fechasData, fechaInput);

            std::cout << "No se encontró una coincidencia exacta para la fecha en " << inputFileName << "." << std::endl;
            std::cout << "La fecha más cercana en data.csv es: " << fechasData[mejorCoincidencia].anio << "-"
                      << fechasData[mejorCoincidencia].mes << "-" << fechasData[mejorCoincidencia].dia << std::endl;
        }
    }

    archivo1.close();
    archivo2.close();
}