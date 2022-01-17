#include <iostream>
#include "ejercicios.h"
#include <math.h>

using namespace std;

//la idea es dado un archivo de codigo inicial ir viendo que esta mal con el debugger y arreglarlo

/************* Ejercicio 1 *************/ 
// Decidir si un vector esta ordenado tanto ascendente como descendentemente
bool estaOrdenadoAsc(vector<int> v){
  int i=0;
  int longitud = v.size();
  bool esMenor = true; //si no incializo a esMenor(lo mismo con esMayor) se autodefine como false y no entra nunca al ciclo
   while(i<=longitud-2 && esMenor){
    esMenor = v[i]<=v[i+1];
    i++;
  }
  return i==longitud-1;
}

bool estaOrdenadoDesc(vector<int> v){
  int longitud = v.size();
  int i=0;
  bool esMayor=true;
  while(i<=longitud-2 && esMayor){
    esMayor = v[i]>=v[i+1];
    i++;
  }

  return i==longitud-1;
}

bool estaOrdenado(vector<int> v) {
    int longitud = v.size();
    if (longitud == 0 || longitud == 1) {
        return true;
    } else {
        return estaOrdenadoDesc(v) || estaOrdenadoAsc(v);
    }
}


/************* Ejercicio 2 *************/ 

// Decidir si un numero es primo.
bool esPrimo(int numero){
  if(numero>2) {
    int i=2;
    bool divide = false;
    while(i<numero && !divide) { //al while le faltaban las sangrias y no terminaba nunca ademas el i tiene q ser < al numero, no <=
        divide = numero % i == 0; //creo que aca habia otro error ya que divide era = numero % i != 0 y esto seria que no divide
        i++;
    }
    return i==numero;
  }
  if(numero==2) {
      return true;
  }else {
      return false;
  }
}

/************* Ejercicio 3 *************/ 

// Decidir si un elemento dado pertenece al vector.
bool pertenece(int elemento, vector<int> v){
  int longitud = v.size();
  if(longitud==0) {
      return false;
  }else {
      int i = 0;
      bool sigo = true;
      while ((i < longitud) && sigo) {
          sigo = v[i] != elemento;
          i++;
      }
   return (i<=longitud & sigo == false) ; //el error es que podia pasar que el elemento este en el ultimo lugar y este lo tomaba como falso
  }
}

/************* Ejercicio 4 *************/ 

// Encontrar el desvio estandar de un vector de floats.
float promedio(vector<float> v){
  int longitud = v.size();
  int suma=0;
  for(int i=0; i<=longitud-1; i++) {
      suma = suma + v[i]; // estaba escrito como suma += v[i] 
  }
  return suma/longitud;
}

float sumaDeCuadrados(vector<float> v){
  float sumadecuadrados=0;
  for(int i=0; i<=v.size()-1; i++) {
      sumadecuadrados += pow((v[i] - promedio(v)), 2); // faltaba sangria
  }
  return sumadecuadrados;
}

float desvioEstandar(vector<float> v){
  float res = sqrt(sumaDeCuadrados(v)/v.size()); //esto no era necesario lo hice para ver los resultados con el debugger
  return res;
}


/************* Ejercicio 5 *************/ //hecho

// Calcular el k-esimo numero de fibonacci
long fibonacci(int k){
  if(k==0) { // habia un error de sangrias creo ademas que aparecia k=0 en vez de  k == 0
      return 0;
  } else {
      if (k == 1) {
          return 1;
      } else {
          long i = 0;
          long j = 1;
          long m;
          int nesimo;
          for (nesimo == 1; nesimo <= k; nesimo++) {
              m = j;
              j = i + j;
              i = m;
          }
          return j;
      }
  }
}

/************* Ejercicio 6 *************/

// Encontrar el maximo comun divisor de dos numeros
int maximo(int x, int y){
  if(x<0) {
      x = -x;
  }
  if(y<0) {
      y = -y;
  }
  if(x>y) {
      return x;
  }else {
      return y;
  }
}

int minimo(int x, int y){
  if(x<0) {
      x = -x;
  }
  if(y<0) {
      y = -y;
  }
  if(x<y) {
      return x;
  }else {
      return y;
  }
}

int maximoComunDivisor(int x, int y) {
    int a = maximo(x, y);
    int b = minimo(x, y);
    int resto;
    while (b > 1) { //aca ya se que hay un loop infinito era porque las asignaciones estaban mal hechas
        resto = a % b;
        a = b;   
        b = resto;
    }
    if (b == 0) { //tenia que poner esto en vez de a==0
        return a;
    } else {
        return 1;
    }
}

/************* Ejercicio 7 *************/ //hecho

// Para un vector de enteros, calcular la sumatoria del doble de los elementos positivos y pares.
int sumaDoble(vector<int> v){
  int suma=0;
  for(int i=0; i<v.size(); i++){
    if(v[i]%2==0 && v[i]>=0) { //habia solo un error que lo que hacia es que si el if no se cumplia creo que qeudaba un loop infinito
        suma = suma + v[i] * 2;
    }else{
        suma = suma; //ademas aca habia un i++ lo cual es innecesario porque es un for
    }
  }
  return suma;
}

/************* Ejercicio 8 *************/ //hecho

// Contar la cantidad de palabras que hay en un archivo de texto.
int cantPalabras(string filename) {
  ifstream miArchivo;
  string palabra;
  int cont = 0;

  miArchivo.open(filename.c_str(), ifstream::in);
  if(miArchivo.is_open()) {
    while(!miArchivo.eof()) { //aca faltaba el ! adelante
      miArchivo >> palabra;
      cont++;
    }
  }
  miArchivo.close();
  return cont;
}

/************* Ejercicio 9 *************/ 

/* El archivo SensadoRemoto.txt contiene una lista de valores reales provenientes de una estacion
* de medicion de una variable fisica dada, cuyos valores son positivos menores a 1.
* Escribir un programa que calcule el promedio de los valores tomados durante un periodo de tiempo.
* Verificar el resultado obtenido.
*/
float valorMedio() {
  ifstream miArchivo;
  float val;
  float acum = 0;
  int cont = 0;

  miArchivo.open("datos/SensadoRemoto.txt",ifstream::in);
  if(miArchivo.is_open()) {
    while(!miArchivo.eof()) {
      miArchivo >> val;
      acum = acum + val;
      cont++;
    }
  }
  miArchivo.close();

  float res= acum/cont;
  return res;
}

/************* Ejercicio 10 *************/ 

// Devolver en res la fraccion (entre 0 y 1) de numeros mayores a 0.
void fraccion(vector<int> v, float res){
  float count = 0; //el error es que count estaba definido como un int
  for(int i = 0; i < v.size(); i++){
    if(v[i] > 0){
      count = count + 1 ;
    }else{
        count= count;
    }
  }
  res = count / v.size();
}
