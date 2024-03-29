#ifndef AED2_MAPA_H
#define AED2_MAPA_H

#include "Tipos.h"
#include "mapa.h"

using namespace std;

// using Mapa = Mapa;/* Completar con la clase Mapa implementada por ustedes */

class aed2_Mapa {
public:

	aed2_Mapa();
	/**
     * Pre:
     *  Todas las elevaciones están en rango. Todas las coordenadas de receptáculos
     *  están en rango y no se repiten.
     */
    aed2_Mapa(Nat ancho, Nat alto, set<Coordenada> elevaciones, map<Color, Coordenada> receptaculos);

    /**
     * Pre: 
     *  Existe c_1 adyacente a c que es piso y 
     *  existe c_2 adyacente a c que es elevación.
     */
    void agregarRampa(Coordenada c);

    Nat ancho() const;

    Nat alto() const;

    TipoCasillero tipoCasillero(Coordenada) const;

    const map<Color, Coordenada>& receptaculos() const;

    Coordenada receptaculo(Color c);

	// Conversiones
    
    // Esta función sirve para convertir del Mapa implementado por ustedes
    // a la clase Mapa de la cátedra
    aed2_Mapa(Mapa m);

    // Esta función sirve para convertir del Mapa de la cátedra (aed2_Mapa)
    // a la clase Mapa definida por ustedes
    Mapa mapa() const;
    map<Color,Coordenada> deDiccTrieADiccLineal(DiccTrie<Coordenada> d);

private:
    //completar
    Mapa _m;
    map<Color,Coordenada> _receptaculos;

};

#endif // AED2_MAPA_H