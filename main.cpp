#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "PrintArray.h"
using namespace std;

int main() {
    cout << "*****TEST DynamicArray*****" << endl;

    DynamicArray<int> myArray;

    //agregamos elementos
    myArray.Append(1984);
    myArray.push_back(2025);

    cout << "elemento 0: " << myArray[0] << endl;
    cout << "elemento 1: " << myArray[1] << endl;

    myArray.pop_back();//eliminamos ultimo
    cout << "despues de pop_back, size = " << myArray.Size() << endl;

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    cout << "copias ya hechas: " << myArray.getCopyCount() << endl;
#endif

    cout << "\n*****TEST LinkedList*****" << endl;

    LinkedList<int> lista;

    //agregamos elementos al inicio
    lista.push_front(10);
    lista.push_front(20);
    lista.push_front(30);

    lista.Print();//imprime lista
    lista.pop_front();//quitamos primer nodo
    lista.Print();

    cout << "\n*****TEST PrintArray*****" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    PrintArray(arr, 5);//este imprime arreglo normal

    return 0;//ojala y saque un 1000000/10 que ahora si estuvo para inmortales 
}