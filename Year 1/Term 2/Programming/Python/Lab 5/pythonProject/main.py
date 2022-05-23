from Point import Point
from Figure import Figure
from Pentagon import Pentagon
from Hexagon import Hexagon
from Functions import create_arr, max_perimeter, min_square, print_arr

if __name__ == '__main__':
    arr1, num1 = create_arr()
    arr2, num2 = create_arr()

    max_p_id = max_perimeter(num1, arr1)
    min_s_id = min_square(num2, arr2)
    
    print(str(arr1[0]._number) + "-кутник з максимальним периметром " + str(arr1[max_p_id].get_perimeter()) +
        ": " + arr1[max_p_id].get_text())

    print(str(arr2[0]._number) + "-кутник з мінімальною площею " + str(arr2[min_s_id].get_square()) +
       ": " + arr2[min_s_id].get_text())


    print_arr(arr2)
    print_arr(arr1)

