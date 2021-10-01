//
// Created by Hoan Do on 9/15/21.
//

#ifndef PROJECT1_LEXER_MULTIPLYAUTOMATON_H
#define PROJECT1_LEXER_MULTIPLYAUTOMATON_H
#include "Automaton.h"

class MultiplyAutomaton : public Automaton{
public:
    MultiplyAutomaton(): Automaton(TokenType::MULTIPLY){}
    void S0(const std::string& input);
};

#endif //PROJECT1_LEXER_MULTIPLYAUTOMATON_H
