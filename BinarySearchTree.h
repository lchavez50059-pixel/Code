#pragma once
#include <iostream>
using namespace std;
#include<vector> // Recuerden, "vector" es el nombre del DynamicArray en c++ STL.

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
	{
		root = nullptr;
	}

	//añade un elemento de tipo T al arbol
	void Add(T value)
	{
		// Si no hay nodo raíz... 
		if (root == nullptr)
		{
			//entonces este valor se va a convertir en el nodo raiz
			root = new Node(value);
			return; //y nos salimos porque ya lo insertamos
		}

		Node* nodoActual = root;
		while (true)
		{
			if (value > nodoActual->value)
			{
				if (nodoActual->rightChild != nullptr)
				{
					nodoActual = nodoActual->rightChild;
					continue;
				}
				else
				{
					Node* nodoConNuevoValor = new Node(value);
					nodoActual->rightChild = nodoConNuevoValor;
					nodoConNuevoValor->parent = nodoActual;
					return;
				}
			}
			else if (value <= nodoActual->value)
			{
				if (nodoActual->leftChild != nullptr)
				{
					nodoActual = nodoActual->leftChild;
					continue;
				}
				else
				{
					Node* nodoConNuevoValor = new Node(value);
					nodoActual->leftChild = nodoConNuevoValor;
					nodoConNuevoValor->parent = nodoActual;
					return;
				}
			}
		}
	}

	//Buscar elemento
	bool Find(T value)
	{
		Node* resultado = FindNode(value);
		if (resultado == nullptr)
			return false;
		return true;
	}


	bool Search(T value)
	{
		Node* nodoActual = root;

		while (nodoActual != nullptr)
		{
			if (value == nodoActual->value)
				return true;

			if (value > nodoActual->value)
				nodoActual = nodoActual->rightChild;
			else
				nodoActual = nodoActual->leftChild;
		}

		return false;
	}

	T MaxValue()//este retorna el valos mas alto del arbl
	{
		if (root == nullptr)
		{
			cerr << "Error, se llamó la función MaxValue pero el árbol está vacío." << endl;
			return T{};
		}

		Node* nodoActual = root;
		while (nodoActual->rightChild != nullptr)
		{
			nodoActual = nodoActual->rightChild;
		}

		return nodoActual->value;
	}

	// Retorna el valor más bajo en el árbol.
	T MinValue()
	{
		if (root == nullptr)
		{
			cerr << "Error, se llamó la función MinValue pero el árbol está vacío." << endl;
			return T{};
		}

		Node* nodoActual = root;
		while (nodoActual->leftChild != nullptr)
		{
			nodoActual = nodoActual->leftChild;
		}

		return nodoActual->value;
	}

	T Siguiente(T value)
	{
		Node* nodoConValue = FindNode(value);
		if (nodoConValue == nullptr)
		{
			cerr << "ERROR, no existe un nodo con valor: " << value << " en este árbol, no hay sucesor para él" << endl;
			return T{};
		}

		Node* sucesor = Sucesor(nodoConValue);
		if (sucesor == nullptr)
		{
			cout << "No hay sucesor para el nodo con valor: " << value << endl;
			return T{};
		}
		return sucesor->value;
	}

	T Anterior(T value)
	{
		Node* nodoConValue = FindNode(value);
		if (nodoConValue == nullptr)
		{
			cerr << "ERROR, no existe un nodo con valor: " << value << " en este árbol, no hay predecesor para él" << endl;
			return T{};
		}

		Node* predecesor = Predecesor(nodoConValue);
		if (predecesor == nullptr)
		{
			cout << "No hay predecesor para el nodo con valor: " << value << endl;
			return T{};
		}
		return predecesor->value;
	}

	//Borra el primer nodo encontrado que tenga dicho valor
	bool BorrarPorValor(T valor)
	{
		if (root == nullptr)
		{
			throw invalid_argument("Este árbol está vacío");
			return false;
		}

		Node* nodoABorrar = FindNode(valor);
		if (nodoABorrar == nullptr)
		{
			throw invalid_argument("No hay nodo con dicho valor en este árbol");
			return false;
		}

		if (nodoABorrar->leftChild == nullptr && nodoABorrar->rightChild == nullptr)
		{
			DeleteCaso1(nodoABorrar);
			return true;
		}

		if (nodoABorrar->leftChild == nullptr && !(nodoABorrar->rightChild == nullptr) ||
			!(nodoABorrar->leftChild == nullptr) && nodoABorrar->rightChild == nullptr)
		{
			DeleteCaso2(nodoABorrar);
			return true;
		}

		Node* nodoSucesor = Sucesor(nodoABorrar);
		Node* hijoDerechoDelSucesor = nodoSucesor->rightChild;
		Node* padreDelSucesor = nodoSucesor->parent;

		nodoSucesor->leftChild = nodoABorrar->leftChild;
		if (nodoSucesor != nodoABorrar->rightChild)
			nodoSucesor->rightChild = nodoABorrar->rightChild;

		nodoSucesor->leftChild->parent = nodoSucesor;
		if (nodoSucesor->rightChild != nullptr)
		{
			nodoSucesor->rightChild->parent = nodoSucesor;
		}

		nodoSucesor->parent = nodoABorrar->parent;
		if (nodoABorrar->parent != nullptr)
		{
			if (nodoABorrar->parent->leftChild == nodoABorrar)
				nodoSucesor->parent->leftChild = nodoSucesor;
			else
				nodoSucesor->parent->rightChild = nodoSucesor;
		}
		else
		{
			root = nodoSucesor;
		}

		if (padreDelSucesor != nullptr)
			padreDelSucesor->leftChild = hijoDerechoDelSucesor;

		if (hijoDerechoDelSucesor != nullptr)
			hijoDerechoDelSucesor->parent = padreDelSucesor;

		delete nodoABorrar;
		return true;
	}

	//Recorridos existentes
	void InOrderRecursivo()
	{
		cout << "In order Recursivo: ";
		InOrderRecursivo(root);
		cout << endl;
	}

	void PreOrderRecursivo()
	{
		cout << "Pre order Recursivo: ";
		PreOrderRecursivo(root);
		cout << endl;
	}

	void PostOrderRecursivo()
	{
		cout << "Post order Recursivo: ";
		PostOrderRecursivo(root);
		cout << endl;
	}


	void BorrarTodoElArbol()//esta borra todo el arbol
	{
		BorrarSubArbol(root);
		root = nullptr;
	}

	void PostOrderIterativo()//este es el postorderinterativo 
	{
		if (root == nullptr)
		{
			cout << "Post order Iterativo: (árbol vacío)" << endl;
			return;
		}

		cout << "Post order Iterativo: ";

		std::stack<Node*> pila1;
		std::stack<Node*> pila2;

        pila1.push(root);

		while (!pila1.empty())
		{
			Node* nodoActual = pila1.top();
			pila1.pop();
			pila2.push(nodoActual);

			if (nodoActual->leftChild != nullptr)
				pila1.push(nodoActual->leftChild);

			if (nodoActual->rightChild != nullptr)
				pila1.push(nodoActual->rightChild);
		}

		while (!pila2.empty())
		{
			cout << pila2.top()->value << ", ";
			pila2.pop();
		}

		cout << endl;
	}

	pair<T, T> ObtenerMinimoYMaximo()
	{
		T max = MaxValue();
		T min = MinValue();
		return pair<T, T>(min, max);
	}

	T* ObtenerRaizMinimoYMaximo()
	{
		T* resultado = new T[3];
		resultado[0] = root->value;
		resultado[1] = MinValue();
		resultado[2] = MaxValue();
		return resultado;
	}

	vector<T> ObtenerRaizMinimoYMaximoConVector()
	{
		vector<T> resultado;
		resultado.push_back(root->value);
		resultado.push_back(MinValue());
		resultado.push_back(MaxValue());
		return resultado;
	}

private:

	class Node
	{
	public:
		Node(T _value)
		{
			value = _value;
			parent = nullptr;
			rightChild = nullptr;
			leftChild = nullptr;
		}

		T value;
		Node* parent;
		Node* rightChild;
		Node* leftChild;
	};

	void BorrarSubArbol(Node* nodoActual)//esta es la privada y pues ya borra el sub arbol
	{
		if (nodoActual == nullptr)
			return;

		BorrarSubArbol(nodoActual->leftChild);
		BorrarSubArbol(nodoActual->rightChild);
		delete nodoActual;
	}

	void DeleteCaso1(Node* nodoABorrar)
	{
		if (nodoABorrar->parent == nullptr)
		{
			delete nodoABorrar;
			root = nullptr;
			return;
		}

		if (nodoABorrar->parent->leftChild == nodoABorrar)
			nodoABorrar->parent->leftChild = nullptr;
		else
			nodoABorrar->parent->rightChild = nullptr;

		delete nodoABorrar;
	}

	void DeleteCaso2(Node* nodoABorrar)
	{
		Node* hijoDeNodoABorrar = nullptr;

		if (nodoABorrar->leftChild == nullptr)
			hijoDeNodoABorrar = nodoABorrar->rightChild;
		else
			hijoDeNodoABorrar = nodoABorrar->leftChild;

		hijoDeNodoABorrar->parent = nodoABorrar->parent;

		if (nodoABorrar == root)
		{
			root = hijoDeNodoABorrar;
		}
		else if (nodoABorrar->parent->leftChild == nodoABorrar)
			nodoABorrar->parent->leftChild = hijoDeNodoABorrar;
		else
			nodoABorrar->parent->rightChild = hijoDeNodoABorrar;

		delete nodoABorrar;
	}

	Node* FindNode(T value)
	{
		if (root == nullptr)
			return nullptr;

		Node* nodoActual = root;
		while (nodoActual != nullptr)
		{
			if (nodoActual->value == value)
				return nodoActual;

			if (value > nodoActual->value)
				nodoActual = nodoActual->rightChild;
			else
				nodoActual = nodoActual->leftChild;
		}

		return nullptr;
	}

	Node* Sucesor(Node* node)
	{
		if (node->rightChild != nullptr)
		{
			Node* nodoActual = node->rightChild;
			while (nodoActual->leftChild != nullptr)
				nodoActual = nodoActual->leftChild;
			return nodoActual;
		}

		Node* nodoActual = node;
		Node* padreNodoActual = nodoActual->parent;

		while (nodoActual->parent != nullptr)
		{
			if (nodoActual == padreNodoActual->leftChild)
				return padreNodoActual;

			nodoActual = padreNodoActual;
			padreNodoActual = padreNodoActual->parent;
		}

		return nullptr;
	}

	Node* Predecesor(Node* node)
	{
		if (node->leftChild != nullptr)
		{
			Node* nodoActual = node->leftChild;
			while (nodoActual->rightChild != nullptr)
				nodoActual = nodoActual->rightChild;
			return nodoActual;
		}

		Node* nodoActual = node;
		Node* padreNodoActual = nodoActual->parent;

		while (nodoActual->parent != nullptr)
		{
			if (nodoActual == padreNodoActual->rightChild)
				return padreNodoActual;

			nodoActual = padreNodoActual;
			padreNodoActual = padreNodoActual->parent;
		}

		return nullptr;
	}

	void InOrderRecursivo(Node* nodoActual)
	{
		if (nodoActual != nullptr)
		{
			InOrderRecursivo(nodoActual->leftChild);
			cout << nodoActual->value << ", ";
			InOrderRecursivo(nodoActual->rightChild);
		}
	}

	void PreOrderRecursivo(Node* nodoActual)
	{
		if (nodoActual != nullptr)
		{
			cout << nodoActual->value << ", ";
			PreOrderRecursivo(nodoActual->leftChild);
			PreOrderRecursivo(nodoActual->rightChild);
		}
	}

	void PostOrderRecursivo(Node* nodoActual)
	{
		if (nodoActual != nullptr)
		{
			PostOrderRecursivo(nodoActual->leftChild);
			PostOrderRecursivo(nodoActual->rightChild);
			cout << nodoActual->value << ", ";
		}
	}

	Node* root;
};

void DemostracionBinarySearchTree();
