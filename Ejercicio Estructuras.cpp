#include <iostream>
using namespace std;

// aquí ya definimos la estructura struct
struct VectorDeValores {
    float *valores;// puntero a float
    int tam;// tamaño del array

    // constructor por defecto
    VectorDeValores() {
        tam = 2; // ya asignamos aquí nuestra variable 
        valores = new float[tam]; // pedimos memoria dinámica para los float 
        for (int i = 0; i < tam; i++) // recorremos el arreglo 
            valores[i] = 0; // inicializamos en 0
        cout << "Constructor de vector tamaño " << tam << endl;
    }

    // constructor con parámetros
    VectorDeValores(float *arr, int t) {
        tam = t; // se asigna el tamaño 
        valores = new float[tam]; // guarda memoria para el número de elementos 
        for (int i = 0; i < tam; i++) // copia los arreglos que recibió 
            valores[i] = arr[i];
        cout << "Constructor con parámetros: " << tam << " elementos creados." << endl;
    }

    // destructor 
    ~VectorDeValores() {
        cout << "Se están liberando " << tam << " elementos" << endl;
        delete[] valores; // libera la memoria dinámica del arreglo 
    }

    // mostramos lo que contiene nuestro vector 
    void mostrar() {
        cout << "Valores del vector: ";
        for (int i = 0; i < tam; i++) { // va recorriendo el arreglo 
            cout << valores[i] << " ";
        }
        cout << endl;
    }
};

// función principal del programa 
int main() {
    cout << "Prueba constructor por defecto " << endl;
    VectorDeValores v1; // crea un objeto usando el constructor por defecto
    v1.mostrar(); // muestra los valores 

    cout << "\nPrueba constructor con parámetros" << endl;
    float datos[] = {1.5, 2.7, 3.9, 4.2}; // ejemplo de arreglo con 4 valores 
    VectorDeValores v2(datos, 4);// crea otro objeto con los valores 
    v2.mostrar();// muestra su contenido copiado

    cout << "\nAhora creo que sí me salió profe :)" << endl;
    return 0;
}