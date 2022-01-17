#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(primosLejanosTEST, toroideHorizontalPeriodico2){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {false, false, false, false, false}, 
                  {false, false, true, false, false}, 
                  {false, false, true, false, false},
                  {false, false, true, false, false}, 
                  {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, FalseUnPeriodico){
    toroide t1 = { {false, false, false, false, false, false, false}, //Este muere y nunca iguala a t2
                   {false, false, false, true, true, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, true, false, true, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t2 = { {false, false, false, false, false, false, false},
                   {false, true, true, true, false, false, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false}
    };

    bool res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
    res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, TrueNingunPeriodico){
    toroide t1 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, true, false, true, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t2 = { {false, false, false, false, false, false, false}, //ESTE es el 1 +2 ticks
                   {false, false, false, true, true, false, false},
                   {false, false, false, false, false, true, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false}
    };

    bool res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
    res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, iguales) {
    toroide t1 = {{true,  true,  false, true},
                  {true,  false, false, false},
                  {false, false, false, false},
                  {false, false, false, false}
    };

    bool res = primosLejanos(t1, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, ToroideComunVSToroideMuerto){
    toroide t1 = {{true,  false, false},
                 {false, true,  false},
                 {false, false, true}};
    toroide t2 = {{false,false,false},
                     {false,false,false},
                     {false,false,false}};


    bool res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
    res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, ambosMuertos) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
    res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, toroidesIgualesPeriodicos) {
    toroide t = {
            {true,  true,  false},
            {true,  true,  false},
            {false, false, false}};
    bool res = primosLejanos(t, t);
    EXPECT_TRUE(res);
}