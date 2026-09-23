
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

        tablero[ff][cf] = ficha;
        tablero[fi][ci] = 0;
        tablero[medioF][medioC] = 0;

        return true;
    }

    return false;
}

void coronar()
{
    for (int c = 0; c < 8; c++)
    {
        if (tablero[0][c] == -1)
            tablero[0][c] = -2;

        if (tablero[7][c] == 1)
            tablero[7][c] = 2;
    }
}

bool quedanFichas(int color)
{
    for (int f = 0; f < 8; f++)
        for (int c = 0; c < 8; c++)
            if (color == -1)
            {
                if (tablero[f][c] == -1 || tablero[f][c] == -2)
                    return true;
            }
            else
            {
                if (tablero[f][c] == 1 || tablero[f][c] == 2)
                    return true;
            }

    return false;
}

int main()
{
    int f = 5;
    int c = 0;

    iniciarTablero();

    while (true)
    {
        mostrarTablero(f, c);

        int tecla = _getch();

        if (tecla == 27)
            break;

        if (tecla == 224)
        {
            tecla = _getch();

            if (tecla == 72 && f > 0)
                f--;

            if (tecla == 80 && f < 7)
                f++;

            if (tecla == 75 && c > 0)
                c--;

            if (tecla == 77 && c < 7)
                c++;
        }
        else if (tecla == 13)
        {
            if (!esPropia(tablero[f][c]))
                continue;

            int origenF = f;
            int origenC = c;

            while (true)
            {
                mostrarTablero(f, c);

                cout << "\nFicha seleccionada.";
                cout << "\nMueve las flechas y presiona ENTER.";

                int t = _getch();

                if (t == 27)
                    return 0;

                if (t == 224)
                {
                    t = _getch();

                    if (t == 72 && f > 0) f--;
                    if (t == 80 && f < 7) f++;
                    if (t == 75 && c > 0) c--;
                    if (t == 77 && c < 7) c++;
                }
                else if (t == 13)
                {
                    if (moverFicha(origenF, origenC, f, c))
                    {
                        coronar();

                        if (!quedanFichas(-jugador))
                        {
                            mostrarTablero(f, c);
                            cout << "\n\nGANARON "
                                 << (jugador == -1 ? "LAS BLANCAS" : "LAS ROJAS")
                                 << "!\n";
                            system("pause");
                            return 0;
                        }

                        jugador *= -1;
                        break;
                    }
                    else
                    {
                        cout << "\nMovimiento no valido.";
                        Sleep(800);
                    }
                }
            }
        }
    }

    return 0;
}
```

---

# 🔵 Versión 2 — Con historial

Esta es una evolución de la primera. Agrega:

* Historial de movimientos.
* Contador de movimientos.
* Guardado del historial en `historial.txt`.
* Tablero.
* Flechas.
* ENTER.
* Capturas.
* Damas.
* Turnos.

Guárdalo como **`ProyectoDamasV2.cpp`**.

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

int tablero[8][8];
int jugador = -1;
vector<string> historial;

void iniciarTablero()
{
    for (int f = 0; f < 8; f++)
        for (int c = 0; c < 8; c++)
            tablero[f][c] = 0;

    for (int f = 0; f < 3; f++)
        for (int c = 0; c < 8; c++)
            if ((f + c) % 2 == 1)
                tablero[f][c] = 1;

    for (int f = 5; f < 8; f++)
        for (int c = 0; c < 8; c++)
            if ((f + c) % 2 == 1)
                tablero[f][c] = -1;
}

void mostrarTablero(int fCursor, int cCursor)
{
    system("cls");

    cout << "\n========== DAMAS INGLESAS ==========\n\n";
    cout << "       1   2   3   4   5   6   7   8\n";

    for (int f = 0; f < 8; f++)
    {
        cout << "   " << f + 1 << "  ";

        for (int c = 0; c < 8; c++)
        {
            char pieza = '.';

            if (tablero[f][c] == 1)
                pieza = 'R';

            if (tablero[f][c] == -1)
                pieza = 'B';

            if (tablero[f][c] == 2)
                pieza = 'D';

            if (tablero[f][c] == -2)
                pieza = 'd';

            if (f == fCursor && c == cCursor)
                cout << "[" << pieza << "] ";
            else
                cout << " " << pieza << "  ";
        }

        cout << endl;
    }

    cout << "\nTurno: "
         << (jugador == -1 ? "BLANCAS" : "ROJAS") << endl;

    cout << "Movimientos realizados: "
         << historial.size() << endl;

    cout << "\nFlechas = mover";
    cout << "\nENTER = seleccionar";
    cout << "\nESC = salir\n";
}

bool propia(int ficha)
{
    if (jugador == -1)
        return ficha == -1 || ficha == -2;

    return ficha == 1 || ficha == 2;
}

bool enemiga(int ficha)
{
    if (jugador == -1)
        return ficha == 1 || ficha == 2;

    return ficha == -1 || ficha == -2;
}

bool mover(int fi, int ci, int ff, int cf)
{
    int ficha = tablero[fi][ci];

    if (tablero[ff][cf] != 0)
        return false;

    int df = ff - fi;
    int dc = cf - ci;

    bool dama = ficha == 2 || ficha == -2;

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
        int mf = (fi + ff) / 2;
        int mc = (ci + cf) / 2;

        if (!enemiga(tablero[mf][mc]))
            return false;

        if (!dama)
        {
            if (ficha == -1 && df != -2)
                return false;

            if (ficha == 1 && df != 2)
                return false;
        }

        tablero[ff][cf] = ficha;
        tablero[fi][ci] = 0;
        tablero[mf][mc] = 0;

        return true;
    }

    return false;
}

void coronar()
{
    for (int c = 0; c < 8; c++)
    {
        if (tablero[0][c] == -1)
            tablero[0][c] = -2;

        if (tablero[7][c] == 1)
            tablero[7][c] = 2;
    }
}

bool tieneFichas(int color)
{
    for (int f = 0; f < 8; f++)
        for (int c = 0; c < 8; c++)
        {
            if (color == -1 &&
                (tablero[f][c] == -1 || tablero[f][c] == -2))
                return true;

            if (color == 1 &&
                (tablero[f][c] == 1 || tablero[f][c] == 2))
                return true;
        }

    return false;
}

void guardarHistorial()
{
    ofstream archivo("historial.txt", ios::app);

    if (!archivo)
        return;

    archivo << "\n============================\n";
    archivo << "NUEVA PARTIDA\n";

    for (int i = 0; i < historial.size(); i++)
        archivo << i + 1 << ". " << historial[i] << endl;

    archivo << "============================\n";

    archivo.close();
}

void verHistorial()
{
    system("cls");

    ifstream archivo("historial.txt");

    cout << "\n========== HISTORIAL ==========\n\n";

    if (!archivo)
    {
        cout << "No hay partidas guardadas.\n";
    }
    else
    {
        string linea;

        while (getline(archivo, linea))
            cout << linea << endl;

        archivo.close();
    }

    cout << "\nPresiona una tecla para regresar...";
    _getch();
}

int main()
{
    iniciarTablero();

    int f = 5;
    int c = 0;

    while (true)
    {
        mostrarTablero(f, c);

        int tecla = _getch();

        if (tecla == 27)
        {
            guardarHistorial();
            break;
        }

        if (tecla == 224)
        {
            tecla = _getch();

            if (tecla == 72 && f > 0) f--;
            if (tecla == 80 && f < 7) f++;
            if (tecla == 75 && c > 0) c--;
            if (tecla == 77 && c < 7) c++;
        }

        else if (tecla == 13)
        {
            if (!propia(tablero[f][c]))
                continue;

            int origenF = f;
            int origenC = c;

            while (true)
            {
                mostrarTablero(f, c);

                cout << "\nFicha seleccionada.";
                cout << "\nENTER para intentar mover.";

                int t = _getch();

                if (t == 27)
                {
                    guardarHistorial();
                    return 0;
                }

                if (t == 224)
                {
                    t = _getch();

                    if (t == 72 && f > 0) f--;
                    if (t == 80 && f < 7) f++;
                    if (t == 75 && c > 0) c--;
                    if (t == 77 && c < 7) c++;
                }

                else if (t == 13)
                {
                    if (mover(origenF, origenC, f, c))
                    {
                        string movimiento =
                            string(jugador == -1 ? "Blancas: " : "Rojas: ");

                        movimiento +=
                            "(" + to_string(origenF + 1) + "," +
                            to_string(origenC + 1) + ") -> (" +
                            to_string(f + 1) + "," +
                            to_string(c + 1) + ")";

                        historial.push_back(movimiento);

                        coronar();

                        if (!tieneFichas(-jugador))
                        {
                            mostrarTablero(f, c);

                            cout << "\nGANARON "
                                 << (jugador == -1
                                         ? "LAS BLANCAS"
                                         : "LAS ROJAS")
                                 << "!\n";

                            guardarHistorial();

                            system("pause");
                            return 0;
                        }

                        jugador *= -1;
                        break;
                    }
                    else
                    {
                        cout << "\nMovimiento no valido.";
                        Sleep(700);
                    }
                }
            }
        }

        // Tecla H para consultar historial
        if (GetAsyncKeyState('H') & 0x8000)
        {
            verHistorial();
        }
    }

    return 0;
}
