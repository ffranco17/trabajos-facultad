#ifndef EJERCICIOS_H
#define EJERCICIOS_H

#include <iostream>
#include <vector>
#include <string>
#include "generador.h"
#include <fstream>

using namespace std;

void holaModuloVectores();

//Ejercicio
bool divide(vector<int> v, int a);
// Dados un vector v y un int a, decide si a divide a todos los numeros de v.

//Ejercicio
int mayor(vector<int> v);
// Dado un vector v, devuelve el valor maximo encontrado.

//Ejercicio
vector<int> reverso(vector<int> v);
// Dado un vector v, devuelve el reverso.

//Ejercicio
vector<int> rotar(vector<int> v, int k);
// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].

//Ejercicio
bool estaOrdenado(vector<int> v);
//Dado un vector v de enteros no repetidos, devuelve verdadero si el mismo esta ordenado (ya sea creciente o decrecientemente).

//Ejercicio
bool esPrimo(int n);
vector<int> factoresPrimos(int n);
// Dado un entero devuelve un vector con los factores primos del mismo

//Ejercicio
void mostrarVector(vector<int> v);
// Dado un vector de enteros muestra por la salida estándar, el vector
// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]

// Y aca van todos los otros headers de los ejercicios del laboratorio
//ej 8
vector<int> fLeerVector(string nombreArchivo);

//ej 9
void guardarVector(vector<int> v, string nombreArchivo);

//ej 10
int sumaParcial(vector<int> v, int a, int b);
int fElementoMedio(vector<int>v);

//ej 11
bool aparece(vector<int> v, int a);
vector<int> numReptidos(vector<int>);
int numApariciones(vector<int> v, int a);
void fCantApariciones(string nombreArchivo, string nombreArchivoOut);

//ej 12
bool sonIguales(string a, string b);
int fCantidadAparicionesDePalabra(string nombreArchivo, string palabra);

//ej 13
void promedio(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut);

//ej 14
void ordenarSecuencias(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut);

//ej 15
vector<int> interseccion();

#endif