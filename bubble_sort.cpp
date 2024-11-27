#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> 
#include <string>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) break;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <nombre_archivo>" << std::endl;
        return 1;
    }

    std::string nombreArchivo = argv[1];
    std::ifstream archivo(nombreArchivo);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return 1;
    }
 
    std::vector<int> numeros;
    int numero;
    while (archivo >> numero) {
        numeros.push_back(numero);
    }
    archivo.close();

    auto inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(numeros);
    auto fin = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << "Tiempo de ejecución del Bubble Sort: " << duracion.count() << " segundos" << std::endl;
    return 0;
}
