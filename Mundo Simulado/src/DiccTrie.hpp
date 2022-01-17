
#include "DiccTrie.h"

template <typename T>
DiccTrie<T>::DiccTrie():_size(0),_raiz(nullptr){
    // COMPLETAR
}

template <typename T>
DiccTrie<T>::DiccTrie(const DiccTrie<T>& aCopiar) : DiccTrie() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.



template<typename T>
void  DiccTrie<T>::buscarClave(Nodo *n,string const  & c,vector<string> &claves) const{
    for(int i =0;i<n->siguientes.size();i++){
        if(n->siguientes[i]!= nullptr){
            if(n->siguientes[i]->definicion!= nullptr){
                claves.push_back(c+char(i));
            }
           buscarClave(n->siguientes[i],c+char(i),claves);

        }
    }
}

template <typename T>
vector<string> DiccTrie<T>::claves() {
    vector<string>claves;
    string c;
    Nodo *n =_raiz;
    for(int i =0; i<_raiz->siguientes.size() ;i++){
        c=char(i);
        if(n->siguientes[i] != nullptr){
            if(n->siguientes[i]->definicion != nullptr){
                claves.push_back(c);
            }
            buscarClave(n->siguientes[i],c,claves);
        }
    }
    return claves;
}


template<typename T>
vector<string> DiccTrie<T>::claves() const {
    vector<string>claves;
    string c;
    Nodo *n =_raiz;
    for(int i =0; i<_raiz->siguientes.size() ;i++){
        c=char(i);
        if(n->siguientes[i] != nullptr){
            if(n->siguientes[i]->definicion != nullptr){
                claves.push_back(c);
            }
           buscarClave(n->siguientes[i],c,claves);
        }
    }
    return claves;
}

template <typename T>
DiccTrie<T>& DiccTrie<T>::operator=(const DiccTrie<T>& d) {
    if(d.empty()){
        _raiz = nullptr;
        _size = 0;
    } else {
        pair<string, T> p;
        _raiz = new Nodo();
        vector<string> c =d.claves();
        for(int i =0;i<c.size();i++){
            p = make_pair(c[i],d.at(c[i]));
            this->insert(p);
        }
    }
    return *this;
}

template <typename T>
void DiccTrie<T>::destruir(Nodo *n) {
    if(n != nullptr) {
        if (n->definicion != nullptr) {
            delete n->definicion;
            n->definicion= nullptr;
        }
        for (int i = 0; i < n->siguientes.size(); i++) {
            if (n->siguientes[i] != nullptr) {
                destruir(n->siguientes[i]);
                n->siguientes[i]= nullptr;
            }
        }
        delete n;
    }
}

template <typename T>
DiccTrie<T>::~DiccTrie(){
    if(_raiz != nullptr) {
        destruir(_raiz);
    }
}

template <typename T>
T& DiccTrie<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int DiccTrie<T>::count(const string & clave) const{
    if(_raiz == nullptr)
        return 0;
    Nodo *n = _raiz;
    bool coincide= true;
    int i =0;
    for(i =0;(i<clave.size()-1) && coincide;i++){
        if(n->siguientes[clave[i]] == nullptr){
            coincide=false;
        }
        n = n->siguientes[clave[i]];
    }
    if(!coincide){
        return 0;
    }
    if(n->siguientes[clave[i]]== nullptr){
        coincide = false;
    } else {
        coincide = n->siguientes[clave[i]]->definicion != nullptr;
    }

    return coincide? 1 : 0;
}


template <typename T>
const T & DiccTrie<T>::at(const string & clave) const {
   Nodo *n = _raiz ;
   int i =0;
   for(i=0;i<clave.size()-1;i++){
       n=n->siguientes[clave[i]];
   }
   return *(n->siguientes[clave[i]]->  definicion);
}

template <typename T>
T & DiccTrie<T>::at(const string & clave) {
    Nodo *n = _raiz ;
    int i =0;
    for(i=0;i<clave.size()-1;i++){
        n=n->siguientes[clave[i]];
    }

    return *(n->siguientes[clave[i]]->definicion);
}




template <typename T>
void DiccTrie<T>::erase(const string& clave) {
    Nodo *n=_raiz,*ultimo= nullptr,*anterior = nullptr; char d ;
    _size--;
    for(char c:clave){
        if(cantidadDeHijos(n)>1){
            ultimo = n;
            d=c;
        }
        anterior =n;
        n = n->siguientes[c];
    }
    delete n->definicion ;
    n->definicion= nullptr;
    if(cantidadDeHijos(n)==0){
        if(ultimo == nullptr){
            destruir(_raiz->siguientes[clave[0]]);
            _raiz ->siguientes [clave[0]] = nullptr;
        } else {
            destruir(ultimo->siguientes[clave[d+1]]);
            ultimo->siguientes[clave[d+1]]= nullptr;
        }
    }

}

template<typename T>
int DiccTrie<T>::cantidadDeHijos(Nodo *n) {
    int cont = 0;
    for(int i =0;i<n->siguientes.size();i++){
        if(n->siguientes[i]!= nullptr){
            cont++;
        }
    }
    return cont ;
}

//template<typename T>
//void string_map<T>::buscarYDestruir(string_map::Nodo *n, string_map::Nodo *ultimo, const string &c, int i,int u) {
//
//    if(i == c.size()-1){
//       delete n->definicion;
//       n->definicion= nullptr;
//       if(cantidadDeHijos(n)>0){
//
//       } else if(ultimo== nullptr){
//           destruir(_raiz->siguientes[c[0]]);
//           _raiz ->siguientes[c[0]] = nullptr;
//       } else {
//           destruir(ultimo->siguientes[c[u+1]]);
//           ultimo ->siguientes[c[u+1]] = nullptr;
//       }
//    } else if(cantidadDeHijos(n)>1) {
//        buscarYDestruir(n->siguientes[c[i+1]],n,c,i+1,i);
//    } else {
//        buscarYDestruir(n->siguientes[c[i+1]],ultimo,c,i+1,u);
//    }
//
//}
//
//
//template<typename T>
//void string_map<T>::erase(const string &key) {
//
//    buscarYDestruir(_raiz->siguientes[key[0]], nullptr,key,0,0);
//    _size--;
//}

template <typename T>
int DiccTrie<T>::size() const{
    return _size;
}

template <typename T>
bool DiccTrie<T>::empty() const{
   return _raiz == nullptr;
}

template<typename T>
void DiccTrie<T>::insert(const pair<string , T >  &p) {

    if(this->count(p.first)==1){
        Nodo *n =_raiz;
        int i;
        for(i=0;i<p.first.size();i++){
            n = n->siguientes[p.first[i]];
        }

        delete n->definicion;
        n->definicion = new T (p.second);
    }else {

        if (_raiz == nullptr) {
            _raiz = new Nodo();
        }
        int i = 0;
        Nodo *n = _raiz;
        for (i = 0; i < p.first.size() - 1; i++) {
            if (n->siguientes[p.first[i]] == nullptr) {
                n->siguientes[p.first[i]] = new Nodo();
                n = n->siguientes[p.first[i]];
            } else {
                n = n->siguientes[p.first[i]];
            }
        }
        n->siguientes[p.first[i]] = new Nodo(p.second);
        _size++;
    }
}



template<typename T>
DiccTrie<T>::Nodo::Nodo():siguientes(256, nullptr),definicion(nullptr) {}

template<typename T>
DiccTrie<T>::Nodo::Nodo(T def):siguientes(256, nullptr),definicion(new T (def)) {}
