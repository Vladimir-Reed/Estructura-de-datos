// Implementación de QuickSort en JavaScript

// Intercambia los elementos en las posiciones i y j
function swap(a, i, j) {
  const temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

// Función para hacer la partición del arreglo
function partition(a, l, h) {
  // Selecciona el elemento pivote
  const pvt = a[h];
  // j es el índice de los elementos que son menores que
  // pivot y también indica la posición correcta del pivote encontrado hasta este momento
  let j = l - 1;
  // Recorre a[l..h-1] y mueve todos los elementos menores
  // al lado izquierdo del pivote.
  // Los elementos de l a j son más pequeños después de cada iteración
  for (let k = l; k < h; k++) { // recorre el arreglo
    // Si el elemento actual es menor que el pivote
    if (a[k] < pvt) { // compara el elemento actual con el pivote
      j++; // incrementa el indice del elemento más pequeño
      swap(a, j, k); // intercambia los elementos
    }
  }
  // Mover el pivote después de elementos más pequeños y
  // devolverlo a su posición
  swap(a, j + 1, h); // intercambia el pivote con el elemento siguiente al último elemento más pequeño
  return j + 1; // devuelve el indice del pivote
}

// Función principal recursiva de QuickSort
function quicksort(a, l, h) {
  if (l < h) {
    // p es el índice de partición, a[p] ya está en su posición correcta
    const p = partition(a, l, h);
    // Ordena los elementos antes y después de la partición
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, h);
  }
}

// Función para imprimir el array
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

quicksort(a, 0, a.length - 1);

console.log("\nArreglo después de ser ordenado: ");
printArr(a);
