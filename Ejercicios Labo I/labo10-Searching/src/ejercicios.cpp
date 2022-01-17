#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

vector<string> split(string s, char delim){
	vector<string> v;
	int i=0;
	while (i < s.size()){
	    if(s[i] == delim){
	        i++;
	    }else{
	        v.push_back("");
	        while (s[i] != delim && i < s.size()){
	            v[v.size()-1].push_back(s[i]);
	            i++;
	        }
	    }
	}
	return v;
}

string darVueltaPalabra(string s){
	string res;
	vector<string> v = split(s, ' ');
	for (int i=v.size()-1; i >= 0; i--){
        for (int j = 0; j < v[i].size(); ++j) {
            res.push_back(v[i][j]);
        }
        if( i != 0) {
            res.push_back(' ');
        }
	}
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
    int indice=0;
    int cont = 0;
	for (int i = 0; i < s1.size(); i++){
        for (int j = indice ; j < s2.size()  ; ++j) {
            if(s1[i] == s2[j]){
                cont++;
                indice= j+1;
                break;
            }
        }
	}
	return cont == s1.size();
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string> > res;
    for (int i = 0; i < v.size(); ++i) {
        bool aparece = false;
        for (int j = 0; j < res.size(); ++j) {
            if (mismasApariciones( v[i] , res[j][0])) {
                res[j].push_back(v[i]);
                aparece = true;
                }
            }
        if(aparece == false){
            res.push_back({v[i]});
        }
    }
	return res;
}
// hace bien las ordenaciones pero no se porque me agrupa "solo" con "otro"

bool mismasApariciones(string s1, string s2){
    int apariciones=0;
    if( s1.size() != s2.size()){
        return false;
    }
    if(s1 == s2){
        return true;
    }
    for (int i = 0; i < s1.size() ; ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            if(s1[i] == s2[j]){
                apariciones++;
            }
        }
    }
    return apariciones == s1.size();
}
bool esPalindromo(string s){
	bool cumple = true;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != s[s.size()-1-i]){
            cumple=false;
        }
    }
    return cumple;
}

bool tieneRepetidos(string s){
    int repetidos=0;
    for (int i = 0; i < s.size() ; ++i) {
        for (int j = 0; j < s.size() && j != i ; ++j) {
            if(s[i]==s[j]){
                repetidos++;
            }
        }
    }
    return repetidos != 0;
}

string rotar(string s, int j){
	string res(s);
	int lon = s.size();
    for (int i = 0; i < s.size(); ++i) {
        res[(i+j)%lon]=s[i];
    }
	return res;
}

// no se puede usar substring
string darVueltaK(string s, int k){
	string res(s);
	/*int i =0;
	while (i < s.size()) {
	    while (i < i + k && i < s.size()){

	    }
    }*/
	return res;
}

string abueloLaino(string s){
    string res="S";
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='i'){
            res="N";
        }
    }
    return res;
}

int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

int middleOut(string s, string t){

    return 0;
}
