#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Figura
{
public:

    //constructor basico, todas las figuras tienen un nombre
    Figura(string name)
    {
        nombre = name;
    }

    //virtual porque vamos a heredar y sobreescribir
    virtual ~Figura()
    {
        //solo lo dejo porque la clase base debe tener destructor virtual
    }

    //estas 2 deben ser virtuales puras porque cada figura calcula area y perimetro distinto
    virtual float CalcularArea() = 0;
    virtual float CalcularPerimetro() = 0;

    //función para obtener el nombre, esta no se sobreescribe
    const string& ObtenerNombreDeFigura()
    {
        return nombre;
    }

protected:
    //protected para que las hijas si puedan usarla directamente
    string nombre;
};

class Circulo : public Figura
{
public:
    Circulo(float r) : Figura("Circulo")
    {
        radio = r;
    }

    ~Circulo()
    {
        // nada especial
    }

    float CalcularArea() override
    {
        return 3.14159f * radio * radio;
    }

    float CalcularPerimetro() override
    {
        return 2.0f * 3.14159f * radio;
    }

private:
    float radio;
};

class Cuadrado : public Figura
{
public:
    Cuadrado(float lado) : Figura("Cuadrado")
    {
        this->lado = lado;
    }

    virtual ~Cuadrado()
    {
     
    }

    float CalcularArea() override
    {
        return lado * lado;
    }

    float CalcularPerimetro() override
    {
        return lado * 4;
    }

protected:
    float lado;
};

class FiguraNLados : public Figura
{
public:
    FiguraNLados(int n, float longitud) : Figura("Figura " + to_string(n) + " lados")
    {
        numLados = n;
        lado = longitud;
    }

    ~FiguraNLados()
    {
    }

    float CalcularArea() override
    {
        //formula del area de un poligono regular
        float per = numLados * lado;
        float apotema = lado / (2 * tan(3.14159f / numLados));
        return (per * apotema) / 2;
    }

    float CalcularPerimetro() override
    {
        return numLados * lado;
    }

private:
    int numLados;
    float lado;
};


class Cubo : public Cuadrado
{
public:
    Cubo(float lado) : Cuadrado(lado)
    {   
    nombre = "Cubo";//reasignamos nombre 
    }

    ~Cubo()
    {
    }

    //esto es para el volumen del cubo 
    float Volumen()
    {
        return lado * lado * lado;
    }

    //area de la superficie del cubo
    float Surface()
    {
        return 6 * (lado * lado);
    }

    //no sobreescribo area o perimetro porque ya existen del cuadrado
};

class Linea : public Figura
{
public:

    //recibe un arreglo de lados y su tamaño
    Linea(float* segmentos, int tam) : Figura("Linea")
    {
        tamaño = tam;

        //pedimos memoria dinamica
        arr = new float[tam];

        //copiamos los valores manualmente
        for (int i = 0; i < tam; i++)
        {
            arr[i] = segmentos[i];
        }
    }

    //destructor aqui si liberamos
    ~Linea()
    {
        delete[] arr;
    }

    //area de una linea es 0
    float CalcularArea() override
    {
        return 0.0f;
    }

    //perimetro es la suma de todos los lados
    float CalcularPerimetro() override
    {
        float suma = 0.0f;
        for (int i = 0; i < tamaño; i++)
            suma += arr[i];
        return suma;
    }

private:
    float* arr;//memoria dinamica
    int tamaño;
};
