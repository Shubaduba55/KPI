import random
# from merge_sort import
from create_array import create_array
from merge_sort_2D import merge_sort

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


def inversion_check(arr1):
    count = 0
    for i in range(len(arr1)):
        for j in range(len(arr1)):
            if arr1[i] > arr1[j] and i < j:
                count += 1
                print("(" + str(i+1) + ", " + str(j+1) + ")")

    return count


if __name__ == '__main__':
    """arr_two = [2, 5, 4, 1, 3]  # 6
    arr_one = [4, 5, 3, 2, 1] # 9
    arr_one_sorted2 = [2, 4, 1, 3, 5] # 3"""
    arr_main = create_array("ip11_shamkov_02_input.txt")
    arr1 = [10, 9, 8, 7, 6]
    merge_sort(arr1, 0, 4)
    print(*arr1)
    # print(*arr_main, sep="\n")
