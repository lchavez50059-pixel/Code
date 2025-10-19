#pragma once //con esto evitamos que nuestro archivo se incluya mas de una vez y lo vi en W3school
#include <iostream>
using namespace std;

template <typename T>// funcion para imprimir nuestro arreglo de cualquier tipo
void PrintArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {// aqui vamos a recorrer todos los elementos de nuestro arreglo 
        cout << arr[i] << " ";
    }
    cout << endl;
}