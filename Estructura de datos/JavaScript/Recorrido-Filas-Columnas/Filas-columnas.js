// Matriz
let matriz = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

// Recorrido por filas
console.log("Recorrido por filas:");

for (let fila = 0; fila < 3; fila++) {
    for (let columna = 0; columna < 3; columna++) {
        process.stdout.write(matriz[fila][columna] + " ");
    }
    console.log();
}

// Recorrido por columnas
console.log("\nRecorrido por columnas:");

for (let columna = 0; columna < 3; columna++) {
    for (let fila = 0; fila < 3; fila++) {
        process.stdout.write(matriz[fila][columna] + " ");
    }
    console.log();
}