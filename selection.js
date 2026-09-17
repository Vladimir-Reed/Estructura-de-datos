// Implementación de Selection Sort en JavaScript

// funcion para implementar el algoritmo de selección
function selection(a) {
  for (let i = 0; i < a.length; i++) { // recorre todo el arreglo
    let small = i; // indice del elemento más pequeño
    for (let j = i + 1; j < a.length; j++) { // encuentra el elemento más pequeño en el arreglo
      if (a[small] > a[j]) { // compara el elemento más pequeño con el siguiente elemento
        small = j; // actualiza el indice del elemento más pequeño
      }
    }
    // intercambia el elemento más pequeño con el primer elemento
    const temp = a[i];
    a[i] = a[small];
    a[small] = temp; // intercambia los elementos
  }
}

// funcion para imprimir el array
function printArr(a) {
  let linea = "";
  for (let i = 0; i < a.length; i++) { // recorre todo el arreglo
    linea += a[i] + " "; // imprime el elemento
  }
  console.log(linea);
}

const a = [65, 26, 13, 23, 12]; // arreglo desordenado

console.log("Arreglo antes de ser ordenado: ");
printArr(a);

selection(a);

console.log("\nArreglo después de ser ordenado: ");
printArr(a);
