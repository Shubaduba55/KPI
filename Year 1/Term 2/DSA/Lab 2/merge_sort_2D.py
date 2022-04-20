from column import Column


def merge(arr_left, arr_right):
    arr_new = []
    i = j = 0

    while i < len(arr_left) and j < len(arr_right):
        # left_obj = arr_left[i]
        # right_obj = arr_right[j]

        if arr_left[i].get_elem() <= arr_right[j].get_elem():
            arr_new.append(arr_left[i])
            i += 1
        else:
            arr_new.append(arr_right[j])
            j += 1
    else:
        if i < len(arr_left):
            arr_new += arr_left[i:]
        elif j < len(arr_right):
            arr_new += arr_right[j:]
    return arr_new


def merge_sort(arr):
    if len(arr) == 1:
        return arr
    middle = len(arr) // 2
    left = merge_sort(arr[:middle])
    right = merge_sort(arr[middle:])
    return merge(left, right)


