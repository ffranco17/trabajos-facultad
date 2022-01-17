#ifndef TP3_ALGO2LANDIA_MAPA_H
#define TP3_ALGO2LANDIA_MAPA_H

#include "Tipos.h"
#include "DiccTrie.h"

using  namespace std;
class Mapa{

public:
    Mapa();
    Mapa& operator=(const Mapa& m);
    Mapa(const map<Color, Coordenada>& rs, vector<vector<TipoCasillero>> elevaciones);
    Nat ancho() const;
    Nat alto() const;
    const DiccTrie<Coordenada>& receptaculos() const;
    Coordenada receptaculo(const Color& c);
    void agregarRampa(Coordenada c);
    TipoCasillero tipoCasillero(Coordenada pos) const;
    bool esPared(Coordenada pos);
    bool esPiso(Coordenada pos);
    bool esRampa(Coordenada pos);
    vector<vector<Color>> coloresCasillas() const;
    vector<vector<TipoCasillero>> elevacionesCasillas() const;
    bool enRango(Coordenada pos);

    const map<Color, Coordenada>& receptaculosLineal() const;

private:

    vector<vector<Color>> _mapaColoresCasillas;
    vector<vector<TipoCasillero>> _mapaElevaciones;
    DiccTrie<Coordenada> _receptaculos;
    map<Color, Coordenada> _receptaculosLineal; // Para usarse en la traducción.
    Nat _ancho;
    Nat _alto;
};


#endif //TP3_ALGO2LANDIA_MAPA_H

