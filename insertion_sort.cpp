#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> 
#include <string>


void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
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
    insertionSort(numeros);
    auto fin = std::chrono::high_resolution_clock::now();
   
    std::chrono::duration<double> duracion = fin - inicio;
   
    std::cout << "Tiempo de ejecución del Insertion Sort: " << duracion.count() << " segundos" << std::endl;

    return 0;
}
