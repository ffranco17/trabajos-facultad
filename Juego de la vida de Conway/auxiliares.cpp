#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios

pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

bool esRectangulo(vector<vector<bool>> const &v){
    int filas = v.size();
    int columnas = v[0].size();
    if (filas<1 || columnas<1){
        return false;
    }
    int i = 0;
    while(i<filas && v[i].size()==columnas){
        i++;
    }
    return i==filas;
}

int cantVecinosVivos(toroide const &t, posicion x){
    int filas = t.size();
    int columnas = t[0].size();
    int vivas = 0;
    for (int i=x.first-1; i <= x.first+1 ;i++ ){ //programe una funcion auxiliar para reposicionar las coordenadas si se salen del rango porque el % no funciona como se necesita para numeros negativos
        int posX = corregirPosicion(i,filas);
        for (int j = x.second-1; j <= x.second+1 ;j++) {
            int posY = corregirPosicion(j,columnas);
            if(t[posX][posY]){
                vivas= vivas + 1;
            }
        }
    }
    if(t[x.first][x.second]){ //como una celula no puede ser vecina de si misma, si es que la celula inicial estaba viva la tengo que descontar de la suma de vecinas vivas
        vivas = vivas-1;
    }
    return vivas;
}

int corregirPosicion(int i, int size){
    int posicion = i;
    if(i < 0){
        posicion = size +i;
    }
    if(i > size-1){
        posicion = size -i;
    }
    return posicion;
}

bool toroideMuerto(toroide t){
    int filas = t.size();
    int columnas = t[0].size();

    for (int i = 0 ; i<filas ; i++){
        for (int j = 0 ; j<columnas ; j++){
            if (t[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool esPrimoLejano(toroide t, toroide u, int p){

    if (esPeriodico(t,p)){
        if(primoLejanoEnUnCiclo(t,u,p)){
            return true;
        }
    }
    else {
        if(igualaOMuere(t,u)){
            return true;
        }
    }
    return false;
}

bool primoLejanoEnUnCiclo(toroide t, toroide u, int p){
    toroide copiat = t;
    for (int i = 0 ; i<p ; i++){  // Porque p es la cantidad de ticks hasta que se repita.
        evolucionToroide(copiat); // Antes que el if ==> necesito preguntar si eran iguales de antemano.
        if (copiat==u){
            return true;
        }
    }
    return false;
}

bool igualaOMuere(toroide t, toroide u){
    if (t == u){
        return false;
    }
    toroide copiat = t;
    while (copiat!=u && !toroideMuerto(copiat)){ // Solo puede terminarse si se muere o iguala a u.
        evolucionToroide(copiat); // Se dijo que no se iba a tomar en cuenta si se hacia periodico despues.
    }                                // Si aparece alguno como arriba no termina nunca. EVITARLO
    if (toroideMuerto(copiat) && copiat != u){
        return false;
    }
    return true;
}


int encontrarMinimoTicksHastaMuerto(toroide t){
    int iteraciones = 0;
    toroide copia = t;
    while (!toroideMuerto(copia)){
        iteraciones++;
        evolucionToroide(copia);
    }
    return iteraciones;
}

int cantidadVivas(toroide t){
    int cantidadVivas = 0;
    int filas = t.size();
    int columnas = t[0].size();

    for (int i = 0 ; i<filas ; i++){
        for (int j = 0 ; j<columnas ; j++){
            if (t[i][j]){
                cantidadVivas++;
            }
        }
    }
    return cantidadVivas;
}

bool trasladado(toroide t, toroide u, int f, int c){
    int filas = t.size();
    int columnas = t[0].size();

    for (int i = 0 ; i<filas ; i++){
        for (int j = 0 ; j<columnas ; j++){
            int filaAux = (i+f)%filas; // Necesario para que no se salga del rango.
            int columnaAux = (j+c)%columnas;
            if (t[i][j] != u[filaAux][columnaAux]){
                return false;
            }
        }
    }
    return true;
}

int superficieViva(toroide t){
    vector<posicion> vivas = posicionesVivas(t);
    int rango = vivas.size();
    int minI = vivas[0].first; // como la funcion posicionesVivas me da las posiciones vivas en orden es deducible que la fila del primer elemento que aparezca en vivas va a ser la primer fila de la matriz donde aparezcan celulas vivas
    int minJ = vivas[0].second;// las inicializo con un valor cualquiera dentro de los que estan en el vector vivas para poder ir comparando
    int maxI = vivas[rango-1].first;//algo similar a lo que pasa con minI, aprovecho que la funcion posicionesVivas me da las posiciones de las celulas en el orden en el que aparecen, entonces la fila de la ultima celula sera la ultima fila con celulas vivas
    int maxJ = vivas[0].second;

    for(int j = 0 ; j < rango ; j++){
        if(vivas[j].second < minJ){     //busca dentro de las posiciones de celuas vivas, el numero de columna menor
            minJ = vivas[j].second;
        }
    }

    for(int j = 0 ; j < rango ; j++){
        if(vivas[j].second > maxJ){    // lo mismo pero con el mayor
            maxJ = vivas[j].second;
        }
    }
    int area= (maxI - minI +1)*(maxJ - minJ +1); // le sumo 1 porque no me cuenta a la fila ni a la columna 0
    return area;
}

toroide trasladar(toroide t, int x, int y){ //no confundir con el auxiliar trasladado, esta funcion traslada un toroide x filas e y columnas
    int filas = t.size();
    int columnas = t[0].size();
    toroide res(filas,vector<bool> (columnas));

    for (int i = 0 ; i < filas ; i++){
        int posx = (i+x)%filas;
        for (int j = 0 ; j < columnas ; j++){
            int posy = (j+y)%columnas;
            res[posx][posy] = t[i][j];
        }
    }
    return res;
}