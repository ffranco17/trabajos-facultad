#include "simulacion.h"

#include <utility>

simulacion::simulacion():_mapa(),_cantObjetivosRealizados(),_cantMovimientos(),
_posJugador(),_posObjetos(),_colorObjetos(),_conjObjetivos(),_objetivosDisponibles(){}

simulacion::simulacion(const Mapa &m, Coordenada p, const map<Color, Coordenada> &l) :
        _mapa(m), _cantObjetivosRealizados(0), _cantMovimientos(0), _posJugador(move(p)),
        _posObjetos(deDiccLinealADiccTrie(l)),
        _objetivosDisponibles(), _colorObjetos(guardarPosiciones(m, l)){}

 DiccTrie<Coordenada> simulacion::deDiccLinealADiccTrie(const map<Color,Coordenada>&l) {
    DiccTrie<Coordenada> PosObjetos;
    for (const pair<Color, Coordenada>& objetoCoordenada : l) {
        PosObjetos.insert(objetoCoordenada);
    }
    return PosObjetos;
}

 vector<vector<Color>> simulacion::guardarPosiciones(const Mapa &m, const map<Color, Coordenada> &l) {
    vector<vector<Color>> ColorObjetos(m.alto(),vector<Color>(m.ancho(),""));
    for(pair<Color,Coordenada> e : l){
//        ColorObjetos[e.second.first][e.second.second]= e.first;
        ColorObjetos[e.second.second][e.second.first]= e.first;
    }
     return ColorObjetos;
}

const Mapa &simulacion::mapa() const {
    return _mapa;
}

Coordenada simulacion::posicionJugador() const {
    return _posJugador;
}

Nat simulacion::cantMovimientos() const {
    return _cantMovimientos;
}

const set<Objetivo> &simulacion::objetivosDisponibles() const {
    return _conjObjetivos;
}

Nat simulacion::cantObjetivosRealizados() const {
    return _cantObjetivosRealizados;
}

Coordenada simulacion::posDelObjeto(const Color& c) {
        return _posObjetos.at(c);
}

const DiccTrie<Coordenada>& simulacion::posObjetos() const{
    return _posObjetos;
}


void simulacion::mover(Direccion d) {
    Coordenada siguientePosJugador = siguientePosicion(_posJugador, d);
    if (_mapa.enRango(siguientePosJugador)){
        _cantMovimientos++;
        if (agenteSeMueve(d)){
            if (hayObjeto(siguientePosJugador)){
                Coordenada PosObjeto = moverObjeto(d);
                if (seCumpleObjetivo(PosObjeto)){
                    _cantObjetivosRealizados++;
                    DiccTrie<set<Objetivo>::iterator> &objetivosDeObjeto = _objetivosDisponibles.at(_colorObjetos[PosObjeto.second][PosObjeto.first]);
                    _conjObjetivos.erase(objetivosDeObjeto.at(_mapa.coloresCasillas()[PosObjeto.second][PosObjeto.first]));
                    objetivosDeObjeto.erase(_mapa.coloresCasillas()[PosObjeto.second][PosObjeto.first]);
                    _objetivosDisponibles.erase(_colorObjetos[PosObjeto.second][PosObjeto.first]);
                    //_conjObjetivos.erase(itObjetivo);
                }
            }
            _posJugador = siguientePosJugador;
        }
    }
}

Coordenada simulacion::siguientePosicion(Coordenada c, Direccion d) {
    switch(d) {
        case ARRIBA:
            c.second++;
            break;
        case ABAJO:
            c.second--;
            break;
        case DERECHA:
            c.first++;
            break;
        case IZQUIERDA:
            c.first--;
            break;
    }
    return c;
}

bool simulacion::agenteSeMueve(Direccion d) {
    Coordenada posSiguiente = siguientePosicion(_posJugador, d);
    return _mapa.enRango(posSiguiente) && !(_mapa.esPiso(_posJugador) && _mapa.esPared(posSiguiente))
        && ( objetoSePuedeMover(posSiguiente, d) || ! hayObjeto(posSiguiente) );
}

bool simulacion::hayObjeto(Coordenada c) {
    return !_colorObjetos[c.second][c.first].empty();
}

bool simulacion::objetoSePuedeMover(Coordenada posDelObjeto, Direccion d) {
    Coordenada posSiguiente = siguientePosicion(posDelObjeto, d);
    return _mapa.enRango(posSiguiente) &&  !(_mapa.esPiso(posDelObjeto) && _mapa.esPared(posSiguiente)) && !(hayObjeto(posSiguiente));
}

Coordenada simulacion::moverObjeto(Direccion d) {
    Coordenada posObjeto = siguientePosicion(_posJugador, d);
    Color objeto = _colorObjetos[posObjeto.second][posObjeto.first];
    _colorObjetos[posObjeto.second][posObjeto.first].clear();
    Coordenada posSiguienteObjeto = siguientePosicion(posObjeto, d);
    _colorObjetos[posSiguienteObjeto.second][posSiguienteObjeto.first] = objeto;
    _posObjetos.insert(make_pair(objeto, posSiguienteObjeto));
    return posSiguienteObjeto;
}

bool simulacion::seCumpleObjetivo(Coordenada c) {
    Color objeto = _colorObjetos[c.second][c.first];
    Color posicion = _mapa.coloresCasillas()[c.second][c.first];
    return  _objetivosDisponibles.count(objeto) == 1 && _objetivosDisponibles.at(objeto).count(posicion) == 1;
}

bool simulacion::agObjetivo( Objetivo o)   {
    if (objetivoValido(o)) {
        Coordenada objeto = _posObjetos.at(o.objeto());
        Coordenada receptaculo = _mapa.receptaculo(o.receptaculo());
        if(objeto == receptaculo ){
           _cantObjetivosRealizados++;
            return false ;
        }
        if (!(_objetivosDisponibles.count(o.objeto()) == 1 && (_objetivosDisponibles.at(o.objeto()).count(o.receptaculo())) == 1)){
            auto it = _conjObjetivos.insert(o).first;
            if (_objetivosDisponibles.count(o.objeto())){
                _objetivosDisponibles.at(o.objeto()).insert(make_pair(o.receptaculo(), it));
            } else{
                DiccTrie<set<Objetivo>::iterator> co;
                co.insert(make_pair(o.receptaculo(),it));
                _objetivosDisponibles.insert(make_pair(o.objeto(),co));
            }
        }
        return true;
    }else{
        return false;
    }
}

bool simulacion::objetivoValido(Objetivo o) {
    return (_posObjetos.count(o.objeto()) == 1) && (_mapa.receptaculos().count(o.receptaculo()) == 1);
}





