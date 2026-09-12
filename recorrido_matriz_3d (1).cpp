#include <iostream>
using namespace std;

/*
 * Tarea: Recorrido de matriz 3D (C++)
 */

const int CAPAS = 2;
const int FILAS = 2;
const int COLUMNAS = 2;

int main() {
    int matriz[CAPAS][FILAS][COLUMNAS] = {
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        }
    };

    for (int capa = 0; capa < CAPAS; capa++) {
        cout << "Capa " << capa << ":" << endl;
        for (int fila = 0; fila < FILAS; fila++) {
            for (int col = 0; col < COLUMNAS; col++) {
                cout << matriz[capa][fila][col] << "\t";
            }
            cout << endl;
        }
    }

    return 0;
}
