def find_max(array, n):
    max = array[0]
    id = 0
    comparisons = 0
    for i in range(1, n):
        comparisons += 1
        if max < array[i]:
            max = array[i]
            id = i
    return id, comparisons


def sort_max(array, n):
    swap = 0
    comparisons = 0
    for i in range(n):
        id, comp = find_max(array, n-i)
        array[n-i-1], array[id] = array[id], array[n-i-1]
        swap += 1
        comparisons += comp
    return swap, comparisons
