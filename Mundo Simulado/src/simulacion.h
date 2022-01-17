#ifndef TP3_ALGO2LANDIA_SIMULACION_H
#define TP3_ALGO2LANDIA_SIMULACION_H

#include "mapa.h"
#include "Tipos.h"
#include "DiccTrie.h"
#include "Objetivo.h"

class simulacion {

public:
    simulacion();
    simulacion(const Mapa&, Coordenada, const map<Color,Coordenada>&l);
    void mover(Direccion);
    bool agObjetivo(const Objetivo o);
    const Mapa& mapa() const;
    Coordenada posicionJugador() const;
    Nat cantMovimientos() const;
    const set<Objetivo>& objetivosDisponibles() const;
    Nat cantObjetivosRealizados() const;
    Coordenada posDelObjeto(const Color&);
    const DiccTrie<Coordenada>& posObjetos() const;

private:
    Mapa _mapa;
    Nat _cantObjetivosRealizados;
    Nat _cantMovimientos;
    Coordenada _posJugador;
    DiccTrie<Coordenada> _posObjetos;
    vector<vector<Color>> _colorObjetos;
    DiccTrie<DiccTrie<set<Objetivo>::iterator >> _objetivosDisponibles;
    set<Objetivo> _conjObjetivos;

    static DiccTrie<Coordenada> deDiccLinealADiccTrie(const map<Color, Coordenada>&);
    static vector<vector<Color>> guardarPosiciones(const Mapa&,const map<Color, Coordenada>&d);
    static Coordenada siguientePosicion(Coordenada, Direccion);
    bool agenteSeMueve(Direccion);
    bool hayObjeto(Coordenada);
    bool objetoSePuedeMover(Coordenada, Direccion);
    Coordenada moverObjeto(Direccion);
    bool seCumpleObjetivo(Coordenada);
    bool objetivoValido(const Objetivo o);
};


#endif //TP3_ALGO2LANDIA_SIMULACION_H
