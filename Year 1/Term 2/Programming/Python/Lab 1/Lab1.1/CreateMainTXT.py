import msvcrt


def CreateMainTXT():
    var=str(input("Очистити файл?(так\ні): "))  
    
    if(var=="так"):
        File=open("Main.txt", "wt")
    else:
        File=open("Main.txt", "at")
    
    if File.closed:
        print("Файл не вдалося відкрити")
    else:
        print("\n__________Файл відкрито для запису__________\n")
        print("Уведіть текст:")
        
        key=msvcrt.getch()
        while key!=(b'\x00'):
            text=str(input())+"\n"
            File.write(text)
            key=msvcrt.getch()
        else:
            print("\n__________Завершення запису файлу, натиснено F1__________\n")
    
        File.close()


