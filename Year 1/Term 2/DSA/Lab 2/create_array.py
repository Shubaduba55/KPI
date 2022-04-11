def extract_numbers(line: str):
    arr_numbers = []
    line_tmp = ""
    i = 0
    while line[i] != "\n":
        while line[i].isdigit():
            line_tmp += line[i]
            i += 1
        else:
            arr_numbers.append(int(line_tmp))
            line_tmp = ""
            if line[i] != "\n":
                i += 1

    if line_tmp.isdigit():
        arr_numbers.append(int(line_tmp))



    """
    
    for i in range(len(line)):
        while line[i] != " ":
            line_tmp += line[i]
            i += 1
        else:
            arr_numbers.append(int(line_tmp))
            line_tmp = ""
            i += 1
            
    """
    return arr_numbers


def create_array_2d(file_read, u, n):
    arr = []
    for i in range(u):
        line = file_read.readline()
        arr.append(extract_numbers(line))

    return arr


def create_array(name: str):
    arr = []
    file_read = open(name, "rt")
    if file_read.closed:
        print("\n__________Файл " + str(name) + " не вдалося відкрити для читання__________\n")
    else:
        print("\n__________Файл " + str(name) + " відкрито для читання__________\n")

        line = file_read.readline()
        arr_line1 = extract_numbers(line)
        users = arr_line1[0]
        films = arr_line1[1]
        arr = create_array_2d(file_read, users, films)

        print("\n__________Файл " + str(name) + " закрито__________\n")
    file_read.close()
    return arr
