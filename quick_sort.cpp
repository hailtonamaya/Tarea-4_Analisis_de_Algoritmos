#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> 
#include <string>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]); 
        }
    }
    std::swap(arr[i + 1], arr[high]); 
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(numeros, 0, numeros.size() - 1);
    auto fin = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << "Tiempo de ejecución del Quick Sort: " << duracion.count() << " segundos" << std::endl;

    return 0;
}
