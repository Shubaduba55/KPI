def bubble_sort(array: list, n: int):
    swap = 0
    comparisons = 0
    for j in range(n):
        for i in range(n - 1 - j):
            comparisons += 1
            if array[i] > array[i + 1]:
                array[i+1], array[i] = array[i], array[i+1]
                swap += 1
    return swap, comparisons
