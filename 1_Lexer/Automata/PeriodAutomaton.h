//
// Created by Hoan Do on 9/14/21.
//

#ifndef PROJECT1_LEXER_PERIODAUTOMATON_H
#define PROJECT1_LEXER_PERIODAUTOMATON_H
#include "Automaton.h"

class PeriodAutomaton : public Automaton{
public:
    PeriodAutomaton(): Automaton(TokenType::PERIOD){}
    void S0(const std::string& input);
};


#endif //PROJECT1_LEXER_PERIODAUTOMATON_H
