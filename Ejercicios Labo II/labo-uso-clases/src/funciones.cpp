#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> aux;
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        if (aux.count(s[i]) == 0){
            aux.insert(s[i]);
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> aux;
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        if (aux.count(s[i]) == 0){
            aux.insert(s[i]);
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;
    set<int> aux;
    for (int i = 0; i < a.size(); ++i) {
        aux.insert(a[i]);
    }
    for (int i = 0; i < b.size(); ++i) {
        if (aux.count(b[i]) == 0){
            res = false;
        }else{
            res = res && true;
        }
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    bool res = true;
    set<int> aux;
    for (int i = 0; i < a.size(); ++i) {
        aux.insert(a[i]);
    }
    for (int i = 0; i < b.size(); ++i) {
        if (aux.count(b[i]) == 0){
            res = false;
        }else{
            res = res && true;
        }
    }
    return res;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    vector<int> aux = quitar_repetidos(s);
    map<int, int> res;
    for (int i = 0; i < aux.size(); ++i) {
        res[aux[i]] = 0;
    }
    for (int i = 0; i < s.size(); ++i) {
        res[s[i]]++;
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> aux = quitar_repetidos(s);
    map<int, int> dicc = contar_apariciones(s);
    vector<int> res;
    for (int i = 0; i < aux.size(); ++i) {
        if (dicc[aux[i]] == 1){
            res.push_back(aux[i]);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int x : a) {
        if (b.count(x) == 1){
            res.insert(x);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for (int i = 0; i < s.size(); ++i) {
        res[s[i] % 10].insert(s[i]);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res = str;
    for (int i = 0; i < str.size(); ++i) {
        for (int j = 0; j < tr.size(); ++j) {
            if (str[i] == tr[j].first){
                res[i]=tr[j].second;
            }
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    vector<set<LU>> libretas;
    for (int i = 0; i < s.size(); ++i) {
        libretas.push_back(s[i].libretas());
    }

    for (int i = 0; i < libretas.size()-1 ; ++i) {
        for (int j = i+1; j < libretas.size() ; ++j) {
            if (s[i] == s[j]){
                res = res;
            }else{
                for(LU x : libretas[i]){
                    if(libretas[j].count(x) == 1){
                        return true;
                    }
                }
            }
        }
    }
    return res;

}


// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  map<set<LU>, Mail> res;
    for (int i = 0; i < s.size(); ++i) {
        if (res[s[i].libretas()].fecha() < s[i].fecha() && s[i].adjunto()) {
            res[s[i].libretas()] = s[i];
        }
    }
    return res;
}
