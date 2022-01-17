#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;


TEST(seleccionNaturalTEST, toroideDiagonalVsUnoVivo){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, true, false},
                  {false, false, false}, 
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}
/* este test no era valido
TEST(seleccionNaturalTEST, DiagonalVsHorizontal){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}*/

TEST(seleccionNaturalTEST, listaDeConsecutivosHastaMuerteGana0){
    toroide t1 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, true, false, true, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t2 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, true, false, false, true, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t3 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, false, false, false, true, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t4 = { {false, false, false, false, false, false, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t5 = { {false, false, false},
                   {false, false, false},
                   {false, false, false}
    };

    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    ts.push_back(t4);
    ts.push_back(t5);

    int res = seleccionNatural(ts);
    EXPECT_EQ(res,0);
}

TEST(seleccionNaturalTEST, listaDeConsecutivosHastaMuerteGana4){
    toroide t1 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, true, false, true, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t2 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, true, false, false, true, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t3 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, false, false, false, true, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t4 = { {false, false, false, false, false, false, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t5 = { {false, false, false},
                   {false, false, false},
                   {false, false, false}
    };

    vector<toroide> ts;
    ts.push_back(t5);
    ts.push_back(t4);
    ts.push_back(t3);
    ts.push_back(t2);
    ts.push_back(t1);

    int res = seleccionNatural(ts);
    EXPECT_EQ(res,4);
}

TEST(seleccionNaturalTEST, listaDeConsecutivosHastaMuerteGana2){
    toroide t1 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, true, false, true, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t2 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, true, false, false, true, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t3 = { {false, false, false, false, false, false, false},
                   {false, false, false, true, true, false, false},
                   {false, false, false, false, false, true, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t4 = { {false, false, false, false, false, false, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, true, false, false},
                   {false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false}
    };

    toroide t5 = { {false, false, false},
                   {false, false, false},
                   {false, false, false}
    };

    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t3);
    ts.push_back(t1);
    ts.push_back(t5);
    ts.push_back(t4);

    int res = seleccionNatural(ts);
    EXPECT_EQ(res,2);
}
