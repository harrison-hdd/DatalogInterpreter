//
// Created by Hoan Do on 9/15/21.
//

#ifndef PROJECT1_LEXER_Q_MARKAUTOMATON_H
#define PROJECT1_LEXER_Q_MARKAUTOMATON_H
#include "Automaton.h"

class Q_MarkAutomaton : public Automaton{
public:
    Q_MarkAutomaton(): Automaton(TokenType::Q_MARK){}
    void S0(const std::string& input);
};

#endif //PROJECT1_LEXER_Q_MARKAUTOMATON_H
