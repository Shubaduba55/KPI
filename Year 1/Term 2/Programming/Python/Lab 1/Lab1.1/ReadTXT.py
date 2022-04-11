def ReadTXT(name:str):
    with open(name, "rt") as File:
        print("\n__________Початок читання файлу "+name+"__________\n")
        print(File.read())
        print("\n__________Кінець читання файлу "+name+"__________")


