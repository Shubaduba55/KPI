import random


def create_array(u, n):
    arr = []
    for i in range(u):
        arr_temp = []
        for j in range(n):
            arr_temp.append(j+1)
        random.shuffle(arr_temp)
        arr.append(arr_temp)
    return arr


def merge_sort(arr, p, q):
    

def merge(arr, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    arr_left = []
    arr_right = []
    for i in range(n1):
        arr_left.append(p+i-1)
    for i in range(n2):
        arr_left.append(q+i)
    arr_left.append(10**10)
    arr_right.append(10**10)

    i = 1
    j = 1
    for k in range(p, r):
        if arr_left[i] <= arr_right[j]:
            arr[k] = arr_left[i]
            i += 1
        else:
            arr[k] = arr_right[j]
            j += 1


if __name__ == '__main__':
    arr_main = create_array(5, 4)
    print(*arr_main)
