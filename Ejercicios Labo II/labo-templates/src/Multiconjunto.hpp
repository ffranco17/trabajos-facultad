#include "Diccionario.hpp"

template<class T>
class Multiconjunto{
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro) const;

private:
    Diccionario<T, int> _multi;
};

template<class T>
Multiconjunto<T> ::Multiconjunto() {}

template<class T>
void Multiconjunto<T> ::agregar(T x) {
    if(_multi.def(x)){
        _multi.definir(x, _multi.obtener(x) + 1);
    }else{
        _multi.definir(x, 1);
    }
}

template<class T>
int Multiconjunto<T> ::ocurrencias(T x) const{
    if(_multi.def(x)){
        return _multi.obtener(x);
    }else{
        return 0;
    }
}

template<class T>
bool Multiconjunto<T> ::operator<=(Multiconjunto<T> otro) const{
    int aux = (_multi.claves()).size();
    for (int i = 0; i < aux; ++i) {
       if (ocurrencias(_multi.claves()[i]) > otro.ocurrencias(_multi.claves()[i])){
            return false;
       }
    }
    return true;
}

