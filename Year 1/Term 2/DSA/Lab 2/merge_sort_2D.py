def swap_2d(arr_2d, id_left, id_right ):
    for i in range(len(arr_2d)):
        arr_2d[i][id_left], arr_2d[i][id_right] = arr_2d[i][id_right], arr_2d[i][id_left]


def merge(arr, id_left, id_right):
    """ arr_left = []
    arr_right = []
    for i in range(len(id_left)):
        arr_left.append(arr[id_left[i]])
    for j in range(len(id_right)):
        arr_right.append(arr[id_right[j]])
    # arr_left.append(10 ** 10)
    # arr_right.append(10**10)
    i = j = 0
    k = 0

    id_plus = id_left + id_right
    while i < len(id_left) and j < len(id_right):

        if arr_left[i] <= arr_right[j]:
            arr[id_plus[k]] = arr_left[i]
            swap_2d(arr_2d, id_left[i], id_right[j])
            i += 1
        else:
            arr[id_plus[k]] = arr_right[j]
            swap_2d(arr_2d, id_left[i], id_right[j])
            j += 1
        k += 1
    else:
        if i < len(id_left):
            for id in range(i, len(id_left)):
                arr[id_plus[k]] = arr_left[id]
                swap_2d(arr_2d, id_left[i], id_plus[k])

        elif j < len(id_right):
            for id in range(j, len(id_left)):
                arr[id_plus[k]] = arr_right[id]
                swap_2d(arr_2d, id_plus[k], id_right[j])
        k += 1
    return
    for k in (id_left + id_right):
                if arr_left[i] <= arr_right[j]:
                    arr[k] = arr_left[i]
                    swap_2d(arr_2d, id_left[i], id_right[j])
                    i += 1
                else:
                    arr[k] = arr_right[j]
                    swap_2d(arr_2d, id_left[i], id_right[j])
                    j += 1
    """
    n_left = len(id_left)
    n_right = len(id_right)
    id_plus = id_left + id_right
    const = id_right[0] - id_left[0]

    """for i in range(n_right):
        if arr[id_plus[i]] > arr[id_plus[i+const]]:
            arr[id_plus[i]], arr[id_plus[i + const]] = arr[id_plus[i + const]], arr[id_plus[i]]
    i += 1
    if n_left > n_right:
        while arr[id_plus[i]] > arr[id_plus[i+1]]:
            arr[id_plus[i]], arr[id_plus[i + 1]] = arr[id_plus[i + 1]], arr[id_plus[i]]
            i += 1"""
    arr_left = []
    arr_right = []
    for i in id_left:
        arr_left.append(arr[i])
    for j in id_right:
        arr_right.append(arr[j])
    arr_left.append(10**10)
    arr_right.append(10**10)
    i = j = 0
    for k in id_plus:
        if arr_left[i] <= arr_right[j]:
            arr[k] = arr_left[i]
            i += 1
        else:
            arr[k] = arr_right[j]
            j += 1


    """while i < n_left and j < n_right:
        if arr[id_left[i]] > arr[id_right[j]]:
            arr[id_left[i]], arr[id_right[j]] = arr[id_right[j]], arr[id_left[i]]
            i += 1
            if
        else:
            i += 1"""

    return id_plus


# en = len(arr) - 1
def merge_sort(arr, start, end):
    if start == end:
        return [end]
    middle = (start + end) // 2
    left = merge_sort(arr, start, middle)
    right = merge_sort(arr, middle + 1, end)
    return merge(arr, left, right)


def merge_sort_2d(arr_2d, number):

    merge_sort(arr_2d, arr_2d[number-1], 0, len(arr_2d[number-1])-1)
