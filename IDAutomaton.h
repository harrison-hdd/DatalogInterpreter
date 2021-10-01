//
// Created by Hoan Do on 9/14/21.
//

#ifndef PROJECT1_LEXER_IDAUTOMATON_H
#define PROJECT1_LEXER_IDAUTOMATON_H
#include "Automaton.h"

class IDAutomaton : public Automaton{
public:
    IDAutomaton(): Automaton(TokenType::ID){}
    void S0(const string& input);
    void S1(const string& input);
};


#endif //PROJECT1_LEXER_IDAUTOMATON_H
