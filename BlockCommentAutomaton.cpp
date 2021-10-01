//
// Created by Hoan Do on 9/12/21.
//

#include "BlockCommentAutomaton.h"

void BlockCommentAutomaton::S0(const string& input) {
    if(input.at(index) == '#'){
        ++inputRead;
        ++index;
        S1(input);
    }
    else{
        Serr();
    }
}

void BlockCommentAutomaton::S1(const string& input) {
    if(index == input.size()){
        Serr();
    }
    else if(input.at(index) == '|'){
        ++inputRead;
        ++index;
        S2(input);
    }
    else{
        Serr();
    }
}

void BlockCommentAutomaton::S2(const string& input) {
    if(index == input.size()){
        ///if reach eof before closing comment
        type = TokenType::UNDEFINED; ///the whole string read become an UNDEFINED token
        return;
    }
    else if(input.at(index) == '|'){
        ++inputRead;
        ++index;
        S3(input);
    }
    else{
        if(input.at(index) == '\n') ++newLines;
        ++inputRead;
        ++index;
        S2(input);
    }
}

void BlockCommentAutomaton::S3(const string& input) {
    if(index == input.size()){ //reached eof
        ///if reach eof before closing comment
        type = TokenType::UNDEFINED; ///the whole string read become an UNDEFINED token
        return;
    }
    else if(input.at(index) == '#'){
        ++inputRead;
        ++index;
    }
    else if(input.at(index) == '|'){
        ++inputRead;
        ++index;
        S3(input);
    }
    else{
        if(input.at(index) == '\n') ++newLines;
        ++inputRead;
        ++index;
        S2(input);
    }
}
