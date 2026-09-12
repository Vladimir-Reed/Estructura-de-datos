import java.util.Arrays;

/*
 * Tarea: Orden por filas de matriz 2D (Java)
 * Cada fila se ordena de forma ascendente de manera independiente.
 */
public class OrdenPorFilas {
    public static void main(String[] args) {
        int[][] matriz = {
            {8, 3, 5},
            {1, 9, 2},
            {7, 4, 6}
        };

        System.out.println("Matriz original:");
        imprimirMatriz(matriz);

        for (int fila = 0; fila < matriz.length; fila++) {
            Arrays.sort(matriz[fila]);
        }

        System.out.println("\nMatriz ordenada por filas:");
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
