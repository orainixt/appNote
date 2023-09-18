#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <filesystem>   

const std::string DATABASE_FOLDER = "note_database/"; 

struct Note
{   
    std::string title; // Title of the note
    std::string content; // The note he wants to add 
};

void addNote(const std::string username, const Note& note)
{
    if (!std::__fs::filesystem::exists(DATABASE_FOLDER)) {
        if (!std::__fs::filesystem::create_directory(DATABASE_FOLDER)) {
            std::cerr << "DATABASE FOLDER can't be created";
            return;
        }
    }

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
    std::ifstream databaseFile(fileName);

    if (databaseFile.is_open())
    {
        std::string line; 

        while (std::getline(databaseFile,line))
        {
            size_t column = line.find(":");

            if (column != std::string::npos) {

                std::string title = line.substr(0, column);
                std::string content = line.substr(column + 1);
                
                title.erase(0, title.find_first_not_of(" "));
                title.erase(title.find_last_not_of(" ") + 1);


                content.erase(0, content.find_first_not_of(" "));
                content.erase(content.find_last_not_of(" ") + 1);

                Note note;
                note.title = title;
                note.content = content;
                notes.push_back(note);
        
            } else {
                std::cerr << "Invalid line format" << line << std::endl;
            }
        }
        databaseFile.close();
    }
    else 
    {
        std::cerr << "Error while searching the file" << std::endl;
        return notes;
    }

    return notes;
}

struct Note createNote(const std::string title, const std::string content) {

    Note toCreate;

    toCreate.title = title;
    toCreate.content = content;

    return toCreate;
}

void viewNote(std::vector<Note>& notes) {

    std::string result; 

    for (const auto& note : notes) {
    result += "Tittle : " + note.title + "\nContent : " + note.content + "\n";
    }

    std::cout << result;
}