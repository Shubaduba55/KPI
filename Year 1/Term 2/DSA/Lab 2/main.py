import random
from merge_sort import merge_sort
from create_array import create_array


"""def create_array1(u, n):
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
    return arr"""


if __name__ == '__main__':
    arr_main = create_array("ip11_shamkov_02_input.txt")
    print(*arr_main, sep="\n")
