```cpp
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int tablero[8][8];
int jugador = -1;

// 0 = vacio
// 1 = roja
// -1 = blanca
// 2 = dama roja
// -2 = dama blanca

void iniciarTablero()
{
    for (int f = 0; f < 8; f++)
        for (int c = 0; c < 8; c++)
            tablero[f][c] = 0;

    // Fichas rojas
    for (int f = 0; f < 3; f++)
        for (int c = 0; c < 8; c++)
            if ((f + c) % 2 == 1)
                tablero[f][c] = 1;

    // Fichas blancas
    for (int f = 5; f < 8; f++)
        for (int c = 0; c < 8; c++)
            if ((f + c) % 2 == 1)
                tablero[f][c] = -1;
}

void mostrarTablero(int cursorF, int cursorC)
{
    system("cls");

    cout << "\n       DAMAS INGLESAS\n\n";
    cout << "     1 2 3 4 5 6 7 8\n";

    for (int f = 0; f < 8; f++)
    {
        cout << "  " << f + 1 << "  ";

        for (int c = 0; c < 8; c++)
        {
            if (f == cursorF && c == cursorC)
                cout << "[";

            if (tablero[f][c] == 0)
                cout << ".";
            else if (tablero[f][c] == 1)
                cout << "R";
            else if (tablero[f][c] == -1)
                cout << "B";
            else if (tablero[f][c] == 2)
                cout << "D";
            else
                cout << "d";

            if (f == cursorF && c == cursorC)
                cout << "]";
            else
                cout << " ";
        }

        cout << endl;
    }

    cout << "\nR = Roja   B = Blanca";
    cout << "\nD/d = Dama";
    cout << "\nTurno: " << (jugador == -1 ? "BLANCAS" : "ROJAS");
    cout << "\nFlechas = mover   ENTER = seleccionar";
    cout << "\nESC = salir\n";
}

bool esPropia(int ficha)
{
    if (jugador == -1)
        return ficha == -1 || ficha == -2;

    return ficha == 1 || ficha == 2;
}

bool esEnemiga(int ficha)
{
    if (jugador == -1)
        return ficha == 1 || ficha == 2;

    return ficha == -1 || ficha == -2;
}

bool moverFicha(int fi, int ci, int ff, int cf)
{
    int ficha = tablero[fi][ci];

    if (tablero[ff][cf] != 0)
        return false;

    int df = ff - fi;
    int dc = cf - ci;

    bool dama = (ficha == 2 || ficha == -2);

    // Movimiento normal
    if (abs(df) == 1 && abs(dc) == 1)
    {
        if (!dama)
        {
            if (ficha == -1 && df != -1)
                return false;

            if (ficha == 1 && df != 1)
                return false;
        }

        tablero[ff][cf] = ficha;
        tablero[fi][ci] = 0;
        return true;
    }

    // Captura
    if (abs(df) == 2 && abs(dc) == 2)
    {
        int medioF = (fi + ff) / 2;
        int medioC = (ci + cf) / 2;

        if (!esEnemiga(tablero[medioF][medioC]))
            return false;

        if (!dama)
        {
            if (ficha == -1 && df != -2)
                return false;

            if (ficha == 1 && df != 2)
                return false;
        }

        tabl
```
