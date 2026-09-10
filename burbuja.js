function bubbleSort(a) {
    let s = a.length;

    for (let i = 0; i < s; i++) {
        let isSwapped = false;

        for (let j = 0; j < s - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                let temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                isSwapped = true;
            }
        }

        if (!isSwapped)
            break;
    }
}

let a = [15, 16, 11, 13, 14];

console.log("Antes de ordenar:");
console.log(a);

bubbleSort(a);

console.log("Después de ordenar:");
console.log(a);