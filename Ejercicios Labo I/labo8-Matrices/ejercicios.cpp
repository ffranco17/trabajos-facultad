#include "ejercicios.h"

//listo
vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
    int n= u.size();
    int m= v.size();
    vector<vector<int> > res(n,vector<int>(m));
    int i=0;
    while(i<n){
        int j=0;
        while(j<m){
            res[i][j]=u[i]*v[j];
            j++;
        }
        i++;
    }
    return res;
}

//listo
void trasponer(vector<vector<int> > &m) {
	int l=m.size();
	int a=m[0].size();
    vector<vector<int> > og(l,vector<int>(a));
    for(int i=0;i<l;i++){
        for(int j=0;j<a;j++){
            og[i][j]=m[i][j];
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<a;j++){
            m[i][j]=og[j][i];
        }
    }

	return;
}

//listo
int posicionij(vector<vector<int> > m1, vector<vector<int> > m2, int i, int j){
    int res=0;
    int k=0;
    while(k < m1[0].size()){
        res= res + m1[i][k]*m2[k][j];
        k++;
    }
    return res;
}
vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
	int n= m1.size();
	int m= m2[0].size();
    vector<vector<int>> res(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res[i][j]=posicionij(m1,m2,i,j);
        }
    }
	return res;
}

//listo
float promedioij(vector<vector<int>> v, int i, int j){
    int suma=0;
    int cant=0;
    for (int k = i-1; k <= i+1 ; k++) {
        if(k >= 0 && k < v.size()){
            for (int l = j-1; l <= j+1; l++) {
                if (l>=0 && l < v[0].size()){
                    suma= suma + v[k][l];
                    cant= cant + 1;
                }
            }
        }
    }
    return suma/cant;
}
vector<vector<int> > promediar(vector<vector<int> > m){
	int l=m.size();
	int a=m[0].size();
    vector<vector<int> > res(l, vector<int>(a));
    for(int i=0;i<l;i++){
        for(int j=0;j<a;j++){
            res[i][j]=promedioij(m,i,j);
        }
    }
	return res;
}

//listo
bool esPico(vector<vector<int>> m, int i, int j){
    for (int k = i-1; k <= i+1 ; k++) {
        if (k >= 0 && k < m.size()) {
            for (int l = j - 1; l <= j + 1; l++) {
                if (l >= 0 && l < m[0].size()) {
                    if(k != i || l != j){
                        if(m[k][l] >= m[i][j]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
int contarPicos(vector<vector<int> > m){
	int res=0;
    int l=m.size();
    int a=m[0].size();
    for(int i=0;i < l;i++){
        for(int j=0;j < a;j++){
            if(esPico(m,i,j)){
                res= res + 1;
            }
        }
    }
	return res;
}

//listo
bool triangSup(vector<vector<int>> v){
    for (int i = v.size()-1; i > 0 ; i=i-1) {
        for (int j = i-1; j >=0 ; j=j-1) {
            if(v[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

bool triangInf(vector<vector<int>> v){
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v[0].size() ; j++) {
            if(v[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

bool esTriangular(vector<vector<int> > m){
	if(triangSup(m)==true){
	    return true;
	}
	if(triangInf(m)==true){
	    return true;
	}
	return false;
}

//este no lo hice porque no lo entiendo, nunca jugué al ajedrez xd
bool hayAmenaza(vector<vector<int> > m){
	//COMPLETAR
	return true;
}

//listo
int diagonal(vector<vector<int>> v){
    int res=0;
    for(int i=0;i<v.size();i++){
        res= res + v[i][i];
        }
    return res;
}
int diagonalInv(vector<vector<int>> v){
    int res=0;
    for(int i=0;i<v.size();i++){
        res= res + v[i][v.size()-1-i];
    }
    return res;
}

int diferenciaDiagonales(vector<vector<int> > m) {
    int resta=diagonal(m) - diagonalInv(m);
    if(resta < 0){
        return -resta;
    }else{
        return resta;
    }
}