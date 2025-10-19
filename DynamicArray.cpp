#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray() {
    count = 0;
    capacity = 2;//es la capacidad que se le asigna 
    data = new T[capacity];//es la memoria para el array
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    copyCounter = 0;
#endif
}

template <typename T>//este es nuestro destructor y  libera la memoria que guardamos para el arreglo
DynamicArray<T>::~DynamicArray() {
    delete[] data;//borramos nuestro arreglo dinamico 
}

template <typename T>//este es nuestro append y agrega un elemento al final del arreglo
void DynamicArray<T>::Append(T value) {
    if (count == capacity) {//aqui si no hay espacio suficiente pues duplicamos la capacidad
        capacity *= 2;
        T* newData = new T[capacity];//se hace un arreglo massss grande 

        for (int i = 0; i < count; i++) {//vamos a copiar los arreglos del viejo al new
            newData[i] = data[i];
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;
#endif
        }

        delete[] data;//borramos el viejo 
        data = newData;//apuntamos el new 
    }
    data[count++] = value;//agregamos el nuevo elemento y aumentamos el contador
}

template <typename T>
void DynamicArray<T>::push_back(T value) {// push_back hace exactamente lo mismo que append
    Append(value); // hace lo mismo
}

template <typename T>
void DynamicArray<T>::pop_back() {//pop_back quita el ultimo elemento del arreglo si existe
    if (count > 0) {//solo si hay elementos
        count--;
    }
}

template <typename T>
void DynamicArray<T>::shrink_to_fit() {//shrink_to_fit función vacía como usted lo pidio profe :)
    // Solo dejarlo vacío
}

//sobrecarga del operador [] para poder acceder a los elementos como en un arreglo normal y estos los investigue de w3school con los ejemplos que te da, va?
template <typename T>
T& DynamicArray<T>::operator[](int index) {
    return data[index];
}