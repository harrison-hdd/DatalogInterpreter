//
// Created by Hoan Do on 9/12/21.
//

#include "LineCommentAutomaton.h"

void LineCommentAutomaton::S0(const string &input) {
    if(input.at(index) == '#'){
        ++inputRead;
        ++index;
        S1(input);
    }
    else{
        Serr();
    }
}

void LineCommentAutomaton::S1(const string &input) {
    if(index == input.size() || input.at(index) == '\n') return; //reached eof or new line
    else{
        ++inputRead;
        ++index;
        S1(input);
    }


//    while(index != input.size() && input.at(index) != '\n'){ //
//        ++inputRead;
//        ++index;
//    }
}

