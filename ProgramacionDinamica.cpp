#include "operaciones.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

vector<vector<int> > matriz_costo;


int calcular_costo_minimo(string s1, string s2, int i, int j){
    if(i == 0 && j == 0){
        matriz_costo[0][0] = 0;
        return 0;
    }

    if(matriz_costo[i][j] != -1) {
        return matriz_costo[i][j];
    }

    if(i == 0){
        matriz_costo[i][j] = calcular_costo_minimo(s1, s2, i, j - 1) + costo_ins(s2[j - 1]);
        return matriz_costo[i][j];
    }
    if(j == 0){
        matriz_costo[i][j] = calcular_costo_minimo(s1, s2, i - 1, j) + costo_del(s1[i - 1]);
        return matriz_costo[i][j];
    }
    
    if(s1[i - 1] == s2[j - 1]){
        matriz_costo[i][j] = calcular_costo_minimo(s1, s2, i - 1, j - 1);
    }
    else{
        int ins_cost = calcular_costo_minimo(s1, s2, i, j - 1) + costo_ins(s2[j - 1]);
        int sub_cost = calcular_costo_minimo(s1, s2, i - 1, j - 1) + costo_sub(s1[i - 1], s2[j - 1]);
        int del_cost = calcular_costo_minimo(s1, s2, i - 1, j) + costo_del(s1[i - 1]);

        matriz_costo[i][j] = min(ins_cost, min(sub_cost, del_cost));

        if(i > 1 && j > 1 && s1[i-1] == s2[j - 2] && s1[i - 2] == s2[j-1]){
            int trans_cost = calcular_costo_minimo(s1, s2, i - 2, j - 2) + costo_trans(s1[i - 2], s1[i-1]);
            matriz_costo[i][j] = min(matriz_costo[i][j], trans_cost);
        }
    }
    return matriz_costo[i][j];
}

int main(){
    string nombrePruebas[2] = {"casosPrueba.txt", "casosPruebaTamanos.txt"};
    string resultados[2] = {"ResultadosDP-P1.csv", "ResultadosDP-P2.csv"};

    init();
    string s1, s2;
    int n;

    // Para no ejecutar los casos de prueba debe descomentar las siguientes lineas y comentar el resto.
    /*
    cin << s1 << s2;
    int i = s1.size(), j = s2.size();

    matriz_costo.resize(i+1, vector<int>(j+1, -1));
    auto start = chrono::high_resolution_clock::now();
    int costo = calcular_costo_minimo(s1, s2, i, j);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Distancia Minima de Edicion (Programacion Dinamica): " << matriz_costo[i][j] << endl;
    cout << "Tiempo de ejecucion : " << duration.count() << " microsegundos" << endl;
    */
   
    // Comentar para probar palabra por palabra.
    for(int i = 0; i < 2; i++){
        ofstream archResultado(resultados[i]);
        if (!archResultado.is_open()) {
            cerr << "No se pudo abrir el archivo de Resultados." << endl;
            return 1;
        }

        ifstream archPrueba(nombrePruebas[i]);
        if (!archPrueba.is_open()) {
            cerr << "No se pudo abrir el archivo de Pruebas." << endl;
            return 1;
        }

        archResultado << "Caso;s1;s2;Tiempo (microsegundos);Respuesta\n";

        archPrueba >> n;
        for(int caso = 0; caso < n; caso++){
            archPrueba >> s1 >> s2;
            int i = s1.size(), j = s2.size();
            for(int l = 0; l < 10; l++){
                matriz_costo.resize(i+1, vector<int>(j+1, -1));
                auto start = chrono::high_resolution_clock::now();
                int costo = calcular_costo_minimo(s1, s2, i, j);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

                cout << "Distancia Minima de Edicion (Programacion Dinamica): " << matriz_costo[i][j] << endl;
                cout << "Tiempo de ejecucion : " << duration.count() << " microsegundos" << endl;
                archResultado << caso+1 << ";" << s1 << ";" << s2 << ";" << duration.count() << ";" << matriz_costo[i][j] << "\n";
                matriz_costo.clear();
            }
            
        }
        archResultado.close();
        archPrueba.close();
    }

    

    return 0;
}