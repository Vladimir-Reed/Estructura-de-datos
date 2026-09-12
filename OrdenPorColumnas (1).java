import java.util.Arrays;

/*
 * Tarea: Orden por columnas de matriz 2D (Java)
 * Cada columna se ordena de forma ascendente de manera independiente.
 */
public class OrdenPorColumnas {
    public static void main(String[] args) {
        int[][] matriz = {
            {8, 3, 5},
            {1, 9, 2},
            {7, 4, 6}
        };

        System.out.println("Matriz original:");
        imprimirMatriz(matriz);

        int filas = matriz.length;
        int columnas = matriz[0].length;

        for (int col = 0; col < columnas; col++) {
            int[] columna = new int[filas];
            for (int fila = 0; fila < filas; fila++) {
                columna[fila] = matriz[fila][col];
            }
            Arrays.sort(columna);
            for (int fila = 0; fila < filas; fila++) {
                matriz[fila][col] = columna[fila];
            }
        }

        System.out.println("\nMatriz ordenada por columnas:");
        imprimirMatriz(matriz);
    }

    public static void imprimirMatriz(int[][] matriz) {
        for (int fila = 0; fila < matriz.length; fila++) {
            for (int col = 0; col < matriz[fila].length; col++) {
                System.out.print(matriz[fila][col] + "\t");
            }
            System.out.println();
        }
    }
}
