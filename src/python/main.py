import os
import ctypes 


# Get the actual directory 
currentDir = os.path.dirname(os.path.abspath(__file__))

# Load the C++ library 
noteLib = ctypes.CDLL(os.path.join(currentDir, 'Note.dylib'))

class NoteStruct(ctypes.Structure) : 
    _fields_ = [("title", ctypes.c_char_p),
                ("content", ctypes.c_char_p)]

def createNote(title,content) : 
    createFunction = noteLib.create
    createFunction.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
    createFunction.restype = ctypes.POINTER(NoteStruct)

    # Call the C++ create to instance a Note object 
    notePointeur = createFunction(title.encode('utf-8'), content.encode('utf-8'))

    # Convert the pointer into a NoteStruct structure 
    noteFinal = notePointeur.contents

    # Free the allocated memory 
    noteLib.free(notePointeur)

    # Return the note we created 
    return noteFinal 
