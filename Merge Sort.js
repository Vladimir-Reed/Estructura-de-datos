function merge(a, l, m, r) {

    let n1 = m - l + 1;
    let n2 = r - m;

    let L = [];
    let R = [];

    for (let i = 0; i < n1; i++)
        L[i] = a[l + i];

    for (let j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    let i = 0;
    let j = 0;
    let k = l;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

function mergeSort(a, l, r) {

    if (l < r) {

        let m = Math.floor(l + (r - l) / 2);

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

let a = [39, 28, 44, 11];

console.log("Antes de ordenar:");
console.log(a);

mergeSort(a, 0, a.length - 1);

console.log("Despues de ordenar:");
console.log(a);