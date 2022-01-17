#include "generador.h"
#include "vectores.h"


using namespace std;

int main() {
    // funcion para generar automaticamente los archivos numericos
    //generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    //holaModuloVectores(); // función definida en vectores.cpp


    //pruebas para la parte de vectores
    vector<int> v;
    int a=2;
    v.push_back(5);
    v.push_back(4);
    v.push_back(9);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);

    /*vector<int> v2 = rotar(v,2);
    vector<int> v3 = factoresPrimos(36);

    mostrarVector(v);*/

   //pruebas para la parte de entrada y salida
   //vector<int> caca= fLeerVector("leerVector.in");
   //mostrarVector(v);

   //guardarVector(caca, "vectorCaca.in");
   //fElementoMedio(fLeerVector("elementoMedio.in"));
   //mostrarVector(numReptidos(v));

   //cantApariciones("cantApariciones.in"); falta algo
   //cout<<sonIguales("hola","hoal");
   // fCantidadAparicionesDePalabra("horrendoTexto.txt", "caca");

   //promedio("promedio1.in", "promedio2.in", "PUTOTEXTO.in");

   // fCantApariciones("cantidadApariciones.in", "OTRAMIERDA.in");

   // ordenarSecuencias("ordenarSecuencia1.in", "ordenarSecuencia2.in", "ESTOYLOQUISIMO.in");

   //vector<int> v3 = interseccion();
   //mostrarVector(v3);
   cout<<estaOrdenado(v);

   return 0;
}
