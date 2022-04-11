from Book import Book
from readtxt import get_previous_info
import pickle


def create_txt(name: str):
    # Оформлення перезаписування та доповнення файлу
    # Доповнюємо його через повний перезапис, що зроблено через особливість модулю pickle
    answer = str(input("Очистити файл?(так/ні): "))
    if answer == "так":
        array = []
    else:
        array = get_previous_info(name)

    file_write = open(name, "wb")

    if file_write.closed:
        print("\n__________Файл " + str(name) + " не вдалося відкрити для запису__________\n")
    else:
        print("\n__________Файл " + str(name) + " відкрито для запису__________\n")

        num = int(input("Вкажіть кількість книг для запису: "))
        for i in range(num):
            # book = Book() створює кожний раз у циклі порожній об'єкт класу Book
            # Якщо написати цей рядок до циклу, то в наш масив ми додаватимемо один і той самий елемент
            book = Book()
            book_name = str(input("\nВкажіть ім'я книги: "))
            book.name = book_name

            book_date = str(input("Вкажіть дату написання книги(00.00): "))
            book.date = book_date

            book_year = str(input("Вкажіть рік видання книги(1111): "))
            book.year = book_year
            array.append(book)

        pickle.dump(array, file_write)

        print("\n__________Файл " + str(name) + " закрито__________\n")
    file_write.close()
