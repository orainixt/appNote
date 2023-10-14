#include <iostream>

class Note {
public:
    std::string title;
    std::string content;

    static Note* create(std::string title, std::string content){
        Note* note = new Note();
        note->title = title; 
        note->content = content; 
        return note;
    }

    std::string getTitle(){
        return this->title;
    }

    std::string getContent(){
        return this->content;
    }
};