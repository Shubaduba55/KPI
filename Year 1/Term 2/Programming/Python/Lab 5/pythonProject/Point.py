from math import sqrt
from accessify import private, protected


class Point:
    def __new__(cls, *args, **kwargs):
        return super().__new__(cls)

    def __init__(self, x: float = 0, y: float = 0):
        self.__x = x
        self.__y = y

    def display(self):
        print("(" + str(self.__x) + "; " + str(self.__y) + ")")

    def set_x(self, x):
        if type(x) in (int, float):
            self.__x = x

    def set_y(self, y):
        if type(y) in (int, float):
            self.__y = y

    def set(self, x, y):
        if type(x) in (int, float) and type(y) in (int, float):
            self.__x = x
            self.__y = y

    def get_x(self):
        return self.__x

    def get_y(self):
        return self.__y

    def __add__(self, other):
        if type(other) == Point:
            x = self.__x + other.__x
            y = self.__y + other.__y
            return Point(x, y)

    def __increase__(self, other):
        if type(other) == Point:
            self.__x += other.__x
            self.__y += other.__y
        return

    def __div_avg__(self, number):
        if type(number) == int:
            self.__x /= number
            self.__y /= number
        return

    @staticmethod
    def calc_distance(point_a, point_b):
        return sqrt((point_a.__x - point_b.__x)**2 + (point_a.__y - point_b.__y)**2)

    @staticmethod
    def calc_sq_triangle(point_a, point_b, point_c):
        side_a = Point.calc_distance(point_a, point_b)
        side_b = Point.calc_distance(point_b, point_c)
        side_c = Point.calc_distance(point_c, point_a)
        semi_p = (side_a + side_b + side_c) / 2
        return sqrt(semi_p * (semi_p - side_a) * (semi_p - side_b) * (semi_p - side_c))

    @staticmethod
    def calc_avg(num, points):
        tmp = Point()
        for i in range(num):
            tmp.__increase__(points[i])
        tmp.__div_avg__(num)
        return tmp
