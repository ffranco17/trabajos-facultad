#include "aed2_simulacion.h"

map<Color, Coordenada> deDiccTrieADiccLineal(DiccTrie <Coordenada> d);

aed2_Simulacion::aed2_Simulacion(const aed2_Mapa &mapa, const map<Color, Coordenada> &objetos, Coordenada inicio)
:_s(mapa.mapa(),inicio,objetos),_posObjetos(objetos) {

}

void aed2_Simulacion::mover(Direccion d) {
    _s.mover(d);
    _posObjetos = deDiccTrieADiccLineal(_s.posObjetos());
    _objetivosDispLista = deSetALista(_s.objetivosDisponibles());
}

void aed2_Simulacion::agregarObjetivo(Objetivo o) {
    if(_s.agObjetivo(o)){
        _objetivosDispLista.push_back(o);
    }
}

const aed2_Mapa aed2_Simulacion ::mapa() const {
    return _s.mapa();
}

const map<Color, Coordenada> &aed2_Simulacion::posObjetos() const {
    return _posObjetos;
}


Coordenada aed2_Simulacion::posAgente() const{
    return _s.posicionJugador();
}

const list<Objetivo> &aed2_Simulacion::objetivosDisponibles() const{

    return _objetivosDispLista;
}


Nat aed2_Simulacion::movimientos() const {
    return _s.cantMovimientos();
}

Nat aed2_Simulacion::objetivosResueltos() const {
    return _s.cantObjetivosRealizados();
}

list<Objetivo> aed2_Simulacion::deSetALista(const set<Objetivo> &aConvertir) {
    list<Objetivo> res;
    for(auto elem : aConvertir){
        res.push_back(elem);
    }
    return res;
}

map<Color, Coordenada> deDiccTrieADiccLineal(DiccTrie <Coordenada> d) {
    vector<string> claves = d.claves();
    map<Color,Coordenada> res;
    for(int i = 0;i<claves.size();i++){
        res[claves[i]] = d.at(claves[i]);
    }
    return res;
}


// completar