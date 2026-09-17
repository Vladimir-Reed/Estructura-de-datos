# Implementación de QuickSort en Python

def swap(a, i, j):
    # Intercambia los elementos en las posiciones i y j
    a[i], a[j] = a[j], a[i]

# Función para hacer la partición del arreglo
def partition(a, l, h):
    # Selecciona el elemento pivote
    pvt = a[h]
    # j es el índice de los elementos que son menores que
    # pivot y también indica la posición correcta del pivote encontrado hasta este momento
    j = l - 1
    # Recorre a[l..h-1] y mueve todos los elementos menores
    # al lado izquierdo del pivote.
    # Los elementos de l a j son más pequeños después de cada iteración
    for k in range(l, h):  # recorre el arreglo
        # Si el elemento actual es menor que el pivote
        if a[k] < pvt:  # compara el elemento actual con el pivote
            j += 1  # incrementa el indice del elemento más pequeño
            swap(a, j, k)  # intercambia los elementos
    # Mover el pivote después de elementos más pequeños y
    # devolverlo a su posición
    swap(a, j + 1, h)  # intercambia el pivote con el elemento siguiente al último elemento más pequeño
    return j + 1  # devuelve el indice del pivote


def quicksort(a, l, h):
    # Función principal recursiva de QuickSort
    if l < h:
        # p es el índice de partición, a[p] ya está en su posición correcta
        p = partition(a, l, h)
        # Ordena los elementos antes y después de la partición
        quicksort(a, l, p - 1)
        quicksort(a, p + 1, h)


def printArr(a):
    # Función para imprimir el array
    for i in range(len(a)):  # recorre todo el arreglo
        print(a[i], end=" ")  # imprime el elemento
    print()


if __name__ == "__main__":
    a = [65, 26, 13, 23, 12]  # arreglo desordenado
    print("Arreglo antes de ser ordenado: ")
    printArr(a)
    quicksort(a, 0, len(a) - 1)
    print("\nArreglo después de ser ordenado: ")
    printArr(a)
