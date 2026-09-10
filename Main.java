package Java.Insertion Sort;

public public class Main {
    static void insertionSort(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int temp = a[i];
            int j = i - 1;
            while (j >= 0 && temp < a[j]) {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = temp;
        }
    }

    static void printArr(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] a = {70, 15, 2, 51, 60};
        System.out.println("Antes de ordenar los elementos del arreglo: ");
        printArr(a);
        insertionSort(a);
        System.out.println("\nDespués de arreglos los elementos del arreglo: ");
        printArr(a);
    }
} {
    
}
