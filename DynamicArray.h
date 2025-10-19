#pragma once //sirve para lo mismo del pasado lol 


#include <iostream> 
using namespace std;


#define COUNT_DYNAMIC_ARRAY_COPIES 1  //este pues es solo para cuando sea diferente de 0


template <typename T>
class DynamicArray {
private:
    T* data;// puntero del arreglo donde se guardan los elementos
    int count;//cuantos elementos tenemos actualmente
    int capacity;//cuanto espacio total hay disponible

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int copyCounter;//cuenta las copias solamente cuande-o esta activado 
#endif

public:
    DynamicArray();//constructor que inicializa nuestra clase 
    ~DynamicArray();//destructor que va liberando memi¿oria 

    void Append(T value);//va agregando un elemento al final
    void push_back(T value);// hace lo mismo que append y que hace el append? va agregando un elemento al final :D
    void pop_back();//es el encargado de quitar el último elemento
    void shrink_to_fit();//va reduciendo la capacidad al tamaño exacto de elementos

    
    T& operator[](int index);

    
    int Size() { return count; }//devuelve la cantidad de elementos que hay 

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int getCopyCount() { return copyCounter; } //devuelve cuantas copias se hicieron
#endif
};