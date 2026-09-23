#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

const int TAMANO_TABLERO = 8;

// 0 = vacio
// 1-12 = rojas
// -1 a -12 = blancas
// >100 = Dama roja
// <-100 = Dama blanca

int tablero[8][8];

int turnoActual = 2;

// Configuracion
int tiempoInicial = 5;
int esperaMovimiento = 300;

int colorFondo = 0;
int colorRojo = 12;
int colorBlanco = 15;

// Tiempo
int tiempoRojas;
int tiempoBlancas;

// Historial
vector<string> historial;

HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

// ==========================================================
// COLORES
// ==========================================================

void cambiarColor(int texto)
{
    SetConsoleTextAttribute(
        consola,
        colorFondo * 16 + texto
    );
}

// ==========================================================
// LIMPIAR
// ==========================================================

void limpiar()
{
    system("cls");
}

// ==========================================================
// ESPERA
// ==========================================================

void esperar()
{
    this_thread::sleep_for(
        chrono::milliseconds(esperaMovimiento)
    );
}

// ==========================================================
// REGLAMENTO
// ==========================================================

void reglamento()
{
    limpiar();

    cout << "\n";
    cout << "====================================================\n";
    cout << "                 DAMAS INGLESAS\n";
    cout << "====================================================\n\n";

    cout << "1. El tablero es de 8 x 8.\n";
    cout << "2. Juegan dos jugadores.\n";
    cout << "3. Comienzan las fichas blancas.\n";
    cout << "4. Las fichas normales se mueven diagonalmente\n";
    cout << "   hacia adelante.\n";
    cout << "5. Si existe una captura, es obligatorio capturar.\n";
    cout << "6. Si despues de capturar existe otra captura,\n";
    cout << "   se debe continuar con la misma ficha.\n";
    cout << "7. Al llegar al extremo contrario se corona como Dama.\n";
    cout << "8. La Dama puede moverse hacia adelante y atras.\n";
    cout << "9. Gana quien elimina todas las fichas contrarias.\n";
    cout << "10. Tambien gana quien deja al contrario sin movimientos.\n\n";

    cout << "====================================================\n";

    system("pause");
}

// ==========================================================
// INICIALIZAR TABLERO
// ==========================================================

void inicializarPiezas()
{
    for (int f = 0; f < 8; f++)
    {
        for (int c = 0; c < 8; c++)
        {
            tablero[f][c] = 0;
        }
    }

    int rojas = 1;
    int blancas = 1;

    for (int f = 0; f < 8; f++)
    {
        for (int c = 0; c < 8; c++)
        {
            if ((f + c) % 2 != 0)
            {
                if (f < 3)
                    tablero[f][c] = rojas++;

                else if (f > 4)
                    tablero[f][c] = -blancas++;
            }
        }
    }
}

// ==========================================================
// MOSTRAR TIEMPO
// ==========================================================

void mostrarTiempo(int segundos)
{
    int minutos = segundos / 60;
    int seg = segundos % 60;

    if (minutos < 10)
        cout << "0";

    cout << minutos << ":";

    if (seg < 10)
        cout << "0";

    cout << seg;
}

// ==========================================================
// MOSTRAR TABLERO
// ==========================================================

void imprimirTablero(int cursorF = -1, int cursorC = -1)
{
    limpiar();

    cout << "\n                 DAMAS INGLESAS\n\n";

    cout << " Rojas: ";
    mostrarTiempo(tiempoRojas);

    cout << "                 Blancas: ";
    mostrarTiempo(tiempoBlancas);

    cout << "\n\n";

    cout << "       1   2   3   4   5   6   7   8\n";
    cout << "     +---+---+---+---+---+---+---+---+\n";

    for (int f = 0; f < 8; f++)
    {
        cout << " " << f + 1 << "   |";

        for (int c = 0; c < 8; c++)
        {
            int valor = tablero[f][c];

            if (f == cursorF && c == cursorC)
                cambiarColor(14);
            else if (valor > 0)
                cambiarColor(colorRojo);
            else if (valor < 0)
                cambiarColor(colorBlanco);
            else
                cambiarColor(8);

            if (valor == 0)
            {
                cout << " . ";
            }
            else if (valor > 100)
            {
                cout << "D" << valor - 100 << " ";
            }
            else if (valor < -100)
            {
                cout << "D" << abs(valor + 100) << " ";
            }
            else
            {
                cout << " " << abs(valor) << " ";
            }

            cambiarColor(7);

            cout << "|";
        }

        cout << "\n";
        cout << "     +---+---+---+---+---+---+---+---+\n";
    }

    cout << "\n";

    if (turnoActual == 1)
        cout << "              TURNO: ROJAS\n";
    else
        cout << "             TURNO: BLANCAS\n";

    cout << "\n";
}

// ==========================================================
// PROPIA Y ENEMIGA
// ==========================================================

bool esPropia(int valor)
{
    if (turnoActual == 1)
        return valor > 0;

    return valor < 0;
}

bool esEnemiga(int valor)
{
    if (valor == 0)
        return false;

    return !esPropia(valor);
}

bool esDama(int valor)
{
    return abs(valor) > 100;
}

// ==========================================================
// DIRECCIONES
// ==========================================================

vector<int> obtenerDirecciones(int valor)
{
    vector<int> direcciones;

    if (esDama(valor))
    {
        direcciones.push_back(1);
        direcciones.push_back(-1);
    }
    else
    {
        if (turnoActual == 1)
            direcciones.push_back(1);
        else
            direcciones.push_back(-1);
    }

    return direcciones;
}

// ==========================================================
// COMPROBAR CAPTURA
// ==========================================================

bool puedeComer(int f, int c)
{
    int valor = tablero[f][c];

    if (!esPropia(valor))
        return false;

    vector<int> direcciones =
        obtenerDirecciones(valor);

    for (int df : direcciones)
    {
        for (int dc : {-1, 1})
        {
            int fi = f + df;
            int ci = c + dc;

            int fd = f + df * 2;
            int cd = c + dc * 2;

            if (fi >= 0 && fi < 8 &&
                ci >= 0 && ci < 8 &&
                fd >= 0 && fd < 8 &&
                cd >= 0 && cd < 8)
            {
                if (esEnemiga(tablero[fi][ci]) &&
                    tablero[fd][cd] == 0)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

// ==========================================================
// COMPROBAR CAPTURAS EN TODO EL TABLERO
// ==========================================================

bool hayCapturas()
{
    for (int f = 0; f < 8; f++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (puedeComer(f, c))
                return true;
        }
    }

    return false;
}

// ==========================================================
// CORONACION
// ==========================================================

void coronar(int f, int c)
{
    int valor = tablero[f][c];

    if (valor > 0 &&
        valor <= 12 &&
        f == 7)
    {
        tablero[f][c] = valor + 100;

        cout << "\nLa ficha roja se convirtio en DAMA.\n";
        esperar();
    }

    if (valor < 0 &&
        valor >= -12 &&
        f == 0)
    {
        tablero[f][c] = valor - 100;

        cout << "\nLa ficha blanca se convirtio en DAMA.\n";
        esperar();
    }
}

// ==========================================================
// HISTORIAL
// ==========================================================

void guardarMovimiento(
    int f1,
    int c1,
    int f2,
    int c2,
    bool captura)
{
    string jugador;

    if (turnoActual == 1)
        jugador = "Rojas";
    else
        jugador = "Blancas";

    string movimiento;

    movimiento =
        jugador + ": " +
        char('A' + c1) +
        to_string(f1 + 1) +
        " -> " +
        char('A' + c2) +
        to_string(f2 + 1);

    if (captura)
        movimiento += " [CAPTURA]";

    historial.push_back(movimiento);
}

// ==========================================================
// SELECCIONAR FICHA
// ==========================================================

bool seleccionarFicha(int& f, int& c)
{
    f = 5;
    c = 0;

    while (true)
    {
        imprimirTablero(f, c);

        cout << "\nUsa las flechas para buscar tu ficha.";
        cout << "\nENTER = seleccionar";
        cout << "\nESC = abandonar";

        int tecla = _getch();

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
            if (esPropia(tablero[f][c]))
                return true;

            cout << "\nSelecciona una ficha de tu color.";
            esperar();
        }
        else if (tecla == 27)
        {
            return false;
        }
    }
}

// ==========================================================
// SELECCIONAR DESTINO
// ==========================================================

bool seleccionarDestino(int& f, int& c)
{
    while (true)
    {
        imprimirTablero(f, c);

        cout << "\nFicha seleccionada.";
        cout << "\nUsa las flechas para elegir destino.";
        cout << "\nENTER = mover";
        cout << "\nESC = cancelar";

        int tecla = _getch();

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
            return true;
        }
        else if (tecla == 27)
        {
            return false;
        }
    }
}

// ==========================================================
// MOVER FICHA
// ==========================================================

bool moverFicha(int fo, int co)
{
    int valor = tablero[fo][co];

    bool hayCaptura = hayCapturas();

    if (hayCaptura && !puedeComer(fo, co))
    {
        cout << "\nEsta ficha no puede moverse.";
        cout << "\nDebes seleccionar una ficha que pueda capturar.";

        esperar();

        return false;
    }

    int fd = fo;
    int cd = co;

    if (!seleccionarDestino(fd, cd))
        return false;

    int df = fd - fo;
    int dc = cd - co;

    // ======================================================
    // CAPTURA
    // ======================================================

    if (abs(df) == 2 &&
        abs(dc) == 2)
    {
        int fi = (fo + fd) / 2;
        int ci = (co + cd) / 2;

        if (tablero[fd][cd] != 0)
        {
            cout << "\nLa casilla esta ocupada.";
            esperar();

            return false;
        }

        if (!esEnemiga(tablero[fi][ci]))
        {
            cout << "\nNo puedes capturar esa ficha.";
            esperar();

            return false;
        }

        vector<int> direcciones =
            obtenerDirecciones(valor);

        bool direccionCorrecta = false;

        for (int direccion : direcciones)
        {
            if (df == direccion * 2)
                direccionCorrecta = true;
        }

        if (!direccionCorrecta)
        {
            cout << "\nMovimiento invalido.";
            esperar();

            return false;
        }

        tablero[fd][cd] = valor;
        tablero[fo][co] = 0;
        tablero[fi][ci] = 0;

        guardarMovimiento(
            fo,
            co,
            fd,
            cd,
            true
        );

        coronar(fd, cd);

        esperar();

        // CAPTURA MULTIPLE
        if (puedeComer(fd, cd))
        {
            cout << "\nCAPTURA MULTIPLE.";
            cout << "\nDebes continuar con la misma ficha.";

            esperar();

            return moverFicha(fd, cd);
        }

        return true;
    }

    // ======================================================
    // MOVIMIENTO NORMAL
    // ======================================================

    if (abs(df) == 1 &&
        abs(dc) == 1 &&
        tablero[fd][cd] == 0)
    {
        vector<int> direcciones =
            obtenerDirecciones(valor);

        bool direccionCorrecta = false;

        for (int direccion : direcciones)
        {
            if (df == direccion)
                direccionCorrecta = true;
        }

        if (!direccionCorrecta)
        {
            cout << "\nEsta ficha no puede moverse hacia atras.";
            esperar();

            return false;
        }

        tablero[fd][cd] = valor;
        tablero[fo][co] = 0;

        guardarMovimiento(
            fo,
            co,
            fd,
            cd,
            false
        );

        coronar(fd, cd);

        esperar();

        return true;
    }

    cout << "\nMovimiento no permitido.";
    esperar();

    return false;
}

// ==========================================================
// CONTAR FICHAS
// ==========================================================

int contarFichas(int jugador)
{
    int contador = 0;

    for (int f = 0; f < 8; f++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (jugador == 1 &&
                tablero[f][c] > 0)
            {
                contador++;
            }

            if (jugador == 2 &&
                tablero[f][c] < 0)
            {
                contador++;
            }
        }
    }

    return contador;
}

// ==========================================================
// TIENE MOVIMIENTOS
// ==========================================================

bool tieneMovimientos()
{
    for (int f = 0; f < 8; f++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (!esPropia(tablero[f][c]))
                continue;

            int valor = tablero[f][c];

            vector<int> direcciones =
                obtenerDirecciones(valor);

            for (int df : direcciones)
            {
                for (int dc : {-1, 1})
                {
                    int nf = f + df;
                    int nc = c + dc;

                    if (nf >= 0 && nf < 8 &&
                        nc >= 0 && nc < 8 &&
                        tablero[nf][nc] == 0)
                    {
                        return true;
                    }

                    int cf = f + df * 2;
                    int cc = c + dc * 2;

                    if (cf >= 0 && cf < 8 &&
                        cc >= 0 && cc < 8)
                    {
                        if (tablero[cf][cc] == 0 &&
                            esEnemiga(tablero[f + df][c + dc]))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

// ==========================================================
// GUARDAR PARTIDA
// ==========================================================

void guardarPartida()
{
    ofstream archivo(
        "historial_partidas.txt",
        ios::app
    );

    if (!archivo)
        return;

    archivo << "\n";
    archivo << "====================================\n";
    archivo << "PARTIDA NUEVA\n";
    archivo << "====================================\n";

    for (int i = 0; i < historial.size(); i++)
    {
        archivo << i + 1 << ". "
                << historial[i]
                << "\n";
    }

    archivo << "====================================\n";

    archivo.close();
}

// ==========================================================
// MOSTRAR HISTORIAL
// ==========================================================

void mostrarHistorial()
{
    limpiar();

    cout << "\n====================================\n";
    cout << "          HISTORIAL\n";
    cout << "====================================\n\n";

    ifstream archivo("historial_partidas.txt");

    if (!archivo)
    {
        cout << "No existen partidas guardadas.\n";
    }
    else
    {
        string linea;

        while (getline(archivo, linea))
        {
            cout << linea << "\n";
        }

        archivo.close();
    }

    cout << "\n";

    system("pause");
}

// ==========================================================
// CONFIGURACION
// ==========================================================

void configuracion()
{
    int opcion;

    do
    {
        limpiar();

        cout << "\n====================================\n";
        cout << "          CONFIGURACION\n";
        cout << "====================================\n\n";

        cout << "1. Tiempo de cada jugador\n";
        cout << "2. Espera entre movimientos\n";
        cout << "3. Color del fondo\n";
        cout << "4. Color de fichas rojas\n";
        cout << "5. Color de fichas blancas\n";
        cout << "6. Regresar\n\n";

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nMinutos para cada jugador: ";
            cin >> tiempoInicial;

            tiempoRojas = tiempoInicial * 60;
            tiempoBlancas = tiempoInicial * 60;

            break;

        case 2:
            cout << "\nTiempo en milisegundos: ";
            cin >> esperaMovimiento;

            break;

        case 3:
            cout << "\nColor de fondo (0-7): ";
            cin >> colorFondo;

            if (colorFondo < 0 ||
                colorFondo > 7)
            {
                colorFondo = 0;
            }

            break;

        case 4:
            cout << "\nColor de fichas rojas (1-15): ";
            cin >> colorRojo;

            if (colorRojo < 1 ||
                colorRojo > 15)
            {
                colorRojo = 12;
            }

            break;

        case 5:
            cout << "\nColor de fichas blancas (1-15): ";
            cin >> colorBlanco;

            if (colorBlanco < 1 ||
                colorBlanco > 15)
            {
                colorBlanco = 15;
            }

            break;

        case 6:
            break;

        default:
            cout << "\nOpcion no valida.\n";
            esperar();
        }

    } while (opcion != 6);
}

// ==========================================================
// JUGAR
// ==========================================================

void jugar()
{
    inicializarPiezas();

    historial.clear();

    tiempoRojas = tiempoInicial * 60;
    tiempoBlancas = tiempoInicial * 60;

    turnoActual = 2;

    bool jugando = true;

    while (jugando)
    {
        if (contarFichas(1) == 0)
        {
            imprimirTablero();

            cout << "\nGANAN LAS BLANCAS.\n";

            break;
        }

        if (contarFichas(2) == 0)
        {
            imprimirTablero();

            cout << "\nGANAN LAS ROJAS.\n";

            break;
        }

        if (!tieneMovimientos())
        {
            imprimirTablero();

            cout << "\nNo existen movimientos disponibles.\n";

            if (turnoActual == 1)
                cout << "GANAN LAS BLANCAS.\n";
            else
                cout << "GANAN LAS ROJAS.\n";

            break;
        }

        int fila;
        int columna;

        if (!seleccionarFicha(fila, columna))
        {
            cout << "\nPartida abandonada.\n";
            break;
        }

        if (moverFicha(fila, columna))
        {
            if (turnoActual == 1)
                turnoActual = 2;
            else
                turnoActual = 1;
        }
    }

    guardarPartida();

    cout << "\nLa partida fue guardada.\n";

    system("pause");
}

// ==========================================================
// MAIN
// ==========================================================

int main()
{
    int opcion;

    do
    {
        limpiar();

        cout << "\n====================================\n";
        cout << "          DAMAS INGLESAS\n";
        cout << "====================================\n\n";

        cout << "1. Reglas del juego\n";
        cout << "2. Iniciar partida\n";
        cout << "3. Historial de partidas\n";
        cout << "4. Configuracion\n";
        cout << "5. Salir\n\n";

        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            reglamento();
            break;

        case 2:
            jugar();
            break;

        case 3:
            mostrarHistorial();
            break;

        case 4:
            configuracion();
            break;

        case 5:
            cout << "\nGracias por jugar.\n";
            break;

        default:
            cout << "\nOpcion no valida.\n";
            system("pause");
        }

    } while (opcion != 5);

    return 0;
}