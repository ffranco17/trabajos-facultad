//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones

pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
bool esRectangulo(vector<vector<bool>> const &v);
int cantVecinosVivos(toroide const &t, posicion x);
int corregirPosicion(int i, int size);
bool toroideMuerto(toroide t);
bool esPrimoLejano(toroide t, toroide u, int p);
bool primoLejanoEnUnCiclo(toroide t, toroide u, int p);
bool igualaOMuere(toroide t, toroide u);
int encontrarMinimoTicksHastaMuerto(toroide t);
int cantidadVivas(toroide t);
bool trasladado(toroide t, toroide u, int f, int c);
int superficieViva(toroide t);
toroide trasladar(toroide t, int x, int y);

#endif //REUNIONESREMOTAS_AUXILIARES_H
