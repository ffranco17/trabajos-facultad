#ifndef DICCTRIE_H_
#define DICCTRIE_H_

#include <string>

using namespace std;

template<typename T>
class DiccTrie {
public:
    /**
    CONSTRUCTOR
    * Construye un diccionario vacio.
    **/
    DiccTrie();

    /**
    CONSTRUCTOR POR COPIA
    * Construye un diccionario por copia.
    **/
    DiccTrie(const DiccTrie<T>& aCopiar);

    /**
    OPERADOR ASIGNACION
     */
    DiccTrie& operator=(const DiccTrie& d);

    /**
    DESTRUCTOR
    **/
    ~DiccTrie();

    /**
    INSERT 
    * Inserta un par clave, valor en el diccionario
    **/
    void insert(const pair <string, T>&p );

    /**
    COUNT
    * Devuelve la cantidad de apariciones de la clave (0 o 1).
    * Sirve para identificar si una clave está definida o no.
    **/

    int count(const string & clave) const;

    /**
    AT
    * Dada una clave, devuelve su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    -- Versión modificable y no modificable
    **/
    const T &  at(const string & clave) const;
    T &  at(const string &clave);
    /**
    ERASE
    * Dada una clave, la borra del diccionario junto a su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    **/
    void erase(const string & key);

    /**
     SIZE
     * Devuelve cantidad de claves definidas */
    int size() const;

    /**
     EMPTY
     * devuelve true si no hay ningún elemento en el diccionario */
    bool empty() const;

    /** OPTATIVO
    * operator[]
    * Acceso o definición de pares clave/valor
    **/
    T &operator[](const string &key);
    vector<string> claves();

    vector<string> claves()const;
private:

    struct Nodo {
        vector<Nodo*> siguientes;
        Nodo();
        explicit Nodo(T def);
        T* definicion;
    };
    void buscarClave(Nodo *n,string const & c,vector<string> &claves)const;
   // void buscarYDestruir(Nodo *n,Nodo *ultimo,const string &c,int i,int u);
    int cantidadDeHijos(Nodo *n);

    void destruir(Nodo *n);

    Nodo* _raiz;
    int _size;
};


#include "DiccTrie.hpp"

#endif // DICCTRIE_H_
