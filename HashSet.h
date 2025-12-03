#pragma once

#include "HashTableChaining.h"

template <typename T>
class HashSet
{
public:

    //Constructor: recibe el número de bucket que tendrá la tabla interna
    HashSet(size_t numeroDeListas)
    {
        tablaInterna = new HashTableChaining<T>(numeroDeListas);
    }

    //Destructor
    ~HashSet()
    {
        delete tablaInterna;
    }

 
    bool Add(T value)//se inserta un elemento solo si no existe 
    {
        if (tablaInterna->Encontrar(value))
        {
            return false;//ya existe no se inserta
        }

        tablaInterna->Add(value);
        return true;
    }
    bool Remove(T value)
    {
        return tablaInterna->BorrarValor(value);
    }

    bool Contains(T value)
    {
        return tablaInterna->Encontrar(value);
    }

    void Print()
    {
        tablaInterna->Imprimir();
    }

private:
    HashTableChaining<T>* tablaInterna;
};
