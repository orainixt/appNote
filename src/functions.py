import classNote as cNote
import tkinter as tk

def launchNewNoteWindow():
    window = tk.Tk()
    window.title("New Note")
    window.geometry("720x720")

def saveData(filename,data) : 
    with open(filename, 'w') as file : 
        for item in data : 
            file.write(f"{item}\n")

def loadData(filename):
    data = []
    try :
        with open(filename, 'r') as file :
            for line in file : 
                data.append(line.strip())
    except FileNotFoundError : 
        pass
    return data

def loadDataFromNote(note : cNote) -> list[str] :
    return [note.title,note.content]

def createNoteFromData(data : list[str]) -> list[cNote.Note] :
    listOfNote = [] 
    for i in range(0,len(data),2) :
        note = cNote.Note(data[i],data[i+1])
        listOfNote.append(note)
    return listOfNote


    
    

