#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {true, true, true}, {true, true, true}, {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresDosPasos) {
    toroide t = {{true,  false, false},
                 {false, true,  false},
                 {false, false, true}};
    toroide evo_t = {{false,false,false},
                     {false,false,false},
                     {false,false,false}};

    toroide res = evolucionMultiple(t, 2);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideMuerto){
    toroide t = {{false,false,false},{false,false,false},{false,false,false}};
    toroide evo_t = {{false,false,false},{false,false,false},{false,false,false}};
    toroide res = evolucionMultiple(t, 5);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroidePeriodico) {
    toroide t = {{false, false, false, false, false},
                 {false, false, false, false, false},
                 {false, true, true, true, false},
                 {false, false, false, false, false},
                 {false, false, false, false, false}};
    toroide evo_t = {{false, false, false, false, false},
                     {false, false, false, false, false},
                     {false, true, true, true, false},
                     {false, false, false, false, false},
                     {false, false, false, false, false}};
    toroide res = evolucionMultiple(t, 4);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionToroideTEST, casoNormalPorDos) {
    toroide t = {{false, false, false, false, false},
                 {false, false, true, false, false},
                 {false, true, true, true, false},
                 {false, false, true, false, false},
                 {false, false, false, false, false}};
    toroide evo_t = {{false, false, true, false, false},
                     {false, true, false, true, false},
                     {true, false, false, false, true},
                     {false, true, false, true, false},
                     {false, false, true, false, false}};
    toroide res = evolucionMultiple(t,2);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideMuereEnMenosQueK) {
    toroide t = {{true,  false, false},
                 {false, true,  false},
                 {false, false, true}};
    toroide evo_t = {{false,false,false},
                     {false,false,false},
                     {false,false,false}};

    toroide res = evolucionMultiple(t, 20);
    EXPECT_EQ(res, evo_t);
}