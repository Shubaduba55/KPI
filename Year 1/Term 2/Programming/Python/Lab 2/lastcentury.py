import pickle
import Book


def last_century(name_read, name_write):
    file_read = open(name_read, "rb")
    file_write = open(name_write, "wb")

    if file_read.closed and file_write.closed:
        print("\n__________Файли " + str(name_read) + " та " + str(name_write) + " не вдалося відкрити__________\n")
    else:
        print("\n__________Файли " + str(name_read) + " та " + str(name_write) +
              " відкрито для пошуку творів минулого сторіччя__________\n")

        array_read = pickle.load(file_read)
        array_write = []
        # Пошук у масиві книг, що були видані минулого сторіччя
        for book in array_read:
            if book.year[:2] == "19":
                array_write.append(book)
        pickle.dump(array_write, file_write)

        print("\n__________Файли " + str(name_read) + " та " + str(name_write) + " закрито__________\n")
    file_read.close()
    file_write.close()
