#include <iostream>
#include "HashTableChaining.h"
#include "HashSet.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    cout << "PRUEBAS" << endl;
    
    HashSet<int> conjunto(10);

    cout << "Agregando 5..." << endl;
    cout << (conjunto.Add(5) ? "Insertado" : "Ya existe") << endl;

    cout << "Agregando 10..." << endl;
    cout << (conjunto.Add(10) ? "Insertado" : "Ya existe") << endl;

    cout << "Agregando 5 otra vez..." << endl;
    cout << (conjunto.Add(5) ? "Insertado" : "Ya existe") << endl;

    cout << "Contenido del HashSet:" << endl;
    conjunto.Print();

    cout << "Buscando 10: " << (conjunto.Contains(10) ? "Encontrado" : "No esta") << endl;
    cout << "Eliminando 10..." << endl;
    conjunto.Remove(10);
    cout << "Buscando 10: " << (conjunto.Contains(10) ? "Encontrado" : "No esta") << endl;

    cout << "PRUEBAS AGAIN BST" << endl;

    BinarySearchTree<int> arbol;

    arbol.Add(50);
    arbol.Add(30);
    arbol.Add(70);
    arbol.Add(20);
    arbol.Add(40);
    arbol.Add(60);
    arbol.Add(80);

    cout << "PostOrder ITERATIVO" << endl;
    arbol.PostOrderIterativo();

    cout << "Search ITERATIVO" << endl;
    cout << (arbol.SearchIterativo(40) ? "40 encontrado" : "40 no esta") << endl;
    cout << (arbol.SearchIterativo(100) ? "100 encontrado" : "100 no esta") << endl;

    cout << "Borrar SUBARBO" << endl;
    arbol.BorrarSubarbol(30);

    cout << "PostOrder después de borrar" << endl;
    arbol.PostOrderIterativo();

    return 0;
}
