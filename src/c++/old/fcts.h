#ifndef FCTS_H
#define FCTS_H

#include <string>


struct Note {
    std::string title;
    std::string content;
};

void addNote(const std::string username, const Note& note);
std::string searchNote(const std::string username);
struct Note createNote(const std::string title, const std::string content);


#endif