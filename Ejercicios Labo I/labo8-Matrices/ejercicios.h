#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v);
void trasponer(vector<vector<int> > &m);
int posicionij(vector<vector<int> > m1, vector<vector<int> > m2, int i, int j);
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2);
float promedioij(vector<vector<int>> v, int i, int j);
vector<vector<int> > promediar(vector<vector<int> > m);
bool esPico(vector<vector<int>> m, int i, int j);
int contarPicos(vector<vector<int> > m);
bool triangSup(vector<vector<int>> v);
bool triangInf(vector<vector<int>> v);
bool esTriangular(vector<vector<int> > m);
bool hayAmenaza(vector<vector<int> > m);
int diagonal(vector<vector<int>> v);
int diagonalInv(vector<vector<int>> v);
int diferenciaDiagonales(vector<vector<int> > m);