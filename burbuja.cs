using System;

class burbuja
{
    static void BubbleSort(int[] a)
    {
        int s = a.Length;

        for (int i = 0; i < s; i++)
        {
            bool isSwapped = false;

            for (int j = 0; j < s - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
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

    static void Main()
    {
        int[] a = { 15, 16, 11, 13, 14 };

        Console.WriteLine("Antes de ordenar:");
        foreach (int x in a)
            Console.Write(x + " ");

        BubbleSort(a);

        Console.WriteLine("\nDespués de ordenar:");
        foreach (int x in a)
            Console.Write(x + " ");
            
    }
}