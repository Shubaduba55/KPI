import random
from merge_sort import merge_sort


def create_array(u, n):
    arr = []
    for i in range(u):
        arr_temp = []
        for j in range(n):
            arr_temp.append(j+1)
        random.shuffle(arr_temp)
        arr.append(arr_temp)
    return arr


def create_array2(n):
    arr = []
    for i in range(n):
        arr.append(i+1)
    random.shuffle(arr)
    return arr


if __name__ == '__main__':
    arr_main = create_array2(25)
    print(*arr_main)
    arr1 = merge_sort(arr_main)
    print(*arr1)
