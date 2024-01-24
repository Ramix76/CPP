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
bool buscarCoincidenciaExacta(const std::map<Fecha, bool>& fechasData, const Fecha& fechaInput) {
    return fechasData.find(fechaInput) != fechasData.end();
}

// Función para buscar la fecha más cercana
Fecha buscarFechaCercana(const std::map<Fecha, bool>& fechasData, const Fecha& fechaInput) {
    std::map<Fecha, bool>::const_iterator it = fechasData.lower_bound(fechaInput);

    if (it != fechasData.begin()) {
        --it;
    }

    return it->first;
}

// Función principal para procesar el archivo de entrada
void procesarArchivos(const char* inputFileName) {
    std::ifstream archivo2(inputFileName);

    if (!archivo2.is_open()) {
        std::cerr << "Error al abrir el archivo " << inputFileName << std::endl;
        return;
    }

    std::map<Fecha, bool> fechasData;

    // Leer fechas de data.csv y almacenar en el mapa
    std::ifstream archivo1("data.csv");
    if (!archivo1.is_open()) {
        std::cerr << "Error al abrir el archivo data.csv" << std::endl;
        return;
    }

    std::string linea1;
    while (getline(archivo1, linea1)) {
        Fecha fecha;
        extraerFecha(linea1, fecha);
        fechasData[fecha] = true;
    }
    archivo1.close();

    std::string linea2;

    while (getline(archivo2, linea2)) {
        Fecha fechaInput;
        extraerFecha(linea2, fechaInput);

        // Buscar coincidencia exacta
        if (buscarCoincidenciaExacta(fechasData, fechaInput)) {
            std::cout << "Se encontró una coincidencia exacta para la fecha en " << inputFileName << "." << std::endl;
        } else {
            // Buscar fecha más cercana
            Fecha fechaCercana = buscarFechaCercana(fechasData, fechaInput);

            std::cout << "No se encontró una coincidencia exacta para la fecha en " << inputFileName << "." << std::endl;
            std::cout << "La fecha más cercana en data.csv es: " << fechaCercana.anio << "-" << fechaCercana.mes << "-" << fechaCercana.dia << std::endl;
        }
    }

    archivo2.close();
}

