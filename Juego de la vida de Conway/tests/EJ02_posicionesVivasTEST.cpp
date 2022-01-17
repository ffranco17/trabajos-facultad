#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(posicionesVivasTEST, toroideDiagonalVivas){
    toroide t = { 
	{true, false, false},
	{false, true, false},
	{false, false, true},
	{true, false, false},
	{false, true, false},
	{false, false, true}};

    vector<posicion> vivas = {mp(0,0), mp(1,1), mp(2,2), mp(3, 0), mp(4, 1), mp(5, 2)};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, toroideTodoVivo) {
    toroide t = { {true, true, true, true, true},
                  {true, true, true, true, true},
                  {true, true, true, true, true}
    };

    vector<posicion> vivas = {{0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,0}, {1,1}, {1,2},
                              {1,3}, {1,4}, {2,0}, {2,1}, {2,2}, {2,3}, {2,4}};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, toroideMuerto) {
    toroide t = { {false, false, false, false},
                  {false, false, false, false},
                  {false, false, false, false},
                  {false, false, false, false},
                  {false, false, false, false}
    };

    vector<posicion> vivas = {};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, soloBordesVivos) {
    toroide t = { {true, false, false, false},
                  {false, false, false, false},
                  {false, false, false, true}
    };

    vector<posicion> vivas = {{0,0}, {2,3}};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, soloBordesMuertos) {
    toroide t = { {false, true, true, true},
                  {true, true, true, true},
                  {true, true, true, false}
    };

    vector<posicion> vivas = {{0,1}, {0,2}, {0,3}, {1,0}, {1,1}, {1,2}, {1,3},
                              {2,0}, {2,1}, {2,2}};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, Variado) {
    toroide t = { {true, false, true, true, false},
                  {true, false, false, true, false},
                  {false, false, false, false, false},
                  {true, true, true, true, true},
                  {false, true, false, true, true}
    };

    vector<posicion> vivas = {{0,0}, {0,2}, {0,3}, {1,0}, {1,3},
                              {3,0}, {3,1}, {3,2}, {3,3}, {3,4},
                              {4,1}, {4,3}, {4,4}};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}


