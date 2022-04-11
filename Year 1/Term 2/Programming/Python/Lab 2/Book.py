class Book:
    """Дані про книгу, її ім'я, дата написання та рік видання"""
    def __init__(self, name="", date="", year=""):
        self.name = name
        self.date = date
        self.year = year

    def write(self):
        print("Назва книги: " + self.name +
              "\nДата написання книги: " + self.date +
              "\nРік видання книги: " + self.year + "\n")
