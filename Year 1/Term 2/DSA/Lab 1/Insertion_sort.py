def insertion_sort(array: list, n: int):
    swap = 0
    comparisons = 0
    i = 1
    while i < n:
        j = i
        while j > 0 and array[j-1] > array[j]:
            array[j-1], array[j] = array[j], array[j-1]
            swap += 1
            comparisons += 1
            j -= 1
        i += 1

    return swap, comparisons
