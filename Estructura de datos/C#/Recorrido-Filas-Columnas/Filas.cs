using System;

class Program
{
    static void Main()
    {
        int[,] matriz =
        {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        // Recorrido por filas
        Console.WriteLine("Recorrido por filas:");

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                Console.Write(matriz[fila, columna] + " ");
            }
            Console.WriteLine();
        }

        // Recorrido por columnas
        Console.WriteLine("\nRecorrido por columnas:");

        for (int columna = 0; columna < 3; columna++)
        {
            for (int fila = 0; fila < 3; fila++)
            {
                Console.Write(matriz[fila, columna] + " ");
            }
            Console.WriteLine();
        }
    }
}