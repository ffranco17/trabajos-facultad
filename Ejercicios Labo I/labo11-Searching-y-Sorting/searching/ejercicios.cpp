#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include<iostream>
#include <cmath>

using namespace std;

int busquedaBinariaDesdeHasta(vector<int> v, int desde, int hasta, int x ){
    int res = -1;
    while (desde <= hasta){
        int medio = desde + (hasta-desde)/2;
        if(v[medio] == x){
            res = medio;
        }
        if(v[medio] < x){
            desde = medio + 1;
        }else{
            hasta = medio - 1;
        }
    }
    return res;
}

int busquedaBinariaHastaDesde(vector<int> v, int desde, int hasta, int x ){
    int res = -1;
    while (desde <= hasta){
        int medio = desde + (hasta-desde)/2;
        if(v[medio] == x){
            res = medio;
        }
        if(v[medio] < x){
            hasta = medio - 1;
        }else{
            desde = medio + 1;
        }
    }
    return res;
}

int busquedaBinaria(vector<int> v, int x){
	int hasta = v.size() -1;
    if( v.size() > 1 && v[0] > v[1]){
        return busquedaBinariaHastaDesde(v, 0, hasta, x);
    }else{
        return busquedaBinariaDesdeHasta(v, 0, hasta, x);
    }
}

//esta solo la programe para el caso de que este ordenado ascendentemente para el caso descendente no
int busquedaJumpSearch(vector<int> v, int x){
	int m = sqrt(v.size());
	int hasta = -1;
    for (int i = 0; i < v.size() && hasta == -1; i = i + m ) {
        if(v[i] > x){
            hasta = i;
        }
    }
    if (hasta == -1){
        hasta = v.size() -1;
    }
    return busquedaBinariaDesdeHasta(v, 0, hasta, x);
}

int buscar(vector<int> v, int x){
    return busquedaBinaria(v, x);
    //return busquedaJumpSearch(v, x);
}


double ejemplo_como_calcular_tiempos() {
    clock_t begin = clock();

    for(int i=0 ; i < 100000; i++){
        // nada
    }

    clock_t end = clock();
    double elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en milisegundos
    return elapsed_msecs;
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}



int indicePico(vector<int> v){
	if(v.size() == 1){
	    return 0;
	}
	if (v[0] >= v[1] ){
	    return 0;
	}
	if (v[v.size() - 2] <= v[v.size()-1]){
	    return v.size()-1;
	}
    for (int i = 1; i < v.size() -1 ; ++i) {
        if(v[i] >= v[i-1] && v[i] >= v[i+1]){
            return i;
        }
    }
    return -1;
}

int puntoFijo(vector<int> v){
    int res = -1;
    int desde = 0;
    int hasta = v.size() -1;
    while (desde <= hasta){
        int medio = desde + (hasta-desde)/2;
        if(v[medio] == medio){
            res = medio;
            while(v[res-1] == res -1){
                res = res - 1;
            }
        }
        if(v[medio] > medio){
            hasta = medio - 1;
        }else{
            desde = medio + 1;
        }
    }
    return res;
}

int encontrarRotado(vector<int> v, int x){
	return -1;
}

int menorMasGrande(vector<int> v, int x){
    int res = -1;
    int desde = 0;
    int hasta = v.size()-1;
    if (v.size() == 1 && v[0] >= x){
        return 0;
    }
    while (desde <= hasta){
        int medio = desde + (hasta-desde)/2;
        if(medio == 0 && v[medio] > x){
            res = medio;
        }else if(v[medio] > x && v[medio-1]<= x){
            res = medio;
        }
        if(v[medio] < x){
            desde = medio + 1;
        }else{
            hasta = medio - 1;
        }
    }
    return res;
}

int difAbs (int x, int t ){
    int res = x - t;
    if (res < 0){
        res = - res;
    }
    return res;
}
void selectionSort(vector<int> &v){
    for (int i = 0; i < v.size()-1; ++i) {
        int minPos = findMinPosition(v, i, v.size());
        swap(v, i, minPos);
    }
}

int findMinPosition(vector<int> &v, int d, int h ){
    int min = d;
    for (int i = d+1; i < h; ++i) {
        if(v[i] < v[min]){
            min = i;
        }
    }
    return min;
}

void swap( vector<int> &v, int i, int j ){
    int guardar = v[j];
    v[j] = v[i];
    v[i] = guardar;
}
vector<int> masCercanoK(vector<int> v, int k,  int x){
	vector<int> res;
	int contador = 0;
	int c1 =  menorMasGrande(v,x);
	int c2 = c1 -1;
	if (v[c2] == x){
	    c2 = c2 -1;
	}
	if( v.size() == 1){
	    return {v[0]};
	}
	while (contador < k){
	    if(c1 >= v.size()){
            res.push_back(v[c2]);
            c2--;
            contador++;
	    }else if ( c2 < 0 ){
            res.push_back(v[c1]);
            c1++;
            contador++;
	    }else {
            if (difAbs(x, v[c1]) < difAbs(x, v[c2])) {
                res.push_back(v[c1]);
                c1++;
                contador++;
            } else if (difAbs(x, v[c1]) == difAbs(x, v[c2])) {
                if (v[c1] < v[c2]) {
                    res.push_back(v[c1]);
                    c1++;
                    contador++;
                } else {
                    res.push_back(v[c2]);
                    c2--;
                    contador++;
                }
            } else {
                res.push_back(v[c2]);
                c2--;
                contador++;
            }
        }
	}
	selectionSort(res);
    return res;
}
