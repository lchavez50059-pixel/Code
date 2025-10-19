#pragma once
#include <iostream>
using namespace std;

//este es el nodo de la lista enlazada 
template <typename T>
struct Node {
    T data;//es el dato que guarda el nodo
    Node* next;//es el apuntador al siguiente nodo
    Node(T value) : data(value), next(nullptr) {}//contructor que contruye jeje
};

//es la clase lista enlazada simple
template <typename T>
class LinkedList {
private:
    Node<T>* head;//es el primer nodo de la lista

public:
    LinkedList();//constructor
    ~LinkedList();//destructor que destruye

    void push_front(T value);//este agrega al inicio
    void pop_front();//este quita del inicio
    void Print();//este imprime toda la lista
};