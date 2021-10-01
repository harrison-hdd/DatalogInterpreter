//
// Created by Hoan Do on 9/14/21.
//

#include "FactsAutomaton.h"
void FactsAutomaton::S0 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'F'){
        ++inputRead;
        ++index;
        S1(input);
    }
    else{
        Serr();
    }
}
void FactsAutomaton::S1 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'a'){
        ++inputRead;
        ++index;
        S2(input);
    }
    else{
        Serr();
    }
}
void FactsAutomaton::S2 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'c'){
        ++inputRead;
        ++index;
        S3(input);
    }
    else{
        Serr();
    }
}
void FactsAutomaton::S3 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 't'){
        ++inputRead;
        ++index;
        S4(input);
    }
    else{
        Serr();
    }
}
void FactsAutomaton::S4 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 's'){
        ++inputRead;
        ++index;
    }
    else{
        Serr();
    }
}
