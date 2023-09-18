#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

const std::string DATABASE_FOLDER = "note_database/"; 

struct Note
{   
    std::string title; // Title of the note
    std::string content; // The note he wants to add 
};

void addNote(const std::string username, const Note& note)
{
    std::string fileName = DATABASE_FOLDER + username + "_notes.txt";
    std::ofstream databaseFile(fileName, std::ios::app);

    if (databaseFile.is_open())
    {
        databaseFile << note.title << " : " << note.content << std::endl;
        databaseFile.close();
        std::cout << "The note of " << username << " has been added." << std::endl;
    }
    else 
    {
        std::cerr << "Error while oppening the file" << std::endl; 
    }
}

std::vector<Note> searchNote(const std::string username)
{
    std::vector<Note> notes;
    
    std::string fileName = DATABASE_FOLDER + username + "_notes.txt";
    std::ifstream databaseFile(fileName, std::ios::app);

    if (databaseFile.is_open())
    {
        std::string line; 

        while (std::getline(databaseFile,line))
        {
            Note note; 
            size_t column = line.find(":");

            if (column != std::string::npos) {

                note.title = line.substr(0, column);
                note.content = line.substr(column + 1);
                notes.push_back(note);
            }
        }
        databaseFile.close();
    }
    else 
    {
        std::cerr << "Error while oppening the file" << std::endl;
    }

    return notes;
}

struct Note createNote(const std::string title, const std::string content) {

    Note toCreate;

    toCreate.title = title;
    toCreate.content = content;

    return toCreate;
}

std::string viewNote(Note& note) {

    std::string result; 
    return result;
}