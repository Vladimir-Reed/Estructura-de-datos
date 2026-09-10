def bubbleSort(a):
    s = len(a)

    for i in range(s):
        isSwapped = False

        for j in range(0, s - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                isSwapped = True

        if isSwapped == False:
            break


a = [15, 16, 11, 13, 14]

print("Antes de ordenar:")
for x in a:
    print(x, end=" ")

bubbleSort(a)

print("\nDespués de ordenar:")
for x in a:
    print(x, end=" ")