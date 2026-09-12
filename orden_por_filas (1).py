"""
Tarea: Orden por filas de matriz 2D (Python)
Cada fila se ordena de forma ascendente de manera independiente.
Ejecutar con: python orden_por_filas.py
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

for fila in matriz:
    fila.sort()

print("\nMatriz ordenada por filas:")
imprimir_matriz(matriz)
