//
// Created by Hoan Do on 9/15/21.
//

#ifndef PROJECT1_LEXER_ADDAUTOMATON_H
#define PROJECT1_LEXER_ADDAUTOMATON_H
#include "Automaton.h"

class AddAutomaton : public Automaton{
public:
    AddAutomaton(): Automaton(TokenType::ADD){}
    void S0(const std::string& input);
};


#endif //PROJECT1_LEXER_ADDAUTOMATON_H
