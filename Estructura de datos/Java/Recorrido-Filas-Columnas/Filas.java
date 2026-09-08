public class Filas
{
    public static void main(String[] args)
    {
        int[][] matriz =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        // Recorrido por filas
        System.out.println("Recorrido por filas:");

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                System.out.print(matriz[fila][columna] + " ");
            }
            System.out.println();
        }

        // Recorrido por columnas
        System.out.println("\nRecorrido por columnas:");

        for (int columna = 0; columna < 3; columna++)
        {
            for (int fila = 0; fila < 3; fila++)
            {
                System.out.print(matriz[fila][columna] + " ");
            }
            System.out.println();
        }
    }
}