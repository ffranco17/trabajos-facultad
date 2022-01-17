#include "aed2_mapa.h"

aed2_Mapa::aed2_Mapa(): _m(), _receptaculos(){};

aed2_Mapa::aed2_Mapa(Nat ancho, Nat alto, set<Coordenada> elevaciones, map<Color, Coordenada> receptaculos) {
    _receptaculos = receptaculos;
    vector<vector<TipoCasillero>> mapa_elevaciones(alto,vector<TipoCasillero>(ancho,PISO));
    for(Coordenada c : elevaciones){
        mapa_elevaciones[c.second][c.first] = ELEVACION;
    }

    Mapa m(receptaculos, mapa_elevaciones);
    _m = m;
}


Nat aed2_Mapa::alto() const {
    return _m.alto();
}

Nat aed2_Mapa::ancho() const {
    return _m.ancho();
}

void aed2_Mapa::agregarRampa(Coordenada c) {
    _m.agregarRampa(c);

}

Coordenada aed2_Mapa::receptaculo(Color c) {
    return _receptaculos[c];
}

TipoCasillero aed2_Mapa::tipoCasillero(Coordenada pos) const {
    return _m.tipoCasillero(pos);
}

const map<Color, Coordenada> &aed2_Mapa::receptaculos() const {
    return _receptaculos;
}

aed2_Mapa::aed2_Mapa(Mapa m){
    _m = m;
    _receptaculos = _m.receptaculosLineal();
}


Mapa aed2_Mapa::mapa() const{
    return _m;
}


//completar