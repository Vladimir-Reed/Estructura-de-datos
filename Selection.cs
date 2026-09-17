// Implementación de Selection Sort en C#
using System;

class Selection
{
    // funcion para implementar el algoritmo de selección
    static void SelectionSort(int[] a)
    {
        for (int i = 0; i < a.Length; i++) // recorre todo el arreglo
        {
            int small = i; // indice del elemento más pequeño
            for (int j = i + 1; j < a.Length; j++) // encuentra el elemento más pequeño en el arreglo
            {
                if (a[small] > a[j]) // compara el elemento más pequeño con el siguiente elemento
                {
                    small = j; // actualiza el indice del elemento más pequeño
                }
            }
            // intercambia el elemento más pequeño con el primer elemento
            int temp = a[i];
            a[i] = a[small];
            a[small] = temp; // intercambia los elementos
        }
    }

    // funcion para imprimir el array
    static void PrintArr(int[] a)
    {
        for (int i = 0; i < a.Length; i++) // recorre todo el arreglo
        {
            Console.Write(a[i] + " "); // imprime el elemento
        }
        Console.WriteLine();
    }

    static void Main(string[] args)
    {
        int[] a = { 65, 26, 13, 23, 12 }; // arreglo desordenado

        Console.WriteLine("Arreglo antes de ser ordenado: ");
        PrintArr(a);

        SelectionSort(a);

        Console.WriteLine("\nArreglo después de ser ordenado: ");
        PrintArr(a);
    }
}
