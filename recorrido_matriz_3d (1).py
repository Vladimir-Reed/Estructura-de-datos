"""
Tarea: Recorrido de matriz 3D (Python)
Ejecutar con: python recorrido_matriz_3d.py
"""

matriz = [
    [
        [1, 2],
        [3, 4]
    ],
    [
        [5, 6],
        [7, 8]
    ]
]

for indice_capa, capa in enumerate(matriz):
    print(f"Capa {indice_capa}:")
    for fila in capa:
        print("\t".join(str(valor) for valor in fila))
