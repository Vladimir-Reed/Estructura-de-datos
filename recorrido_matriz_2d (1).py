"""
Tarea: Recorrido de matriz 2D (Python)
Ejecutar con: python recorrido_matriz_2d.py
"""

matriz = [
    [8, 3, 5],
    [1, 9, 2],
    [7, 4, 6]
]

print("Matriz 2D:")
for fila in matriz:
    print("\t".join(str(valor) for valor in fila))
