#include "LinkedList.h"

//este es el constructor e inicia la lista vacía
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

//este es el destructor y libera toda la memoria de los nodos
template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current; //guardamos nodo actual
        current = current->next; //pasamos al siguiente
        delete temp;//borramos el nodo
    }
    // Con esto nos aseguramos que no haya fugas de memoria
}

// push_front: agrega un nodo al inicio
template <typename T>
void LinkedList<T>::push_front(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head; // apuntamos al primer nodo actual
    head = newNode;       // ahora este es el primer nodo
}

// pop_front: quita el primer nodo
template <typename T>
void LinkedList<T>::pop_front() {
    if (head != nullptr) {
        Node<T>* temp = head;
        head = head->next; // avanzamos al siguiente
        delete temp;       // borramos el primero
    }
}

// Print: muestra la lista desde el inicio al final
template <typename T>
void LinkedList<T>::Print() {
    Node<T>* current = head;
    cout << "链表内容: "; //diceee "contenido de la lista" en chino segun el traductor 
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}