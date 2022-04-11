def Search(main:str, name:str):
    File=open(main, "rt")
    FileID=open(name, "wt")
    if File.closed and FileID.closed:
        print("\nФайли: " + main +" та "+name+" не вдалося відкрити\n")
    else:
        print("\n___________Файли: " + main +" та "+name+" відкрито___________\n")
        text=File.read()
        start=0
        id=""
        library=[]
        start=text.find("=", start)
        while start!=-1:
            if(text[start+1]=="="):
                start=text.find("=", start+2)
            else:
                i=start-1 
                while(text[i]==' '):
                    i=i-1
                while text[i].isalpha() or text[i].isdigit():
                    id+=text[i]
                    i=i-1
                id=id[::-1]
                if(id!=""):
                    check=True
                    for tmp in library:
                        if id==tmp:
                            check=False
                    if check:
                        
                        FileID.write(id+"\n")
                        library.append(id)
                id=""
                start=text.find("=", start+1)
    
    
        print("\n___________Файли: " + main +" та "+name+" закрито___________\n")
    File.close()
    FileID.close()


