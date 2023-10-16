import tkinter as tk
import os 
import classNote as cNote
import functions as fct 

def main() :

    # Functions used in the loop 
    def createNewNote() :
        fct.launchNewNoteWindow()

    # Open data : 
    script_dir = os.path.dirname(os.path.abspath(__file__))
    dataFilePath = os.path.join(script_dir,"..", "data", "data.txt")    
    if not os.path.exists(dataFilePath) :
        print("The file is not existing yet. Creating new one ...")
        with open(dataFilePath,"w") as file : 
            file.write("")
        
    else : 
        print("Opening your file ...")
        userData = fct.loadData(dataFilePath)
        userNotes = fct.createNoteFromData(userData)

    # Creation of the main window 
    window = tk.Tk()
    window.title("My Notes")
    window.geometry("720x700")

    # Creation of the differents object of the app 
    # Text field with all the notes


    # Button for the New Note
    buttonCreate = tk.Button(window, text="Create New Note", command=createNewNote,
                                bg ="blue", fg="black",font=("Comic Sans MS",14))
    buttonCreate.pack(side=tk.BOTTOM, pady=10)

    # Last instruction
    window.mainloop()

if __name__ == "__main__":
    main()
