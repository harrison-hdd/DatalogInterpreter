#include "Lexer.h"
#include <fstream>
#include <iostream>
Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for(long unsigned int i = 0; i < automata.size(); ++i){
        delete automata.at(i);
    }
    for(long unsigned int i = 0; i < tokens.size(); ++i){
        delete tokens.at(i);
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton);
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new BlockCommentAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new LineCommentAutomaton());
}

void Lexer::Run(std::string& input) {
    int lineNum = 1;
    while(!input.empty()){
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);

        while(isspace(input.at(0))){ //white space handling
            if (input.at(0) == '\n') ++lineNum;
            input.erase(0,1); //should use erase here to save memory and time
            if(input.empty()){
                Token* newToken = new Token(TokenType::END_OF_FILE, "", lineNum);
                tokens.push_back(newToken);
                return;
            }
        }

        for (long unsigned int i = 0; i < automata.size(); ++i){
            int inputRead = automata.at(i)->Start(input);
            if (inputRead > maxRead){
                maxRead = inputRead;
                maxAutomaton = automata.at(i);
                if(maxAutomaton->getType() == TokenType::COMMENT) break;
            }
        }
        if(maxRead > 0){
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNum);
            lineNum += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        else{
            maxRead = 1;
            Token* newToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNum);
            tokens.push_back(newToken);
        }
        input.erase(0,maxRead);
    }

    Token* newToken = new Token(TokenType::END_OF_FILE, "", lineNum);
    tokens.push_back(newToken);
}

string Lexer::toString() const {
    stringstream ss;
    for(long unsigned int i = 0; i < tokens.size(); ++i){
        ss << *tokens.at(i);
    }
    ss << "Total Tokens = " << tokens.size();
    return ss.str();
}
