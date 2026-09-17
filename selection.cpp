// Implementación de Selection Sort en C++
#include <iostream>
using namespace std;

// funcion para implementar el algoritmo de selección
void selection(int a[], int n) {
    for (int i = 0; i < n; i++) { // recorre todo el arreglo
        int small = i; // indice del elemento más pequeño
        for (int j = i + 1; j < n; j++) { // encuentra el elemento más pequeño en el arreglo
            if (a[small] > a[j]) { // compara el elemento más pequeño con el siguiente elemento
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
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) { // recorre todo el arreglo
        cout << a[i] << " "; // imprime el elemento
    }
    cout << endl;
}

int main() {
    int a[] = {65, 26, 13, 23, 12}; // arreglo desordenado
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Arreglo antes de ser ordenado: " << endl;
    printArr(a, n);

    selection(a, n);

    cout << "\nArreglo después de ser ordenado: " << endl;
    printArr(a, n);

    return 0;
}
