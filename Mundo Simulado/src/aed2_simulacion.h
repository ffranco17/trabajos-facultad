#ifndef AED2_SIMULACION_H
#define AED2_SIMULACION_H

#include "Tipos.h"
#include "aed2_mapa.h"
#include "simulacion.h"
#include "Objetivo.h"


class aed2_Simulacion {
public:

    /**
     * Pre:
     *  > inicio está en contenido en mapa
     *  > las coordenadas en objetos estan en mapa y no se repiten
     *  > las coordenadas en objetos no se solapan con la posición del agente
     */
    aed2_Simulacion(const aed2_Mapa& mapa, const map<Color, Coordenada>& objetos, Coordenada inicio);

    void mover(Direccion);

    void agregarObjetivo(Objetivo);

    const aed2_Mapa mapa() const;

    const map<Color, Coordenada>& posObjetos() const;

    Coordenada posAgente() const;

    const list<Objetivo>& objetivosDisponibles() const;

    Nat movimientos() const;
    
    Nat objetivosResueltos() const;


private:
    //completar
    simulacion _s;
    list<Objetivo> _objetivosDispLista;
    map<Color,Coordenada> _posObjetos;

    list<Objetivo> deSetALista(const set<Objetivo> &set);
};

#endif // AED2_SIMULACION_H
