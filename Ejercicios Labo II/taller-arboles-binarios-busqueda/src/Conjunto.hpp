
template <class T>
Conjunto<T>::Conjunto() {
    // Completar
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
    destruir(_raiz);
}

template <class T>
void Conjunto<T>::destruir(Nodo * n){
    if (n!= nullptr) {
        destruir(n->izq);
        destruir(n->der);
        delete n;
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    aux_pertenece(_raiz, clave);
}
template <class T>
bool Conjunto<T>::aux_pertenece(Nodo * n, const T& clave) const {
    if(n != nullptr) {
        if (n->valor == clave) {
            return true;
        } else {
            if (clave > n->valor) {
                return aux_pertenece(n->der, clave);
            } else {
                return aux_pertenece(n->izq, clave);
            }
        }
    }
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(pertenece(clave) == false ) {
        aux_insertar(_raiz, clave);
    }
}

template <class T>
void Conjunto<T>::aux_insertar(Nodo * n, const T& clave){
    if(n == _raiz && _raiz == nullptr){
        Nodo * nuevo = new Nodo(clave);
        _raiz = nuevo;
    }else{
        if(n->valor > clave){
            if(n->izq == nullptr){
                Nodo * nuevo = new Nodo(clave);
                n->izq = nuevo;
                nuevo->padre = n;
            }else {
                aux_insertar(n->izq, clave);
            }
        }else{
            if(n->der == nullptr){
                Nodo * nuevo = new Nodo(clave);
                n->der = nuevo;
                nuevo->padre = n;
            }else {
                aux_insertar(n->der, clave);
            }
        }
    }
}

template <class T>
int Conjunto<T>::remover(const T& clave) {
    if(pertenece(clave)){
        if (cardinal() == 1 && clave == _raiz->valor){
            delete _raiz;
            _raiz = nullptr;
        }else{
            eliminar(nullptr, "", _raiz, clave);
        }
    }
}

template <class T>
void Conjunto<T>::eliminar(Nodo * padre, string dir, Nodo * n, const T& clave){
    if(n->valor == clave){
        if(n->izq == nullptr && n->der == nullptr){  //es hoja
            delete n;
            if(dir == "IZQ"){
                padre->izq = nullptr;
            }else{
                padre->der = nullptr;
            }
        }else{
            if(n->der != nullptr){
                n->valor = aux_min(n->der);
                eliminar(n, "DER", n->der, n->valor); //borra la copia
            }else{
                n->valor = aux_max(n->izq);
                eliminar(n, "IZQ", n->izq, n->valor);
            }
        }
    }else{
        if(n->valor > clave){
            eliminar(n, "IZQ", n->izq, clave);
        }else{
            eliminar(n, "DER", n->der, clave);
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    return aux_succ(_raiz, clave);
}

template <class T>
const T& Conjunto<T>::aux_succ(Nodo * n, const T& clave) const{
    if(n->valor == clave){
        if(n->der != nullptr){
            return aux_min(n->der);
        }else{
            if(n->padre->izq == n){
                return n->padre->valor;
            }else{
                Nodo* actual = n->padre;
                bool aux = false;
                while(!aux){
                    if(actual->padre->izq == actual){
                        actual = actual->padre;
                        aux = true;
                    }else{
                        actual = actual->padre;
                    }
                }
                return actual->valor;
            }
        }
    }else{
        if(n->valor > clave){
            return aux_succ(n->izq, clave);
        }else{
            return aux_succ(n->der, clave);
        }
    }
}


template <class T>
const T& Conjunto<T>::minimo() const {
    if(_raiz->izq == nullptr){
        return _raiz->valor;
    }else{
        return aux_min(_raiz);
    }
}

template <class T>
const T& Conjunto<T>:: aux_min(Nodo * n) const{
    if(n->izq == nullptr){
        return n->valor;
    }else{
        return aux_min(n->izq);
    }
}

template <class T>
const T& Conjunto<T>::maximo() const {
    if(_raiz->der == nullptr){
        return _raiz->valor;
    }else{
        return aux_max(_raiz);
    }
}

template <class T>
const T& Conjunto<T>:: aux_max(Nodo * n) const{
    if(n->der == nullptr){
        return n->valor;
    }else{
        aux_max(n->der);
    }
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return aux_cardinal(_raiz);
}

template <class T>
unsigned int Conjunto<T>::aux_cardinal(Nodo * n) const{
    unsigned int res = 0;
    if(n != nullptr){
        res = 1 + aux_cardinal(n->izq) + aux_cardinal(n->der);
    }
    return res;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    stack<Nodo *> s;
    Nodo *actual = _raiz;
    while (actual != nullptr || s.empty() == false) {
        while (actual != nullptr) {
            s.push(actual);
            actual = actual->izq;
        }
        actual = s.top();
        s.pop();
        cout<< actual->valor << " ";
        actual = actual->der;
    }
}

