from Pentagon import Pentagon
from Hexagon import Hexagon


def create_arr():
    arr = []
    angles = int(input("Введіть кількість кутів у фігур "))
    num = int(input("Введіть кількість фігур "))
    for i in range(num):
        if angles == 5:
            tmp = Pentagon()
            tmp.set_points()
            arr.append(tmp)
        elif angles == 6:
            tmp = Hexagon()
            tmp.set_points()
            arr.append(tmp)

    return arr, num


def max_perimeter(num, figures):
    id = 0
    max_p = figures[0].get_perimeter()
    for i in range(num):
        if max_p < figures[i].get_perimeter():
            max_p = figures[i].get_perimeter()
            id = i
    return id


def min_square(num, figures):
    id = 0
    min_s = figures[0].get_square()
    for i in range(num):
        if min_s > figures[i].get_square():
            min_s = figures[i].get_square()
            id = i
    return id


def print_arr(figures):
    for f in figures:
        print(str(f._number) + "-кутник [" + str(f.get_perimeter()) + "//" + str(f.get_square()) + "] " +
              ": " + f.get_text())
