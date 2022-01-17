#include "ejercicios.h"


// Ejercicio 1 
bool existePico(vector<int> v){
    bool res = false;
    if(v.size() > 2){
        for(int i=1; i < v.size()-1; i++){
            res= res || ((v[i] > v[i-1]) & (v[i] > v[i+1]));
        }
    }
	return res;
}


// Ejercicio 3 
int indiceMinSubsec(vector<int> v, int l, int r){

    int minimo=r;
    if( v.size() > 1) {
        for (int i = r; i >= l; i=i-1) {
            if(v[i]< v[minimo]){
                minimo = i;
            }else{
                minimo = minimo;
            }
        }
    }
    if(v.size() == 1){
        minimo = 0;
    }
	return minimo;
}

// Ejercicio 4 
void ordenar1(vector<int>& v){
    int minimo;
    int guardar;
//por las dudas, lo que hace es calcular el indice del minimo y ese valor lo pone en la posicion mas a
//a la izquierda y en la posicion en la q estaba este valor pone el que estaba en la posicion mas a la
//izquierda, este ultimo valor fue guardado previamente en la variable guardar
    for(int i=0; i < v.size(); i++){
        minimo=indiceMinSubsec(v,i,v.size()-1);
        guardar=v[i];
        v[i]=v[minimo];
        v[minimo]=guardar;
    };
}

// Ejercicio 5 
int cantApariciones(vector<int> v, int k){
    int res=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]==k){
            res= res + 1;
        }
    }
    return res;
}
void ordenar2(vector<int>& v){
    int i=cantApariciones(v,0);
    int j=cantApariciones(v,1);
    for (int k=0; k<i; k++){
        v[k]=0;
    }
    for (int k=i; k<i+j; k++){
        v[k]=1;
    }
    for (int k=i+j; k<v.size(); k++){
        v[k]=2;
    }

}

// Ejercicio 6 
tuple<int,int> division(int n, int d){
    int cociente = 0;
    int resto = n;

    if(d!=0) {

        while (n >= d) {
            n = n - d;
            cociente = cociente + 1;
            resto = n;
        }
    }
    return make_tuple(cociente,resto);
}
