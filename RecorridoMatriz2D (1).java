/*
 * Tarea: Recorrido de matriz 2D (Java)
 */
public class RecorridoMatriz2D {
    public static void main(String[] args) {
        int[][] matriz = {
            {8, 3, 5},
            {1, 9, 2},
            {7, 4, 6}
        };

        System.out.println("Matriz 2D:");
        for (int fila = 0; fila < matriz.length; fila++) {
            for (int col = 0; col < matriz[fila].length; col++) {
                System.out.print(matriz[fila][col] + "\t");
            }
            System.out.println();
        }
    }
}
