from column import Column
from merge_sort_2D import merge_sort


def inversion_check(arr1):
    count = 0
    for i in range(len(arr1)):
        for j in range(len(arr1)):
            if arr1[i] > arr1[j] and i < j:
                count += 1
                # print("(" + str(i+1) + ", " + str(j+1) + ")")

    return count


# back 1 -> 10
def create_array_of_columns(arr, n_films, n_users, x_num):
    arr_new = []
    for i in range(0, n_films + 1):
        temp = Column(x_num)
        for j in range(n_users):
            temp.app_array(arr[j][i])
        arr_new.append(temp)
    return arr_new


def columns_to_rows(arr, n_columns, n_rows):
    arr_new = []
    for i in range(n_rows):
        arr_temp = [i + 1]
        for j in range(n_columns):
            temp = arr[j].column
            arr_temp.append(temp[i])
        arr_new.append(arr_temp)

    return arr_new


def print_inversions(name, arr, n_users):
    dictionary = [[], []]
    with open(name, "wt") as file_write:
        for i in range(n_users):
            inversions = inversion_check(arr[i][1:])
            dictionary[0].append(arr[i][0])
            dictionary[1].append(inversions)
        new = create_array_of_columns(dictionary, n_users - 1, 2, 1)
        new = merge_sort(new)
        for i in new:
            file_write.write("(" + str(i.column[0]) + "; " + str(i.column[1]) + ")\n")

