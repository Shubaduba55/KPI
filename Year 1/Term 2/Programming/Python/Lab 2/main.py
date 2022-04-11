from createtxt import create_txt
from readtxt import read_txt
from countwinter import count_winter
from lastcentury import last_century

if __name__ == '__main__':
    name1 = "File.txt"
    name2 = "Last century.txt"
    create_txt(name1)
    read_txt(name1)
    print("Кількість творів виданих узимку: " + str(count_winter(name1)))
    last_century(name1, name2)
    read_txt(name2)
