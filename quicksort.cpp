// Implementación de QuickSort en C++
#include <iostream>
using namespace std;

// Intercambia los elementos en las posiciones i y j
void swapVal(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Función para hacer la partición del arreglo
int partition(int a[], int l, int h) {
    // Selecciona el elemento pivote
    int pvt = a[h];
    // j es el índice de los elementos que son menores que
    // pivot y también indica la posición correcta del pivote encontrado hasta este momento
    int j = l - 1;
    // Recorre a[l..h-1] y mueve todos los elementos menores
    // al lado izquierdo del pivote.
    // Los elementos de l a j son más pequeños después de cada iteración
    for (int k = l; k < h; k++) { // recorre el arreglo
        // Si el elemento actual es menor que el pivote
        if (a[k] < pvt) { // compara el elemento actual con el pivote
            j++; // incrementa el indice del elemento más pequeño
            swapVal(a, j, k); // intercambia los elementos
        }
    }
    // Mover el pivote después de elementos más pequeños y
    // devolverlo a su posición
    swapVal(a, j + 1, h); // intercambia el pivote con el elemento siguiente al último elemento más pequeño
    return j + 1; // devuelve el indice del pivote
}

// Función principal recursiva de QuickSort
void quicksort(int a[], int l, int h) {
    if (l < h) {
        // p es el índice de partición, a[p] ya está en su posición correcta
        int p = partition(a, l, h);
        // Ordena los elementos antes y después de la partición
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, h);
    }
}

// Función para imprimir el array
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

    quicksort(a, 0, n - 1);

    cout << "\nArreglo después de ser ordenado: " << endl;
    printArr(a, n);

    return 0;
}
