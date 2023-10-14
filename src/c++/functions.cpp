#include <iostream>
#include <tuple>
#include "Note.h"

extern "C" {
    std::tuple<std::string, std::string> collectInformationFromNote(Note& note){
        std::string title = note.getTitle(); 
        std::string content = note.getContent();

        return std::make_tuple(title,content);
    }
}
