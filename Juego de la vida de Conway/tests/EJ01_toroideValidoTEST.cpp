#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(toroideValidoTEST, toroideTOTALMENTEVacio) {
    toroide t = {};
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, toroideVacio){
    toroide t = { vector<bool> () };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, toroideVacio5Filas){
    vector<bool> vacio;
    toroide t = { vacio, vacio, vacio, vacio, vacio };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, diagonalTresPorTres) {
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}
    };
    EXPECT_TRUE(toroideValido(t));
}

TEST(toroideValidoTEST, noRectangulo) {
    toroide t = { {true, true, true},
                  {true, false},
                  {true}
    };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, toroideValido) {
    toroide t = { {true, true, false, true},
                  {false, false, true, false},
                  {true, false, false, false}
    };
    EXPECT_TRUE(toroideValido(t));
}

TEST(toroideValidoTEST, rectanguloNoValido) {
    toroide t = { {true,false},
                  {false,true}
    };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, unoPorUno) {
    toroide t = {{true}};
    EXPECT_FALSE(toroideValido(t));
}