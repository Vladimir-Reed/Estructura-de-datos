"""
Tarea: Orden por columnas de matriz 2D (Python)
Cada columna se ordena de forma ascendente de manera independiente.
Ejecutar con: python orden_por_columnas.py
"""


def imprimir_matriz(matriz):
    for fila in matriz:
        print("\t".join(str(valor) for valor in fila))


matriz = [
    [8, 3, 5],
    [1, 9, 2],
    [7, 4, 6]
]

print("Matriz original:")
imprimir_matriz(matriz)

filas = len(matriz)
columnas = len(matriz[0])

for col in range(columnas):
    columna = [matriz[fila][col] for fila in range(filas)]
    columna.sort()
    for fila in range(filas):
        matriz[fila][col] = columna[fila]

print("\nMatriz ordenada por columnas:")
imprimir_matriz(matriz)
