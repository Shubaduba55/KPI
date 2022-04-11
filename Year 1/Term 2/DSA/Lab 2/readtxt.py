import pickle


def get_previous_info(name: str):
    """
    Функція для отримання попередньої інформації з файлу
    та його перезаписуз нею одним блоком, що викликано особливістю
    роботи з модулем pickle
    """
    with open(name, "rb") as file_read:
        array = pickle.load(file_read)
    return array


def read_txt_bin(name: str):
    file_read = open(name, "rb")
    if file_read.closed:
        print("\n__________Файл " + str(name) + " не вдалося відкрити для читання__________\n")
    else:
        print("\n__________Файл " + str(name) + " відкрито для читання__________\n")

        array = pickle.load(file_read)
        for book in array:
            book.write()

        print("\n__________Файл " + str(name) + " закрито__________\n")
    file_read.close()

