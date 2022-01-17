#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int sum = 17 + 5;
    int res = 22;
    EXPECT_EQ(sum, res);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    float pot = pow(10, 2);
    float res = 100;
    EXPECT_EQ(pot, res);
}

// Ejercicios 6..9
TEST(Aritmetica, potencia_general){
    float pot1 = pow(-5,2);
    float res1 = 25;
    float pot2 = pow(0,2);
    float res2 = 0;
    float pot3 = pow(1,2);
    float res3 = 1;
    float pot4 = pow(5,2);
    float res4 = 25;
    EXPECT_EQ(pot1, res1);
    EXPECT_EQ(pot2, res2);
    EXPECT_EQ(pot3, res3);
    EXPECT_EQ(pot4, res4);
}

TEST(Diccionario, obtener){
    map<int, int> dicc;
    int res = 5;
    dicc[2] = res;
    EXPECT_EQ(dicc[2], res);
}

TEST(Diccionario, definir){
    map<int, int> m;
    EXPECT_EQ(m.count(5), 0);
    m[5] = 10;
    EXPECT_EQ(m.count(5), 1);
}

TEST(Truco, inicio){
    Truco t;
    EXPECT_EQ(t.puntaje_j1(), 0);
    EXPECT_EQ(t.puntaje_j2(), 0);
}

TEST(Truco, buenas){
    Truco t;
    EXPECT_FALSE(t.buenas(1));
    for (int i = 0; i < 15; ++i) {
        t.sumar_punto(1);
    }
    EXPECT_FALSE(t.buenas(1));
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
    t.sumar_punto(1);
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
}