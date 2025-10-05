#include <iostream> 
using namespace std;

//clase rect que representa un rectángulo en un espacio 2D
class Rect {
private:
    float x;//coordenada X 
    float y;//coordenada Y 
    float alto;//altura del rectangulo
    float ancho;//ancho del rectangulo

public:

    //se inicializan todas las variables en 0
    Rect() {
        x = 0;
        y = 0;
        alto = 0;
        ancho = 0;
        cout << "constructor por defecto ejecutado " << endl;
    }

    // recibe x, y, alto y ancho y los asigna a las variables
    Rect(float _x, float _y, float _alto, float _ancho) {
        x = _x;
        y = _y;
        alto = _alto;
        ancho = _ancho;
        cout << "constructor con 4 parametros ejecutado" << endl;
    }

    // x y y se ponen en 0 por defecto
    Rect(float _alto, float _ancho) {
        x = 0;
        y = 0;
        alto = _alto;
        ancho = _ancho;
        cout << "constructor con alto y ancho ejecutado" << endl;
    }

    // aqui se esa para mostrar los valores del rectangulo
    void Mostrar() {
        cout << "Rect -> X: " << x << ", Y: " << y
             << ", alto: " << alto << ", ancho: " << ancho << endl;
    }

    //dse calcula las coordenadas finales y valida los datos
    bool CalcularCoordenadasFinales(Rect &r, float &xFin, float &yFin) {
        
        //si alguno de los valores del rectangulo es negativo, devuelve false
        if (r.x < 0 || r.y < 0 || r.alto < 0 || r.ancho < 0) {
            cout << "ERRORRRR: al menos un campo del rect es menor que 0" << endl;
            return false;
        }

        //se calcula la posición final en el plano
        xFin = r.x + r.ancho;
        yFin = r.y + r.alto;

        //se imprime los datos del rectángulo que se recibio
        cout << "Rect recibido -> X inicial: " << r.x
             << ", Y inicial: " << r.y
             << ", X final: " << xFin
             << ", Y final: " << yFin << endl;

        return true; //si todo salió bien (obvio si), devuelve true
    }

    bool CheckOverlap(Rect r1, Rect r2) {
        //calculamos las coordenadas finales de los dos rectangulos
        float r1_xFin = r1.x + r1.ancho;
        float r1_yFin = r1.y + r1.alto;
        float r2_xFin = r2.x + r2.ancho;
        float r2_yFin = r2.y + r2.alto;

        //comprobamos si NOOOOOOOO se traslapan esto ocurre si uno está totalmente a la izquierda, derecha, arriba o abajo del otro
        if (r1_xFin < r2.x || r2_xFin < r1.x ||
            r1_yFin < r2.y || r2_yFin < r1.y)
            return false; //no se traslapan

        //si no se cumple ninguna de las condiciones anteriores, significa que sí se traslapan
        return true;
    }
};

//función principal
int main() {
    //ejemplo 1 usamos el constructor por defecto
    Rect r0;
    r0.Mostrar();

    //ejemplo 2: usamos el constructor con 4 parametros
    Rect r1(0, 0, 5, 5);
    r1.Mostrar();

    //ejemplo 3: usamos el constructor con solo alto y ancho
    Rect r2(2, 2);
    r2.Mostrar();

    //probamos la funcion CalcularCoordenadasFinales
    Rect aux(1, 1, 3, 4);//creamos un rectangulo auxiliar
    float xFin, yFin;//variables para guardar coordenadas finales

    //mandamos llamar al metodo pasando el rectangulo y las variables por referencia
    if (r1.CalcularCoordenadasFinales(aux, xFin, yFin))
        cout << "coordenadas finales calculadas a la perfeccion :)\n";
    cout << endl;

    //ahora probamos nuestros ejemplos de traslape que se piden
    Rect a(0, 0, 5, 5);
    Rect b(6, 6, 5, 5);
    Rect c(2, 2, 2, 2);
    Rect d(1, 1, 7.5, 2);

    Rect temp; //este es un objeto temporal que sirve para llamar a CheckOverlap()

    //mostramos los resultados de los ejemplos dados
    cout << "¿a y b se traslapan? " << (temp.CheckOverlap(a, b) ? "si" : "no") << endl;
    cout << "¿a y c se traslapan? " << (temp.CheckOverlap(a, c) ? "si" : "no") << endl;
    cout << "¿a y d se traslapan? " << (temp.CheckOverlap(a, d) ? "si" : "no") << endl;

    return 0; 
}
