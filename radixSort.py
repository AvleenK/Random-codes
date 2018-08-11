#least significant digit radix sort
def radixSort(arr):
    maxLength = len(str(max(arr)))
    length = len(arr)
    res = [0] * length
    d = 1

    for _ in range(maxLength):
        count = [0] * 10

        for i in range(length):
            index = arr[i]//d
            rem = index%10
            count[rem] += 1

        count[0] -= 1
        for i in range(1, 10):
            count[i] += count[i-1]

        i = length-1
        while i >= 0:
            index = arr[i]//d
            rem = index%10
            res[count[rem]] = arr[i]
            count[rem] -= 1
            i -= 1
        
        for i in range(length):
            arr[i] = res[i]

        d *= 10


arr = list(map(int, input("Enter elements: ").split()))

radixSort(arr)

print("Sorted array: " + str(arr))