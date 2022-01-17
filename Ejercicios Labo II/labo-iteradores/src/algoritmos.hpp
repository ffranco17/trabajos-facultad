#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::value_type min = *it;
    while(it != c.end()){
        if(*it < min){
            min = *it;
        }
        ++it;
    }
    return min;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    typename Contenedor::value_type total = *it;
    int cantidad = 1;
    ++it;
    while(it != c.end()){
        total = total + *it;
        cantidad++;
        ++it;
    }
    return total/cantidad;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type min = *desde;
    auto it = desde;
    while(it != hasta){
        if(*it < min){
            min = *it;
        }
        ++it;
    }
    return min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    auto it = desde;
    typename Iterator::value_type total = *desde;
    int cantidad = 1;
    ++it;
    while(it != hasta){
        total = total + *it;
        cantidad++;
        ++it;
    }
    return total/cantidad;
}

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    auto it = c.begin();
    while(it != c.end()){
        if(*it == elem){
            it = c.erase(it);
        }else{
            ++it;
        }
    }

}

template<class Contenedor>
bool ordenado(Contenedor &c){
    auto it1= c.begin();
    auto it2= c.begin();
    ++it2;
    while(it2 != c.end()){
        if(not(it1 < it2)){
            return false;
        }
        ++it1;
        ++it2;
    }
    return true;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem) {
    Contenedor c1;
    Contenedor c2;
    auto it= c.begin();
    auto it1= c1.begin();
    auto it2= c2.begin();

    while(it != c.end()){
        if(*it < elem){
            it1 = c1.insert(it1, *it);
            ++it1;
        }else{
            it2 = c2.insert(it2, *it);
            ++it2;
        }
        ++it;
    }
    return make_pair(c1, c2);
}

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    auto it1 = c1.begin();
    auto it2 = c2.begin();
    auto it = res.end();
    while(it1 =! c1.end() || it2 =! c2.end()){
        if(it1 == c1.end()){
            it = res.insert(it, *it2);
            ++it2;
        }else{
            if(it2 == c2.end()){
                it = res.insert(it, *it1);
                ++it1;
            }else{
                if(*it1 < *it2){
                    it = res.insert(it, *it1);
                    ++it1;
                }else{
                    it = res.insert(it, *it2);
                    ++it2;
                }
            }
        }
        ++it;
    }

}
#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
