#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, toroideFacil){
    toroide t = {{true,false,false},{true,false,false},{false,false,false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 2);
}

TEST(menorSuperficieVivaTEST, toroide4x4){
    toroide t = {{true,false,false,true},{false,false,false,false},{false,false,false,false},{false,false,false,true}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res,4);
}

TEST(menorSuperficieVivaTEST, unaSolaCelula){
    toroide t = {{false,false,false},{false,true,false},{false,false,false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, toroideMuerto){
    toroide t = {{false,false,false},{false,false,false},{false,false,false}};
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 0);
}