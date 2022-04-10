import math


def comb_sort(array: list, n: int):
    swap = 0
    comparisons = 0

    difference = (1 / (1 - math.exp(-1.618033)))
    step = (n / difference)
    step_round = round(step)

    while step_round != 1:
        for i in range(n - step_round):
            comparisons += 1
            if array[i] > array[i + step_round]:
                array[i + step_round], array[i] = array[i], array[i + step_round]
                swap += 1
        step /= difference
        step_round = round(step)
    else:
        flag = True
        while flag:
            flag = False
            for i in range(n - 1):
                comparisons += 1
                if array[i] > array[i + 1]:
                    array[i + 1], array[i] = array[i], array[i + 1]
                    swap += 1
                    flag = True
    return swap, comparisons

