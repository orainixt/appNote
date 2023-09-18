#include <iostream>
#include <string>

#include <vector>

#include "menu.h"
#include "fcts.h"

using namespace std;

int main() { 

    string username;
    int firstOption;
    Note note;
    string title;
    string content;
    std::vector<Note> notes;

    std::cout << "\033[2J\033[1;1H";

    displayUserMenu();
    cin >> username; 

    displayOptionMenu();
    cin >> firstOption;

    switch (firstOption) {
        case 1: // Option voir vos notes
            notes = searchNote(username);
            viewNote(notes);
            break;
        case 2: // Option retrer une note
            displayTitleNote();
            cin >> title;
            displayContentNote();
            cin >> content;
            note = createNote(title, content);
            addNote(username, note);  // Ajout de la note
            break;

        default:
            cout << "Option invalide" << endl;
            break;
    }

    return 0;
}