#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


//Ejercicio 1 Bien
bool divide(vector<int> v, int a){
	// Dados un vector v y un int a, decide si a divide a todos los numeros de v.
	for (int i=0; i < v.size(); i++){
	    if((v[i] % a) != 0){
	        return false;
	    }
	}
    return true;
}

//Ejercicio 2 Bien
int mayor(vector<int> v){
	// Dado un vector v, devuelve el valor maximo encontrado.
	int res=v[0];
	for(int i=0; i < v.size(); i++){
	    if(v[i]>res){
	        res = v[i];
	    }
	}
	return res;
}

//Ejercicio 3 Bien
vector<int> reverso(vector<int> v){
	// Dado un vector v, devuelve el reverso.
	vector<int> res;
	for (int i=0; i< v.size(); i++){
	    res.push_back(v[v.size()-1 - i]);
	}
	return res;
}

//Ejercicio 4 Bien
vector<int> rotar(vector<int> v, int k) {
    // Dado un vector v y un entero k, rotar k posiciones los elementos de v.
    // [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
    vector<int> res(v.size());
    for (int i = 0; i < v.size(); i++) {
        res[i] = v[(i + k) % v.size()];
    }
    return res;
}
//Ejercicio 5

bool estaOrdenado(vector<int> v){
    bool res1=true;
    bool res2=true;
    bool res;
    if (v.size() > 1) {

        if (v[0] <= v[1]) {

            for (int i = 0; i < v.size()-1; i++) {
                if (v[i] <= v[i + 1]) {
                    res1 = res1 & true;
                }else{
                    res1 = res & false;
                }

            }
        }else{
            res1=false;
        }
        if (v[0] >= v[1]) {
            for (int i = 0; i < v.size()-1; i++) {
                if (v[i] >= v[i + 1]) {
                    res2 = res2 & true;
                }else{
                    res2 = res & false;
                }
            }

        }else{
            res2=false;
        }
    }
    res = res1 | res2;
    return res;
}
//Ejercicio 6 Bien
bool esPrimo(int n){
    if(n == 2){
        return true;
    }
    if(n > 2){
        for (int i=2; i < n; i++){
            if(n % i == 0){
                return false;
            }
        }
    }
    return true;
}

vector<int> factoresPrimos(int n){
	//que dado un entero devuelve un vector con los factores primos del mismo
	vector<int> res;
	int i=2;
	int tope=n;
	if(n==2){
	    res.push_back(2);
	}
	while(i < tope)
	    if(esPrimo(i) && (n % i == 0)){
	        res.push_back(i);
	        n=n/i;
	        i=i;
	    }else{
	        i=i+1;
	    }
    return res;
}

//Ejercicio 7 Bien
void mostrarVector(vector<int> v){
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
	cout<<"[";
	for (int i=0; i < v.size(); i++){
	    if(i != v.size() - 1){
	        cout<< v[i]<<",";
	    }else{
	        cout<< v[i] << "]";
	    }
	}
}

//ej 8 Bien
vector<int> fLeerVector(string nombreArchivo){
    //le cambie el nombre a la funcion porque no se que pasaba como el archivo de texto se llamaba igual
    //Dado un archivo que contiene una secuencia de numeros enteros separados por espacio (por ejemplo: 1 2 34 4 45),
    //leerlo y devolver un vector con los numeros en el mismo orden
    vector<int> res;
    int a;
    ifstream fin;
    fin.open(nombreArchivo);
    while(!fin.eof()){
        fin>>a;
        res.push_back(a);
    }
    fin.close();
    return res;
}

//ej 9 Bien
void guardarVector(vector<int> v, string nombreArchivo){
    //Dado un vector de enteros, grabar sus elementos en un archivo cuyo nombre viene como parametro de entrada. Ejemplo:
    //si el vector es <1, 2, 5, 65> el archivo contiene [1, 2, 5, 65]
    ofstream fout;
    fout.open(nombreArchivo);
    fout<<"["<<" ";
    for(int i=0; i<v.size()-1; i++){
        fout<< v[i]<<",";
    }
    fout<<v[v.size()-1]<<"]";
    fout.close();
}

//ej 10 Bien
int sumaParcial(vector<int> v, int a, int b){
    int res=0;
    for (int i=a; i<= b; i++){
        res= res + v[i];
    }
    return res;
}
int fElementoMedio(vector<int>v){
    //Dado un vector de enteros encontrar el primer elemento de izquierda a derecha tal que los elementos a su izquierda
    //suman mas que los que estan a su derecha. Ejemplo: <1, 2, 3, 4> el resultado es 3 porque (1+2) < 3 + 4 y (1 + 2 +
    //3) > 4. El vector de entrada debe ser leido desde un archivo y el resultado debe ser mostrado por pantalla. Utilizar el
    //archivo elementoMedio.in para probar la funcion.
    for(int i=1; i<v.size();i++ ){
        if(sumaParcial(v,0,i-1)>sumaParcial(v,i+1,v.size()-1)){
            cout<< i;
            return i;
        }

    }
    cout<<"no hubo );";
}

//ej 11 Bien
bool aparece(vector<int> v, int a){
    for (int i=0; i < v.size(); i++){
        if(a==v[i]){
            return true;
        }
    }
    return false;
}
vector<int> numReptidos(vector<int>v){
    //dado un vector me devuelve uno eliminando las repeticiones
    vector<int> res;
    for(int i=0; i < v.size(); i++){
        if(not(aparece(res,v[i]))){
            res.push_back(v[i]);
        }
    }
    return res;
}

int numApariciones(vector<int> v, int a){
    int res=0;
    for (int i=0; i<v.size(); i++){
        if(v[i]==a){
            res=res +1;
        }
    }
    return res;
}

void fCantApariciones(string nombreArchivo, string nombreArchivoOut) {
    //Dado un archivo que contiene una lista de numeros, contar la cantidad de apariciones de cada uno y crear en un archivo
    //en el directorio archivos/out con el mismo nombre del archivo de entrada, de manera de tener una linea por cada
    //numero encontrado, un espacio y su cantidad de apariciones
    vector<int> v = fLeerVector(nombreArchivo);
    vector<int> numeros = numReptidos(v);
    vector<int> apariciones(numeros.size());
    for (int i=0; i < numeros.size(); i++ ){
        apariciones[i]=numApariciones(v,numeros[i]);
    }
    ofstream fout;
    fout.open(nombreArchivoOut); 
    for (int i=0; i < numeros.size(); i++){
        fout<<numeros[i]<<" "<<apariciones[i]<<endl;
    }
    fout.close();

}



//ej 12 no termina el programa 
bool sonIguales(string a, string b){
    bool res=true;
    if(b.length()==a.length()){
        for (int i=0; i < a.length(); i++){
            if(a[i]==b[i]){
                res= true;
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
    return res;
}
int fCantidadAparicionesDePalabra(string nombreArchivo, string palabra) {
    //Ingresar por consola una palabra a buscar y el nombre de un archivo de texto y devolver la cantidad de apariciones de
    //la palabra en el archivo. Mostrar el resultado por pantalla.
    //Para testear el ejercicio pueden usar el archivo cantidadAparicionesDePalabra.in
    int apariciones=0;
    string prueba;
    ifstream fin;
    fin.open(nombreArchivo, ios::in);
    while(!fin.eof()){
        fin>>prueba;
        if(sonIguales(prueba, palabra) == true){
            apariciones = apariciones + 1;
        }
    }
    cout<<apariciones;
    fin.close();
    return 0;

}
//ej 13 bien
void promedio(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut){
    //Dados dos archivos en los que cada uno contiene una secuencia de enteros de la misma longitud, guardar el promedio de
    //cada par de numeros que se encuentran en la misma \posicion" en el archivo de salida. Ejemplo: si tenemos dos secuencias
    //<1, 2, 3, 4> y <1, 25, 3, 12> el resultado debe ser [1, 13.5, 3, 8]. En archivos/ se encuentra promedio1.in y
    //promedio2.in. Cada archivo contiene 100 numeros random entre 1 y 10.
    ofstream fout;
    ifstream fin1;
    ifstream fin2;
    fout.open(nombreArchivoOut);
    fin1.open(nombreArchivoIn1);
    fin2.open(nombreArchivoIn2);
    int a;
    int b;
    while(!fin1.eof()){
        fin1>>a;
        fin2>>b;
        fout<<(a+b)/2<<" ";
    }
    fout.close();
    fin1.close();
    fin2.close();
}

//ej 14 bien
void ordenarSecuencias(string nombreArchivoIn1, string nombreArchivoIn2, string nombreArchivoOut){
    //Dados dos archivos en los que cada uno contiene una secuencia de enteros ordenada, ordenarlos y guardar el resultado
    //en el archivo de salida. Ejemplo: si tenemos dos secuencias <1, 4, 8, 19> y <3, 25, 31> el resultado debe ser [1,
    //3, 4, 8, 25, 31].
    //En archivos/ se encuentra ordenarSecuencia1.in y ordenarSecuencia2.in. Cada archivo contiene 5000 numeros
    //ordenados entre 1 y 1000. El primer archivo contiene los numeros pares en el rango y el segundo los impares.
    ofstream fout;
    ifstream fin1;
    ifstream fin2;
    fout.open(nombreArchivoOut);
    fin1.open(nombreArchivoIn1);
    fin2.open(nombreArchivoIn2);
    int a;
    int b;
    while(!fin1.eof()){
        fin1>>a;
        fin2>>b;
        if(a >= b){
            fout<<b<<" "<<a<<" ";
        }else{
            fout<<a<<" "<<b<<" ";
        }
    }
    fout.close();
    fin1.close();
    fin2.close();


}

//ej 15 hay algo mal
vector<int> interseccion(){
    //Funcion que pide al usuario que se ingrese por teclado dos nombres de archivos que contengan solo numeros enteros,
    //luego calcule la interseccion (los elementos comunes a ambos archivos), que debe mostrar por pantalla, ademas de
    //devolverla como vector.
    string a;
    string b;
    int num1;
    int num2;
    vector<int> res;
    //cout << "Ingresar primer archivo";
    //cin >> a;
    //cout<< "Ingresar segundo archivo";
    //cin >> b;
    ifstream fin1;
    ifstream fin2;
    fin1.open("interseccion1.in");
    fin2.open("interseccion2.in");
    while(!fin1.eof()){
        fin1>>num1;
        while(!fin2.eof()){
            fin2>>num2;
            if(num2 == num1){
                res.push_back(num1);
                cout<<num1;
            }
        }
    }
    fin1.close();
    fin2.close();
    return res;
}



