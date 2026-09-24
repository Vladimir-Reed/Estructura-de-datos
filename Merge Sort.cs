using System;

class Program
{
    static void Merge(int[] a, int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int[] L = new int[n1];
        int[] R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = a[l + i];

        for (int j = 0; j < n2; j++)
            R[j] = a[m + 1 + j];

        int i1 = 0;
        int j = 0;
        int k = l;

        while (i1 < n1 && j < n2)
        {
            if (L[i1] <= R[j])
            {
                a[k] = L[i1];
                i1++;
            }
            else
            {
                a[k] = R[j];
                j++;
            }

            k++;
        }

        while (i1 < n1)
        {
            a[k] = L[i1];
            i1++;
            k++;
        }

        while (j < n2)
        {
            a[k] = R[j];
            j++;
            k++;
        }
    }

    static void MergeSort(int[] a, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;

            MergeSort(a, l, m);
            MergeSort(a, m + 1, r);

            Merge(a, l, m, r);
        }
    }

    static void Main()
    {
        int[] a = { 39, 28, 44, 11 };

        Console.Write("Antes de ordenar: ");
        foreach (int x in a)
            Console.Write(x + " ");

        MergeSort(a, 0, a.Length - 1);

        Console.Write("\nDespues de ordenar: ");
        foreach (int x in a)
            Console.Write(x + " ");
    }
}