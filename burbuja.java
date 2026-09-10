public class Main {

    static void bubbleSort(int[] a) {
        int s = a.length;

        for (int i = 0; i < s; i++) {
            boolean isSwapped = false;

            for (int j = 0; j < s - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;

                    isSwapped = true;
                }
            }

            if (!isSwapped)
                break;
        }
    }

    public static void main(String[] args) {
        int[] a = {15, 16, 11, 13, 14};

        System.out.println("Antes de ordenar:");
        for (int x : a)
            System.out.print(x + " ");

        bubbleSort(a);

        System.out.println("\nDespués de ordenar:");
        for (int x : a)
            System.out.print(x + " ");
    }
}