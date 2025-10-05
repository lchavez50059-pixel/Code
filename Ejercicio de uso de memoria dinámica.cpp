#include <iostream>
using namespace std;

int main() {

    //aqui se declarar un puntero a flotante y asignarle el valor nullptr
    float* ptr = nullptr; // el puntero no apunta a nada ahorita 

    //pedir la memoria dinámica para el puntero y que adentro tenga el valor 7.77
    ptr = new float;//guardamos memoria dinámica para un float
    *ptr = 7.77;//guardamos el valor 7.77 en la dirección de memoria
    cout << "valor que se almaceno en la memoria dinámica: " << *ptr << endl;

    //aqui declaramos una variable de tipo flotante con un valor de 6.66
    float num = 6.66;

    //hacemos que ahora el puntero 3 apunte a la dirección de memoria de la variable del punto 3.2
    ptr = &num;  //aquí estamos perdiendo la referencia al espacio de memoria anterior 

    cout << "cuidado, acabas de causar un memory leak!" << endl;

    cout << "un memory leak ocurre cuando perdemos la referencia a un espacioo de memoria dinamica si haberlo liberado, lol " << endl;
    cout << "lo podemos evitar si utilizamos un delete antes de cambiar el puntero o saliendo de programa. Facil, no?" << endl;

    // aqui volvemos a pedir memoria dinámica pero ahora para el puntero y le damos el valor 1984
    ptr = new float;// se pide nueva memoria
    *ptr = 1984;// se guarda el valor 1984
    cout << "nuevo valor que se le asigno a la memoria dinámica: " << *ptr << endl;

    //hacemos un nuevo puntero a float y hacer que apunte a la misma dirección que el puntero anterior
    float* otroPtr = ptr; //ahora los dos apuntan al mismo bloque de memoria 

    //liberamos la memoria dinámica borrando el puntero de 3.6 y luego asignamos nullptr
    delete ptr;//liberamos la memoria dinámica
    ptr = nullptr;//el puntero ahora apunta a nada, lol

    //verificamos si nuestro puntero es igual a nullptr
    if (ptr == nullptr)
        cout << "el puntero ptr es igual a nullptr" << endl;

    //verificamos si el puntero es igual a NULL
    if (ptr == NULL)
        cout << "el puntero ptr es igual a NULL." << endl;

    //checamos si el puntero del punto 3.7 es nullptr o null
    if (otroPtr == nullptr || otroPtr == NULL)
        cout << "el puntero otroPtr es nullptr o NULL" << endl;
    else
        cout << "el puntero otroPtr NOOOOOOOOOOO es nullptr ni NULL. "
             << "cuidado: esta apuntando a memoria que ya fue liberada" << endl;
             
        cout << "si ando sacando mis 25 puntotes o no? o nada?"<<endl;
    return 0;
}
