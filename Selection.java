// Implementación de Selection Sort en Java
public class Selection {

    // funcion para implementar el algoritmo de selección
    static void selection(int[] a) {
        for (int i = 0; i < a.length; i++) { // recorre todo el arreglo
            int small = i; // indice del elemento más pequeño
            for (int j = i + 1; j < a.length; j++) { // encuentra el elemento más pequeño en el arreglo
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
    static void printArr(int[] a) {
        for (int i = 0; i < a.length; i++) { // recorre todo el arreglo
            System.out.print(a[i] + " "); // imprime el elemento
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] a = {65, 26, 13, 23, 12}; // arreglo desordenado

        System.out.println("Arreglo antes de ser ordenado: ");
        printArr(a);

        selection(a);

        System.out.println("\nArreglo después de ser ordenado: ");
        printArr(a);
    }
}
