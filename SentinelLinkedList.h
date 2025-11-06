#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SentinelLinkedList
{
public:
	SentinelLinkedList()
	{
        // El nodo NIL tiene un data X por defecto (no importa)
		NIL = new Node(T{});
		NIL->next = NIL;
		NIL->prev = NIL;
		count = 0;
	}

	~SentinelLinkedList()
	{
        // ¡OJO! El nodo centinela solamente se borra cuando se borra la lista.
		Node* nodoActual = NIL->next;
		while (nodoActual != NIL)
		{
			Node* nodoABorrar = nodoActual;
			nodoActual = nodoActual->next;
			delete nodoABorrar;
		}

		delete NIL;
		cout << "Sentinel linked list destruida con éxito" << endl;
	}
    // En esta versión no necesita ningún tipo de chequeo. Además es tiempo constante O(1)
	void Append(T value)
	{
		Node* newNode = new Node(value);
        // el que es el último nodo antes de insertar el nuevo ahora apunta al nuevo hacia adelante
		// OJO: el previo de NIL es el último nodo.
		NIL->prev->next = newNode;
        // el nuevo nodo apunta al anterior último hacia atrás
		newNode->prev = NIL->prev;
	    // NIL ahora hacia atrás apunta al nuevo nodo.
		NIL->prev = newNode;
        // El nuevo nodo apunta a NIL hacia adelante
		newNode->next = NIL;
		count++;
	}

	T PopBack()
    // Función PopBack quita y borra el último elemento de la Lista y regresa su valor.
	{
        // tenemos que checar que no esté vacía la lista.
		if (count == 0)
		{
			cout << "Error, trataron de hacer PopBack de una lista vacía." << endl;
			return T{};
		}
        // El nodo final es el prev de NIL. 
		Node* nodoABorrar = NIL->prev;
		T valorDelNodoABorrar = nodoABorrar->data;
        // hace las reconexiones entre prev's y next's y reduce el count en 1.
		Delete(nodoABorrar);
        // Regresamos el valor que almacena dicho nodo.
		return valorDelNodoABorrar;
	}
    // Función Front devuelve el valor del primer elemento de la lista
	T Front()
	{
        // tenemos que checar que no esté vacía la lista.
		if (count == 0)
		{
			cout << "Error, trataron de sacar el front de una lista vacía." << endl;
			return T{};
		}
        // El nodo inicial es el next de NIL. Regresamos el valor que almacena dicho nodo.
		return NIL->next->data;
	}
    // Back devuelve el valor del último elemento de la lista.
	T Back()
	{
        // tenemos que checar que no esté vacía la lista.
		if (count == 0)
		{
			cout << "Error, trataron de sacar el Back de una lista vacía." << endl;
			return T{};
		}
        // El nodo final es el prev de NIL. Regresamos el valor que almacena dicho nodo.
		return NIL->prev->data;
	}
    // Regresa true si hay al menos un nodo con dicho value, y falso si no.
	bool Contains(T value)
	{
		Node* nodoEncontrado = Search(value);
        // si no encontramos el nodo, entonces regresamos false
		if (nodoEncontrado == nullptr)
			return false;
        // si no encontramos el nodo, entonces regresamos false
		return true;
        // return nodoEncontrado != nullptr;
	}
    // Nos regresa los datos guardados el nodo en la i-ésima posición desde el inicio.
	T ObtenerValorPorIndice(size_t indice)
	{
		if (indice >= count)
		{
			cout << "Error, trataron de acceder a un índice inválido:" << indice << endl;
			return T{};
		}

		Node* nodoActual = NIL->next;
		for (int i = 0; i < indice; i++)
			nodoActual = nodoActual->next;

		return nodoActual->data;
	}
    // versión inventada que trata de llegar más rápido al índice dependiendo de si está en la mitad de atrás
	// o en la mitad de adelante.
	T ObtenerValorPorIndiceOptimizada(int indice)
	{
		if (indice >= count)
		{
			cout << "Error, trataron de acceder a un índice inválido:" << indice << endl;
			return T{};
		}
        // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] // 10 nodos
		// dame el 9no tú tienes que hace 9 iteraciones
		// pero si empezaras desde el final, solo tendrías que hacer una iteración
		// si ese índice es mayor que la mitad del count, entonces empieza desde el final.
		// y ahora tenemos que hacer count-índice iteraciones.
		Node* nodoActual = nullptr;
		if (indice < count / 2)
		{
			nodoActual = NIL->next;
			for (int i = 0; i < indice; i++)
				nodoActual = nodoActual->next;
		}
		else
		{
			int iteraciones = count - indice;
			nodoActual = NIL->prev;
			for (int i = 0; i < iteraciones; i++)
				nodoActual = nodoActual->prev;
		}

		return nodoActual->data;
	}

	void DeleteByValue(T value)
	{
		Node* nodoABorrar = Search(value);
        // si es nullptr, no se encontró un nodo con ese value, entonces no hay nada que borrar.
		if (nodoABorrar == nullptr)
		{
			cout << "no se encontró el valor a borrar: " << value << " en esta lista con centinela." << endl;
			return;
		}

		Delete(nodoABorrar);
	}

	/* FUNCIONES PARA EL EXAMEN QUE SE ENTREGA A MÁS TARDAR EL JUEVES 6 DE NOVIEMBRE A LAS 11:59 PM*/
	void PushFront(T value){

	Node* nuevo = new Node(value);//creo el nodo nuevo

	nuevo->next = NIL->next;//lo conecto con el que era el primero
	nuevo->prev = NIL;//lo conecto atras con nil

	NIL->next->prev = nuevo;//ajusto el previo del que era el primero
	NIL->next = nuevo;//ahora nil apunta al nuevo nodo
	count++;//aumento el contador
}


T PopFront()
{
	if (count == 0)
	{
		cout << "Error, trataron de hacer PopBack de una lista vacía." << endl;
		return T{};
	}

	Node* borrar = NIL->next;//tomo el primer nodo real
	T dato = borrar->data;//se guarda su valor antes de borrarlo

	Delete(borrar);//uso la función existente

	return dato;//regreso el dato
}
private:
	class Node
	{
	public:
		Node(T _data)
		{
			data = _data;
			next = nullptr;
			prev = nullptr;
		}

		T data;
		Node* next;
		Node* prev;
	};

	Node* Search(T value)
	{
		Node* nodoActual = NIL->next;

		while (nodoActual != NIL)
		{
			if (nodoActual->data == value)
			{
				return nodoActual;
			}
			nodoActual = nodoActual->next;
		}

		cout << "no se encontró el valor: " << value << " en esta lista con centinela." << endl;
		return nullptr;
	}

	void Delete(Node* nodoABorrar)
	{
		nodoABorrar->prev->next = nodoABorrar->next;
		nodoABorrar->next->prev = nodoABorrar->prev;
		count--;
	}

	Node* NIL;
	int count;
};

void DemostracionSentinelLinkedList();
