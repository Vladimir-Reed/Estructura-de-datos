#include <iostream>
using namespace std;

/*
 * Tarea: Recorrido de matriz 2D (C++)
 */

const int FILAS = 3;
const int COLUMNAS = 3;

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {8, 3, 5},
        {1, 9, 2},
        {7, 4, 6}
    };

    cout << "Matriz 2D:" << endl;
    for (int fila = 0; fila < FILAS; fila++) {
        for (int col = 0; col < COLUMNAS; col++) {
            cout << matriz[fila][col] << "\t";
        }
        cout << endl;
    }

    return 0;
}
