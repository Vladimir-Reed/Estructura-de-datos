#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Tarea: Orden por columnas de matriz 2D (C++)
 * Cada columna se ordena de forma ascendente de manera independiente.
 */

const int FILAS = 3;
const int COLUMNAS = 3;

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    for (int fila = 0; fila < FILAS; fila++) {
        for (int col = 0; col < COLUMNAS; col++) {
            cout << matriz[fila][col] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {8, 3, 5},
        {1, 9, 2},
        {7, 4, 6}
    };

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);

    for (int col = 0; col < COLUMNAS; col++) {
        int columna[FILAS];
        for (int fila = 0; fila < FILAS; fila++) {
            columna[fila] = matriz[fila][col];
        }
        sort(columna, columna + FILAS);
        for (int fila = 0; fila < FILAS; fila++) {
            matriz[fila][col] = columna[fila];
        }
    }

    cout << "\nMatriz ordenada por columnas:" << endl;
    imprimirMatriz(matriz);

    return 0;
}
