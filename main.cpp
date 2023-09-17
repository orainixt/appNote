#include <iostream>
#include <fstream> 
#include <string>

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

std::string searchNote(const std::string username)
{
    std::string fullnote;
    
    std::string fileName = DATABASE_FOLDER + username + "_notes.txt";
    std::ifstream databaseFile(fileName, std::ios::app);

    if (databaseFile.is_open())
    {
        std::string line; 

        while (std::getline(databaseFile,line))
        {
            fullnote = fullnote + line + "\n";
        }
    }
    else 
    {
        std::cerr << "Error while oppening the file" << std::endl;
    }

    return fullnote;
}

