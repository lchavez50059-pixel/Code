#include <iostream>
#include "Figuras.h"
using namespace std;

int main()
{
    cout << "Aqui es la prueba de herencia para figuras ";

    //circulo 
    Figura* f1 = new Circulo(5.0f);
    cout << f1->ObtenerNombreDeFigura() << endl;
    cout << "area: " << f1->CalcularArea() << endl;
    cout << "perimetro: " << f1->CalcularPerimetro() << endl << endl;


    //cuadrado 
    Figura* f2 = new Cuadrado(4.0f);
    cout << f2->ObtenerNombreDeFigura() << endl;
    cout << "area: " << f2->CalcularArea() << endl;
    cout << "perimetro: " << f2->CalcularPerimetro() << endl << endl;


    //figuna de n lados 
    Figura* f3 = new FiguraNLados(6, 3.0f);//hexagono regular
    cout << f3->ObtenerNombreDeFigura() << endl;
    cout << "area: " << f3->CalcularArea() << endl;
    cout << "perimetro: " << f3->CalcularPerimetro() << endl << endl;


    //cubo
    Cubo* cub = new Cubo(2.5f);
    cout << cub->ObtenerNombreDeFigura() << endl;
    cout << "area: " << cub->CalcularArea() << endl;
    cout << "perimetro: " << cub->CalcularPerimetro() << endl;
    cout << "volumen del cubo: " << cub->Volumen() << endl;
    cout << "superficie total: " << cub->Surface() << endl << endl;


    //linea
    float segmentos[] = { 2.5f, 1.0f, 3.3f, 4.2f };
    Figura* linea = new Linea(segmentos, 4);

    cout << linea->ObtenerNombreDeFigura() << endl;
    cout << "area: " << linea->CalcularArea() << endl;
    cout << "perimetro: " << linea->CalcularPerimetro() << endl << endl;


    //aquie es donde se va a liberAR MEMORIA 
    delete f1;
    delete f2;
    delete f3;
    delete cub;
    delete linea;

    cout << "Se terminaron las pruebas, no vuelva pronto por favor " << endl;

    return 0;
}
