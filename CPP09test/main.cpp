#include "bitcoin.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    procesarArchivos(argv[1]);

    return 0;
}