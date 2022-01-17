template <typename T>
string_map<T>::string_map(){
    // COMPLETAR
    raiz = new Nodo();
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
    for (int i = 0; i < raiz->siguientes.size(); ++i) {
        if (raiz->siguientes[i] != nullptr){
            borrar(raiz->siguientes[i]);
        }
    }
    delete raiz;
    raiz = new Nodo();
    copiar(raiz, d.raiz);
    _size = d.size();
}

template <typename T>
void string_map<T>::copiar(Nodo* r, Nodo* n) {
    if (n->definicion != nullptr){
        T* aux = new T(*n->definicion);
        r->definicion = aux;
    }
    for (int i = 0; i < raiz->siguientes.size(); ++i) {
        if (n->siguientes[i] != nullptr){
            r->siguientes[i] = new Nodo;
            copiar(r->siguientes[i], n->siguientes[i]);
        }
    }

}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
    borrar(raiz);
}

template <typename T>
void string_map<T>::borrar(Nodo* n){
    if(n->definicion != nullptr) {
        delete (n->definicion);
    }
    for (int i = 0; i < raiz->siguientes.size(); ++i) {
        if(n->siguientes[i] != nullptr){
            borrar(n->siguientes[i]);
            n->siguientes[i] = nullptr;
        }
    }
    delete n;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& tupla){
    Nodo* actual = raiz;
    for (int i = 0; i < tupla.first.size(); ++i) {
        if(actual->siguientes[int(tupla.first[i])] != nullptr){
            actual = actual->siguientes[int(tupla.first[i])];
        }else{
            actual->siguientes[int(tupla.first[i])] = new Nodo();
            actual = actual->siguientes[int(tupla.first[i])];
        }
    }
    if (actual->definicion != nullptr){
        delete (actual->definicion);
    }
    T* aux = new T(tupla.second);
    actual->definicion = aux;
    _size++;
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR
    Nodo* actual = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        if(actual->siguientes[int(clave[i])] != nullptr){
            actual = actual->siguientes[int(clave[i])];
        }else{
            return 0;
        }
    }
    if(actual->definicion != nullptr) {
        return 1;
    }else{
        return 0;
    }
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    // COMPLETAR
    Nodo* actual = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        actual = actual->siguientes[int(clave[i])];
    }
    return *actual->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
    Nodo* actual = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        actual = actual->siguientes[int(clave[i])];
    }
    return *actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
    Nodo* actual = raiz;
    Nodo* borrar = raiz;
    int indice = 0;
    for (int i = 0; i < clave.size(); ++i) {
        actual = actual->siguientes[int(clave[i])];
        if (actual->definicion != nullptr || tieneHijos(actual)){
            borrar = actual;
            indice = i;
        }
    }
    delete (actual->definicion);
    actual->definicion = nullptr;
    if (indice != clave.size()-1){
        indice++;
        int aux = indice;
        Nodo* sig = borrar->siguientes[int(clave[indice])];
        for (int i = indice; i < clave.size(); ++i) {
            actual = sig;
            indice++;
            sig = sig->siguientes[int(clave[indice])];
            delete actual;
        }
        borrar->siguientes[int(clave[aux])] = nullptr;
    }
    _size--;

}


template <typename T>
bool string_map<T>::tieneHijos(Nodo* n){
    for (int i = 0; i < raiz->siguientes.size(); ++i) {
        if(n->siguientes[i] != nullptr){
            return true;
        }
    }
    return false;
}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR
    int res = 0;
    for (int i = 0; i < raiz->siguientes.size(); ++i) {
        if(raiz->siguientes[i] != nullptr){
            res = res + recorrer(raiz->siguientes[i]);
        }
    }
    return res;
}

template <typename T>
int string_map<T>::recorrer(Nodo* n) const{
    int res = 0;
    if (n->definicion != nullptr){
        res++;
    }
    for (int i = 0; i < raiz->siguientes.size(); ++i) {
        if(n->siguientes[i] != nullptr){
            res = res + recorrer(n->siguientes[i]);
        }
    }
    return res;
}

template <typename T>
bool string_map<T>::empty() const{
    // COMPLETAR
    return raiz != nullptr;
}