import random
from bubble_sort import bubble_sort
from comb_sort import comb_sort
from Insertion_sort import insertion_sort
from max_f import sort_max


def create_array(length: int, var: int):
    array = []
    if var == 0:
        for i in range(length):
            array.append(i+1)
        random.shuffle(array)
    elif var == 1:
        for i in range(length):
            array.append(i+1)
    elif var == -1:
        for i in range(length):
            array.append(length - i)

    return array


def write_sort(array: list, n: int, func, name: str, case: str):
    arr = array[::1]
    print(case+" "+name+"(", n, "): ")
    print("\tMixed:[", *arr, "]") if n <= 50 else ""
    swap, comparisons = func(arr, n)
    print("\tSorted:[", *arr, "]") if n <= 50 else ""
    print("\tSwap" + case + name + " =", swap, "\n\t" + "Comparisons" + case + name + " =", comparisons, "\n")


if __name__ == '__main__':
    # n = int(input("Enter size of array: "))
    dictionary = {1: "Best", -1: "Worst", 0: "Random"}
    number = [10, 100, 1000, 5000, 10000, 20000, 50000]
    for var, case in dictionary.items():
        for n in number:
            A = create_array(n, var)
            # write_sort(A, n, bubble_sort, "Bubble", case)
            write_sort(A, n, comb_sort, "Comb", case)
            # write_sort(A, n, insertion_sort, "Insertion", case)
            # write_sort(A, n, sort_max, "Max", case)
