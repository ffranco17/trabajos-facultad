#include<string>
#include<vector>

using namespace std;

template<class T>
T cuadrado(T t){
    return t*t;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor c, Elem e){
    for (int i = 0; i < c.size(); ++i) {
        if(c[i] == e){
            return true;
        }
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    if(a.size() >= b.size()){
        return false;
    }else{
        for (int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]){
                return false;
            }
        }
    }
    return true;
}

template<class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem max = c[0];
    for (int i = 1; i < c.size(); ++i) {
        if(c[i] > max){
            max = c[i];
        }
    }
    return max;
}

