# Matriz
TwoDimensionalArray = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

# Recorrido por filas
print("Recorrido por filas:")

for fila in TwoDimensionalArray:
    for elemento in fila:
        print(elemento, end=" ")
    print()

# Recorrido por columnas
print("\nRecorrido por columnas:")

for columna in range(3):
    for fila in range(3):
        print(TwoDimensionalArray[fila][columna], end=" ")
    print()