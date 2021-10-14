//
// Created by Hoan Do on 9/14/21.
//

#include "QueriesAutomaton.h"
void QueriesAutomaton::S0 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'Q'){
        ++inputRead;
        ++index;
        S1(input);
    }
    else{
        Serr();
    }
}
void QueriesAutomaton::S1 (const string& input){
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
void QueriesAutomaton::S2 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'e'){
        ++inputRead;
        ++index;
        S3(input);
    }
    else{
        Serr();
    }
}
void QueriesAutomaton::S3 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'r'){
        ++inputRead;
        ++index;
        S4(input);
    }
    else{
        Serr();
    }
}
void QueriesAutomaton::S4 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'i'){
        ++inputRead;
        ++index;
        S5(input);
    }
    else{
        Serr();
    }
}
void QueriesAutomaton::S5 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 'e'){
        ++inputRead;
        ++index;
        S6(input);
    }
    else{
        Serr();
    }

}
void QueriesAutomaton::S6 (const string& input){
    if(index == input.length()) Serr();
    else if(input.at(index) == 's'){
        ++inputRead;
        ++index;
    }
    else{
        Serr();
    }
}
