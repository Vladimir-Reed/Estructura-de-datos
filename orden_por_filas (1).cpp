#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Tarea: Orden por filas de matriz 2D (C++)
 * Cada fila se ordena de forma ascendente de manera independiente.
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

    for (int fila = 0; fila < FILAS; fila++) {
        sort(matriz[fila], matriz[fila] + COLUMNAS);
    }

    cout << "\nMatriz ordenada por filas:" << endl;
    imprimirMatriz(matriz);

    return 0;
}
