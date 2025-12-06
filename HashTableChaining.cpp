#include <iostream>
#include "HashTableChaining.h"

using namespace std;

void DemostracionHashTableChaining()
{
    cout << " DEMOSTRACION" << endl;

    HashTableChaining<int> tabla(10);

    cout << "Insertando 15..." << endl;
    tabla.Add(15);

    cout << "Insertando 25 (colision)..." << endl;
    tabla.Add(25);

    cout << "Insertando 35 (colision)..." << endl;
    tabla.Add(35);

    cout << "Estado de la tabla:" << endl;
    tabla.Imprimir();

    cout << "Buscando 25: ";
    cout << (tabla.Encontrar(25) ? "Encontrado" : "No esta, lol quw mal ") << endl;

    cout << "Borrando 25..." << endl;
    tabla.BorrarValor(25);

    cout << "Buscando 25: ";
    cout << (tabla.Encontrar(25) ? "Encontrado" : "No estaaa") << endl;

    cout << "Tabla final:" << endl;
    tabla.Imprimir();
}
