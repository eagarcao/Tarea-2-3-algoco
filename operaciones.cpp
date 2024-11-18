#include "operaciones.h"
#include <iostream>
#include <array>
#include <fstream>
using namespace std;

array< array<char, 26>, 26 > matriz_sub;
array< array<char, 26>, 26 > matriz_trans;
array<char, 26> tabla_ins;
array<char, 26>tabla_del;
const int BASE_ASCII = 97;



array< array<char, 26>, 26 > leer_matriz_costo(string nombre_archivo){
    ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
    }

    array< array<char, 26>, 26 > matriz_costo;
    int costo;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            archivo >> costo;
            matriz_costo[i][j] = costo;
        }
    }
    archivo.close();
    return matriz_costo;
}

array<char, 26> leer_tabla_costo(string nombre_archivo){
    ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
    }

    array<char, 26> tabla_costo;
    int costo;
    for(int i = 0; i < 26; i++){
        archivo >> costo;
        tabla_costo[i] = costo;
    }
    archivo.close();
    return tabla_costo;
}

void init(){
    string base = "Costos/";
    matriz_sub = leer_matriz_costo(base + "cost_replace.txt");
    matriz_trans = leer_matriz_costo(base + "cost_transpose.txt");
    tabla_del = leer_tabla_costo(base + "cost_delete.txt");
    tabla_ins = leer_tabla_costo(base + "cost_insert.txt");
}

int costo_sub(char a, char b){
    int costo;
    // Implementacion
    int posA = a - BASE_ASCII;
    int posB = b - BASE_ASCII;
    costo = matriz_sub[posA][posB];

    return costo;
}

int costo_ins(char b){
    int costo;
    // Implementacion
    int posB = b - BASE_ASCII;
    costo = tabla_ins[posB];

    return costo;
}

int costo_del(char a){
    int costo;
    // Implementacion
    int posA = a - BASE_ASCII;
    costo = tabla_ins[posA];

    return costo;
}

int costo_trans(char a, char b){
    int costo;
    // Implementacion
    int posA = a - BASE_ASCII;
    int posB = b - BASE_ASCII;
    costo = matriz_trans[posA][posB];
    
    return costo;
}