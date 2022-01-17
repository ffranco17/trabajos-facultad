#include "Lista.h"

Lista::Lista() {
    // Completar
    _primero = nullptr;
    _ultimo = nullptr;
    _long = 0;
}
Lista:: Nodo::Nodo(int elem) : valor(elem), anterior(nullptr), siguiente(nullptr){}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
    while (_primero != nullptr){
        Nodo* p= _primero;
        _primero = _primero->siguiente;
        delete p;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    int l = this->longitud();
    for (int i = 0; i < l; ++i) {
        this->eliminar(0);
    }

    for (int i = 0; i < aCopiar.longitud(); ++i) {
        this->agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
    Nodo* nodo = new Nodo(elem);
    if(_long > 0) {
        _primero->anterior = nodo;
        nodo->siguiente = _primero;
        _primero = nodo;
    }else{
        _primero = nodo;
        _ultimo = nodo;
    }
    this->_long++;
}

void Lista::agregarAtras(const int& elem) {
    // Completar
    Nodo* nodo = new Nodo(elem);
    if(_long > 0) {
        _ultimo->siguiente = nodo;
        nodo->anterior = _ultimo;
        _ultimo = nodo;
    }else{
        _primero = nodo;
        _ultimo = nodo;
    }
    this->_long++;
}

void Lista::eliminar(Nat i) {
    // Completar
    Nodo* p = _primero;

    for (int j = 0; j < i; ++j) {
        p = p->siguiente;
    }

    //voy a suponer que no pueden pasarme una lista vacia o un i fuera de las dimensiones de la lista
    if(_long == 1){
        _primero = nullptr;
        _ultimo = nullptr;
        delete p;
    }else{
        if (i == 0){
            _primero = p->siguiente;
            _primero->anterior = nullptr;
            delete p;
        }else{
            if (i == _long-1){
                _ultimo = p->anterior;
                _ultimo->siguiente = nullptr;
                delete p;
            }else{
                (p->anterior)->siguiente = p->siguiente;
                (p->siguiente)->anterior = p->anterior;
                delete p;
            }
        }
    }
    _long--;
}

int Lista::longitud() const {
    // Completar
    return _long;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    Nodo* p = _primero;
    for (int j = 0; j < i; ++j) {
        p = p->siguiente;
    }
    return p->valor;
}


int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* p = _primero;
    for (int j = 0; j < i; ++j) {
        p = p->siguiente;
    }
    return p->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
