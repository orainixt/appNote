#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <tuple>

extern "C"{
    std::tuple<std::string, std::string> collectInformationFromNote(Note& note);
}



#endif