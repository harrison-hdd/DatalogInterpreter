//
// Created by Hoan Do on 9/14/21.
//

#include "IDAutomaton.h"
void IDAutomaton::S0(const string& input){
    if(isalpha(input.at(index))){
        ++inputRead;
        ++index;
        S1(input);
    }
    else{
        Serr();
    }
}
void IDAutomaton::S1(const string& input){
    if(index == input.size() || isspace(input.at(index))) return;
    else if(isalnum(input.at(index))){
        ++index;
        ++inputRead;
        S1(input);
    }
    else{
        return;
    }
}