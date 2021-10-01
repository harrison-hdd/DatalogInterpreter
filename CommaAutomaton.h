//
// Created by Hoan Do on 9/15/21.
//

#ifndef PROJECT1_LEXER_COMMAAUTOMATON_H
#define PROJECT1_LEXER_COMMAAUTOMATON_H
#include "Automaton.h"
class CommaAutomaton: public Automaton{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input);
};
;


#endif //PROJECT1_LEXER_COMMAAUTOMATON_H
