#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"


// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    if(t.size() == 0 ){
        return false;
    }
    bool resp = false; // este valor puede ser cambiado de acuerdo a la propia implementacion
    if (esRectangulo(t)){
        if (t.size()>2 && t[0].size()>2){
            return true;
        }
        return false;
    }
    return resp;
}

// EJERCICIO 2
vector<posicion> posicionesVivas(toroide const &t) {
    vector<posicion> vivos;
    int filas = t.size();
    int columnas = t[0].size();
    for (int i = 0 ; i<filas ; i++){
        for (int j = 0 ; j<columnas ; j++){
            if (t[i][j]){ //Tener en cuenta que t[i][j] es un bool
                pair <int, int> posicionPar (i,j);
                vivos.push_back(posicionPar);
            }
        }
    }
    return vivos;
}


// EJERCICIO 3
float densidadPoblacion(toroide const &t) {
    float resp = -1;
    int filas = t.size();
    int columnas = t[0].size();
    float cantidadVivas = 0;
    for (int i = 0 ; i<filas ; i++){
        for (int j = 0 ; j<columnas ; j++){
            if (t[i][j]){
                cantidadVivas++;
            }
        }
    }
    resp = cantidadVivas/filas/columnas;
    return resp;
}

// EJERCICIO 4
bool evolucionDePosicion(toroide const &t, posicion x) {
    bool vive = false;
    if (t[x.first][x.second]) {
        if (cantVecinosVivos(t, x) <= 3 && cantVecinosVivos(t, x) >= 2) {
            vive = true;
        }
    } else if (cantVecinosVivos(t, x) == 3) {
        vive = true;
    }
    return vive;
}

// EJERCICIO 5
void evolucionToroide(toroide &t) {
    int filas = t.size();
    int columnas = t[0].size();
    toroide copia = t;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++) {
            t[i][j]=evolucionDePosicion(copia,make_pair(i,j));
        }
    }
}

// EJERCICIO 6
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out = t;
    for (int i = 1; i <= K; i++){
        evolucionToroide(out);
    }
    return out;
}


// EJERCICIO 7
bool esPeriodico(toroide const &t, int &p) {
    if(toroideMuerto(t)){
        p = 1;
        return true;
    }
    toroide copia = t; // Creo una copia para poder evolucionarlo y despues compararlo con el inicial
    evolucionToroide(copia);
    int iteraciones = 1;
    while (copia!=t && !toroideMuerto(copia)){
        iteraciones++;
        evolucionToroide(copia);
    }
    if (toroideMuerto(copia)){
        return false;
    }
    p = iteraciones;
    return true;
}

// EJERCICIO 8
bool primosLejanos(toroide const &t, toroide const &u) {

    int p = 1;
    if (t==u && esPeriodico(t , p)){        // El ciclo en caso de ser periodico no se fija este caso.
        return true;
    }

    p = 0;

    if (esPrimoLejano(t,u,p)){
        return true;
    }

    if (esPrimoLejano(u,t,p)){ //Como la funcion se fija si t->u la llamo por segunda vez para ver si u->t
        return true;
    }

    return false;
}

// EJERCICIO 9
int seleccionNatural(vector <toroide> ts) {
    // Tener en cuenta que si 2 toroides tardan lo mismo en morir, me piden el primero.
    int rango = ts.size();
    int indiceMaximo = 0;
    int maximo = encontrarMinimoTicksHastaMuerto(ts[0]); //Es el maximo de los minimoTicksHastaMuerto

    for (int i = 0 ; i<rango ; i++){
        int auxiliar = encontrarMinimoTicksHastaMuerto(ts[i]);
        if (auxiliar>maximo){
            maximo = auxiliar;
            indiceMaximo = i;
        }

    }
    return indiceMaximo;
}


// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u) {
    toroide fusion = t;
    int filas = t.size();
    int columnas = t[0].size();

    for (int i = 0 ; i<filas ; i++){
        for (int j = 0 ; j<columnas ; j++){
            if (t[i][j] && u[i][j]){ // Si ambas estan vivas
                fusion[i][j] = true;
            }
            else {
                fusion[i][j] = false;
            }
        }
    }
    return fusion;
}

// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u){
    int filas = t.size();
    int columnas = t[0].size();

    if (cantidadVivas(t)!=cantidadVivas(u)){
        return false;
    }

    for (int i = 0 ; i<filas ; i++){ //Hay filas*columnas diferentes traslaciones.
        for (int j = 0 ; j<columnas ; j++){
            if (trasladado(t,u,i,j)){
                return true;
            }
        }
    }
    return false;
}

// EJERCICIO 12
int menorSuperficieViva(toroide const &t){
    if(cantidadVivas(t) == 0){
        return 0;
    }
    int minSuperficie = superficieViva(t); //inicializo este valor con la superficie viva del toroide sin trasladar para poder compararlo despues con las del toroide trasladado
    int filas = t.size();
    int columnas = t[0].size();

    for (int i = 0 ; i < filas ; i++){
        for (int j = 0 ; j < columnas ; j++){
            int superficie = superficieViva(trasladar(t,i,j));
            if(superficie < minSuperficie){
                minSuperficie = superficie;
            }
        }
    }
    return minSuperficie;

}