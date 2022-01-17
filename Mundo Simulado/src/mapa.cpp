#include "mapa.h"

Mapa::Mapa(): _alto(0), _ancho(0), _receptaculos(),
    _receptaculosLineal(), _mapaElevaciones(), _mapaColoresCasillas() {}


Mapa& Mapa::operator=(const Mapa& m){
    _mapaColoresCasillas = m.coloresCasillas();
    _mapaElevaciones = m.elevacionesCasillas();
    _receptaculos = m.receptaculos();
    _receptaculosLineal = m.receptaculosLineal();
    _ancho = m.ancho();
    _alto = m.alto();
    return *this;
}

Mapa::Mapa(const map<Color, Coordenada>& rs, vector<vector<TipoCasillero>> elevaciones) {
 _alto = elevaciones.size();
 _ancho = elevaciones[0].size();
 _mapaElevaciones = elevaciones;
 _receptaculosLineal = rs;
 vector<vector<Color>> mc (_alto,vector<Color> (_ancho,""));
 for(const auto& key : rs){
    _receptaculos.insert(key);
//    mc[key.second.first][key.second.second]=  key.first;
    mc[key.second.second][key.second.first]=  key.first;
 }
 _mapaColoresCasillas=mc;
}

Nat Mapa::ancho() const{
    return _ancho;
}

Nat Mapa::alto() const {
    return _alto;
}

const DiccTrie<Coordenada> &Mapa::receptaculos() const{
    return _receptaculos;
}

Coordenada Mapa::receptaculo(const Color& c){
    return _receptaculos.at(c);
}

TipoCasillero Mapa::tipoCasillero(Coordenada pos) const{
 //   return _mapaElevaciones[pos.first][pos.second];
    return _mapaElevaciones[pos.second][pos.first];
}

void Mapa:: agregarRampa(Coordenada c){
  //  _mapaElevaciones[c.first][c.second] = RAMPA;
    _mapaElevaciones[c.second][c.first] = RAMPA;
}

bool Mapa::esPared(Coordenada pos){
    return _mapaElevaciones[pos.second][pos.first] == ELEVACION;
}

bool Mapa::esPiso(Coordenada pos){
    return _mapaElevaciones[pos.second][pos.first] == PISO;
}

bool Mapa::esRampa(Coordenada pos){
    return _mapaElevaciones[pos.second][pos.first] == RAMPA;
}

vector<vector<Color>> Mapa::coloresCasillas() const {
    return _mapaColoresCasillas;
}

vector<vector<TipoCasillero>> Mapa::elevacionesCasillas() const {
    return _mapaElevaciones;
}
bool Mapa::enRango(Coordenada pos) {
    return pos.first >= 0 && pos.first < _ancho && pos.second >= 0 && pos.second < _alto;
}

const map<Color, Coordenada>& Mapa::receptaculosLineal() const{
    return _receptaculosLineal;
}