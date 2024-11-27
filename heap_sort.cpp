#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> 
#include <string>


void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;        
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  

    
    if (left < n && arr[left] > arr[largest])
        largest = left;

    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        
        heapify(arr, n, largest);
    }
}


void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    
    for (int i = n - 1; i > 0; --i) {
        
        std::swap(arr[0], arr[i]);

        
        heapify(arr, i, 0);
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
    heapSort(numeros);
    auto fin = std::chrono::high_resolution_clock::now();
 
    std::chrono::duration<double> duracion = fin - inicio;
   
    std::cout << "Tiempo de ejecución del Heap Sort: " << duracion.count() << " segundos" << std::endl;

    return 0;
}
