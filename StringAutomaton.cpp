//
// Created by Hoan Do on 9/14/21.
//

#include "StringAutomaton.h"
void StringAutomaton::S0(const string& input) {
    if(input.at(index) == '\''){
        ++inputRead;
        ++index;
        S1(input);
    }
    else{
        Serr();
    }
}

void StringAutomaton::S1(const string& input){
    if (index == input.size()) {
        type = TokenType::UNDEFINED;
        return;
    }
    else if (input.at(index) == '\''){
        ++index;
        ++inputRead;
        S2(input);
    }
    else{
        if(input.at(index) == '\n') ++newLines;
        ++inputRead;
        ++index;
        S1(input);
    }
}

void StringAutomaton::S2(const string& input){
    if(index == input.size()) return;
    else if (input.at(index) == '\''){
        ++index;
        ++inputRead;
        S1(input);
    }
    else {
        return;
    }
}
