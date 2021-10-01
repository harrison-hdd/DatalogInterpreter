//
// Created by Hoan Do on 9/15/21.
//

#ifndef PROJECT1_LEXER_LEFTPARENAUTOMATON_H
#define PROJECT1_LEXER_LEFTPARENAUTOMATON_H
#include "Automaton.h"

class LeftParenAutomaton : public Automaton{
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_LEXER_LEFTPARENAUTOMATON_H
