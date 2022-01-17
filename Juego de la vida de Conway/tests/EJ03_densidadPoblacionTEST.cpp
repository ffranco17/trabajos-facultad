#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

TEST(densidadPoblacionTEST, todosVivos) {
    toroide t = { {true, true, true, true},
                  {true, true, true, true},
                  {true, true, true, true},
                  {true, true, true, true},
                  {true, true, true, true}
    }; // Creo que es exactamente el mismo text de arriba, pero no importa, si ya lo escribi no hay razon para no usarlo

    EXPECT_NEAR(densidadPoblacion(t),1,0.001);
}


TEST(densidadPoblacionTEST, todosMuertos) {
    toroide t = { {false, false, false, false},
                  {false, false, false, false},
                  {false, false, false, false}
    };

    EXPECT_NEAR(densidadPoblacion(t),0,0.001);
}

TEST(densidadPoblacionTEST, UnoSiUnoNo) {
    toroide t = { {true, false, true, false, true},
                  {false, true, false, true, false},
                  {true, false, true, false, true},
                  {false, true, false, true, false}
    };

    EXPECT_NEAR(densidadPoblacion(t),0.5,0.001);
}

TEST(densidadPoblacionTEST, diagonalViva) {
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}
    };

    EXPECT_NEAR(densidadPoblacion(t),0.333333,0.001);
}

TEST(densidadPoblacionTEST, toroideMuyLargo) {
    toroide t = { {true, true, true, true},
                  {true, true, true, false},
                  {true, true, false, true},
                  {true, true, false, false},
                  {true, false, true, true},
                  {true, false, true, false},
                  {true, false, false, true},
                  {true, false, false, false},
                  {false, true, true, true},
                  {false, true, true, false},
                  {false, true, false, true},
                  {false, true, false, false},
                  {false, false, true, true},
                  {false, false, true, false},
                  {false, false, false, true},
                  {false, false, false, false}
    };

    EXPECT_NEAR(densidadPoblacion(t),0.5,0.001);
}