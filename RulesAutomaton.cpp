//
// Created by Hoan Do on 9/14/21.
//

#include "RulesAutomaton.h"
void RulesAutomaton::S0 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'R'){
        ++inputRead;
        ++index;
        S1(input);
    }
    else{
        Serr();
    }
}
void RulesAutomaton::S1 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'u'){
        ++inputRead;
        ++index;
        S2(input);
    }
    else{
        Serr();
    }
}
void RulesAutomaton::S2 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'l'){
        ++inputRead;
        ++index;
        S3(input);
    }
    else{
        Serr();
    }
}
void RulesAutomaton::S3 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'e'){
        ++inputRead;
        ++index;
        S4(input);
    }
    else{
        Serr();
    }
}
void RulesAutomaton::S4 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 's'){
        ++inputRead;
        ++index;
    }
    else{
        Serr();
    }
}