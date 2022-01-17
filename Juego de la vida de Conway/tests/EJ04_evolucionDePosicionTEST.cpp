#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(evolucionDePosicionTEST, toroideDiagonalTresPorTres){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, NoRevivePorCincoVecinosVivos){
    toroide t = { {false, true, true}, {false, true, false}, {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
}

TEST(evolucionDePosicionTEST, posicionBordeVive ){
    toroide t = {{true,false,false},{false,false,false},{true,false,true}};
    EXPECT_TRUE(evolucionDePosicion(t,make_pair(0,0)));
}

TEST(evolucionDePosicionTEST, posicionBordeRevive ){
    toroide t = {{true,false,false},{false,false,true},{false,true,false}};
    EXPECT_TRUE(evolucionDePosicion(t,make_pair(2,2)));
}

TEST(evolucionDePosicionTEST, posicionBordeMuerePorSobrepoblacion ){
    toroide t = {{false,true,true},{false,true,true},{false,true,true}};
    EXPECT_FALSE(evolucionDePosicion(t,make_pair(1,2)));
}
TEST(evolucionDePosicionTEST, posicionCentralNoRevivePorSobrepoblacion){
    toroide t = {{true,true,true,false},{true,false,true,false},{true,true,true,false},{false,false,false}};
    EXPECT_FALSE(evolucionDePosicion(t,make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, toroideGrandeCelulaAlejada){
    toroide t = {{true,true,true,true,true},{true,false,false,false,true},{true,false,false,false,true},{true,false,false,false,true},{true,true,true,true,true}};
    EXPECT_FALSE(evolucionDePosicion(t,make_pair(2,2)));
}