import tkinter as tk
import classNote as cNote
import functions as fct 

# Functions used in the loop 
def createNewNote() :
    fct.launchNewNoteWindow()


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