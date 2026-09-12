/*
 * Tarea: Recorrido de matriz 3D (Java)
 */
public class RecorridoMatriz3D {
    public static void main(String[] args) {
        int[][][] matriz = {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            }
        };

        for (int capa = 0; capa < matriz.length; capa++) {
            System.out.println("Capa " + capa + ":");
            for (int fila = 0; fila < matriz[capa].length; fila++) {
                for (int col = 0; col < matriz[capa][fila].length; col++) {
                    System.out.print(matriz[capa][fila][col] + "\t");
                }
                System.out.println();
            }
        }
    }
}
