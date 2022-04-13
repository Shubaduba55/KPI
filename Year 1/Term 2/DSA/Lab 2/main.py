from create_array import create_array
from functions import create_array_of_columns, columns_to_rows, print_inversions
from merge_sort_2D import merge_sort
from column import Column


def main():
    name_input = "ip11_shamkov_02_input.txt"
    name_output = "ip11_shamkov_02_output.txt"

    # ситаємо двовимірний масив користувачів та їхньої оцінки фільмів
    arr_main, users, films = create_array(name_input)

    x = int(input("Уведіть номер користувача, відносно якого будемо рахувати інверсії: "))

    # створюємо масив стовбців, тобто розрізаємо масив не по рядках, а по колонках
    arr_columns = create_array_of_columns(arr_main, films, users, x)

    # сортуємо двовимірний масив за певним рядком, номер якого є x
    arr_sorted = merge_sort(arr_columns[1:])

    # знову змінємо розріз двовимірного масиву
    arr_rows = columns_to_rows(arr_sorted, films, users)

    # підраховуємо кількість інверсій та записуємо це значення у файл
    print_inversions(name_output, arr_rows, users)


if __name__ == '__main__':
    main()





