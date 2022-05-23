from Point import Point

class Figure:
    def __init__(self, num: int = 0, points: list = []):
        self._number = num
        self._points = points[0::]
        self._perimeter = 0
        self._square = 0

    def get_text(self):
        text = ""
        for pt in self._points:
            text += "(" + str(pt.get_x()) + "; " + str(pt.get_y()) + ") "
        return text

    def display(self):
        print(str(self._number) + "-кутник: ")
        for i in range(0, self._number):
            self._points[i].display()
        return

    def get_points(self):
        return self._points

    def set_points(self):
        print("Точки " + str(self._number) + "-кутника:\n")
        for i in range(self._number):
            x = float(input("Точка " + str(i + 1) + "\nx: "))
            y = float(input("y: "))
            tmp = Point(x, y)
            self._points.append(tmp)
        return

    def set_number(self, num: int):
        self._number = num
        self._points = []
        self.set_points()
        return

    def calc_perimeter(self):
        for i in range(self._number - 1):
            self._perimeter += Point.calc_distance(self._points[i], self._points[i+1])
        if self._number > 2:
            self._perimeter += Point.calc_distance(self._points[0], self._points[self._number - 1])
        self._perimeter = round(self._perimeter, 4)

    def calc_square(self):
        if self._number == 3:
            self._square = Point.calc_sq_triangle(self._points[0], self._points[1], self._points[2])
        if self._number >= 4:
            avg = Point.calc_avg(self._number, self._points)
            for i in range(self._number - 1):
                self._square += Point.calc_sq_triangle(self._points[i], self._points[i + 1], avg)
            self._square += Point.calc_sq_triangle(self._points[0], self._points[self._number - 1], avg)
        self._square = round(self._square, 4)

    def get_perimeter(self):
        if self._perimeter == 0 and self._number >= 2:
            self.calc_perimeter()
        return self._perimeter

    def get_square(self):
        if self._square == 0 and self._number >= 3:
            self.calc_square()
        return self._square
