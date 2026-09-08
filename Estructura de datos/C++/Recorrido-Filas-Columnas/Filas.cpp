#include <iostream>
using namespace std;

int main()
{
    int matriz[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Recorrido por filas
    cout << "Recorrido por filas:" << endl;

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            cout << matriz[fila][columna] << " ";
        }
        cout << endl;
    }

    // Recorrido por columnas
    cout << "\nRecorrido por columnas:" << endl;

    for (int columna = 0; columna < 3; columna++)
    {
        for (int fila = 0; fila < 3; fila++)
        {
            cout << matriz[fila][columna] << " ";
        }
        cout << endl;
    }

    return 0;
}