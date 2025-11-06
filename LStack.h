#pragma once

#include <iostream>
#include <forward_list>//la lista ligada , para esta aparte de link que nos proporciono me guie un poco de la pagina de w3schoolpara que me quedara mas claro 
using namespace std;

template <typename T>
class LStack
{
public:

    LStack()
    {
        //forward_list no necesita de un constructor especial 
        count = 0;
    }

    //igual que el stack del profe, solo que ahora los datos
    //estan en una forward_list
    void Push(T value)
    {
        //push_front es O(1) porque forward_list solo tiene head
        lista.push_front(value);
        count++;//igual que en la pila normal
    }

    //saca y regresa el elemento del tope
    T Pop()
    {
        if (count > 0)
        {
            //el primero de la lista es el tope
            T valor = lista.front();
            lista.pop_front();//lo borra
            count--;
            return valor;
        }

        
        cout << "ERROR la pila estaba vacía pero se intentó sacar un elemento." << endl;
        return T{};
    }

    //vemos el elemento superior sin quitarlo
    T Peek()
    {
        if (count > 0)
        {
            return lista.front();
        }

        cout << "ERROR la pila estaba vacía pero se intentó hacer Peek." << endl;
        return T{};
    }

    //lo mismo que getcount en el queue
    int Count()
    {
        return count;
    }

private:
    forward_list<T> lista;//donde se guardan los datos
    int count;//igual que en stack de usted profe 
};
