import pickle
import Book


def count_winter(name: str):
    with open(name, "rb") as file_read:
        print("\n__________Файл " + str(name) + " відкрито для підрахунку творів, написаних узимку__________\n")
        array = pickle.load(file_read)
        count = 0
        for book in array:
            date = book.date[3:]
            if date == "12" or date == "01" or date == "02":
                count += 1
        print("\n__________Файл " + str(name) + " закрито для підрахунку творів, написаних узимку__________\n")
    return count
