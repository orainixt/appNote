import classNote as cNote
import tkinter as tk

def launchNewNoteWindow():
    window = tk.Tk()
    window.title("New Note")
    window.geometry("720x720")

    # Creation of the different fields
    txtTitle = "Title of your Note"
    txtContent = "Content of your Note"

    lblTxt = tk.Label(window, text=txtTitle, width=30, height=5, relief="solid")
    lblContent = tk.Label(window, text=txtContent, width=30, height=5, relief="solid")
    lblTxt.grid(row=0, column=0, padx=10, pady=10, sticky=tk.NW)
    lblContent.grid(row=0, column=1, padx=10, pady=10, sticky=tk.NE) 

    lblTxt.config(state="disabled")
    lblContent.config(state="disabled")
    
    entryTitle = tk.Entry(window, width=40)
    entryTitle.grid(row=0, column=1, padx=10, pady=10, sticky=tk.NE)

    entryContent = tk.Entry(window, width=40)
    entryContent.grid(row=1, column=1, padx=10, pady=10, sticky=tk.NE)
    
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


    
    

