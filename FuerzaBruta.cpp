#include "operaciones.h"
#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

int calcular_costo_minimo(string s1, string s2, int i, int j){
    if(i == 0 && j == 0) {
        return 0;
    }
    if(i == 0){
        return calcular_costo_minimo(s1, s2, i, j - 1) + costo_ins(s2[j - 1]);
    }
    if(j == 0){
        return calcular_costo_minimo(s1, s2, i - 1, j) + costo_del(s1[i - 1]);
    }

    if(s1[i - 1] == s2[j - 1]){
        return calcular_costo_minimo(s1, s2, i - 1, j - 1);
    }
    int ins_cost = calcular_costo_minimo(s1, s2, i, j - 1) + costo_ins(s2[j - 1]);
    int sub_cost = calcular_costo_minimo(s1, s2, i - 1, j - 1) + costo_sub(s1[i - 1], s2[j - 1]);
    int del_cost = calcular_costo_minimo(s1, s2, i - 1, j) + costo_del(s1[i - 1]);

    int costo_minimo = min(ins_cost, min(sub_cost, del_cost));

    if(i > 1 && j > 1 && s1[i-1] == s2[j - 2] && s1[i - 2] == s2[j - 1]){
        costo_minimo = min(costo_minimo, (calcular_costo_minimo(s1, s2, i - 2, j - 2) + costo_trans(s1[i - 1], s1[i - 2])));
    }
    return costo_minimo;
}

int main(){
    string nombrePruebas[2] = {"casosPrueba.txt", "casosPruebaTamanos.txt"};
    string resultados[2] = {"ResultadosBF-P1.csv", "ResultadosBF-P2.csv"};

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

    cout << "Distancia Minima de Edicion (Fuerza Bruta): " << costo << endl;
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
                auto start = chrono::high_resolution_clock::now();
                int costo = calcular_costo_minimo(s1, s2, i, j);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

                cout << "Distancia Minima de Edicion (Fuerza Bruta): " << costo << endl;
                cout << "Tiempo de ejecucion : " << duration.count() << " microsegundos" << endl;
                archResultado << caso+1 << ";" << s1 << ";" << s2 << ";" << duration.count()  << ";" << costo << "\n";
            }
        }
        archResultado.close();
        archPrueba.close();
    }

    

    
    return 0;
}