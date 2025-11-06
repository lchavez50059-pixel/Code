#pragma once

#include "SentinelLinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
class LQueue
{
private:
    //esta queue solo usa una lista con nodo centinela
    //es exactamente la misma estructura que vimos en clase pero sin el array
    SentinelLinkedList<T> data;

public:

    LQueue()
    {
        //no hay nada que inicializar realmente
        //la lista ya trae el NIL configurado
    }

    //igual que en la queue normal
    int GetCount() 
    { 
        return data.GetCount(); 
    }

    //enqueue mete al FINAL, como la queue normal
    void Enqueue(T value)
    {
        //aqui usamos pushback pero en mi lista se llama append
        //no todos los profes usan el mismo nombre asi que lo dejo como append
        //append mete al final y es O(1)
        data.Append(value);
    }

    //dequeue quita del frente 
    T Dequeue()
    {
        //si no hay nada pues es error igual que en queue normal
        if (data.GetCount() == 0)
        {
            cout << "ERROR: LQueue vacia (Dequeue)" << endl;
            return T{};  // valor default
        }

        //popfront lo hicimos en la parte del examen
        return data.PopFront();
    }

    //vemos el primer elemento sin sacarlo
    T Front()
    {
        //esta función ya existe en la lista, el profe la dejo
        return data.Front();
    }
};
