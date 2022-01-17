#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void swap( vector<int> &v, int i, int j ){
    int guardar = v[j];
    v[j] = v[i];
    v[i] = guardar;
}

void insert(vector<int> &v, int i ){
    for (int j = i; j > 0 && v[j] > v[j-1] ; j--) { //habia que ordenarlo en el otro orden
        swap(v, j, j-1);
    }
}
void insertionSort(vector< int > &arr){
	for(int i = 0; i < arr.size(); i++){
	    insert(arr, i);
	}

}

int findMinPosition(vector<int> &v, int d, int h ){
    int min = d;
    for (int i = d+1; i < h; ++i) {
        if(v[i] < v[min]){
            min = i;
        }
    }
    return min;
}

void selectionSort(vector< int > &arr){
    for (int i = 0; i < arr.size()-1; ++i) {
        int minPos = findMinPosition(arr, i, arr.size());
        swap(arr, i, minPos);
    }
}


vector<int> reconstruir(vector<int> &lista, vector<int> conteo){
    vector<int> res(lista.size());
    int n = 0;
    int indice_conteo = n-1;
    for (int i = 0; i < n; ++i) {
        while (conteo[indice_conteo] == 0){
            indice_conteo++;
        }
        lista[i]=indice_conteo;
        conteo[indice_conteo]--;
    }
    return res;
}

vector<int> contar (vector<int> &lista){
    vector<int> conteo(99, 0);
    int n = lista.size();
    for (int i = 0; i < n; ++i) {
        conteo[lista[i]]++;
    }
    return conteo;
}

vector<int> countingSort(vector<int> &lista){
    vector<int> conteo= contar(lista);
    return reconstruir(lista, conteo);
}

void ordenar(vector<int> &items){
	countingSort(items);
}


int bestFit(int W, vector<int> &items){
	multiset<int> restos;
	for(int i=0; i<(int)items.size(); ++i){
		restos.insert(W);
	}
	int res = 0;
	for(int i=0; i<(int)items.size(); ++i){
		multiset<int>::iterator it = restos.lower_bound(items[i]);
		int restoAct = *it;
		if(restoAct==W){
			res++;
		}
		restoAct -= items[i];
		restos.erase(it);
		restos.insert(restoAct);
	}
	return res;
}

int main(){
	int N, W, aux;

	//Se levantan los items y la capacidad del contenedor
	cout << "Se levantan los items y la capacidad del contenedor";
	ifstream bpp("BPP.in");
	bpp >> N >> W;
	vector<int> items;
	for(int i=0; i<N; ++i){
		bpp >> aux;
		items.push_back(aux);
	}
	bpp.close();
	//Se corre best-fit
	int cant1 = bestFit(W, items);
	cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

	//Se ordenan los items
	ordenar(items);
	//Se corre best-fit-decreasing
	int cant2 = bestFit(W, items);
	cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

	return 0;
}
