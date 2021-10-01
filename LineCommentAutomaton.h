//
// Created by Hoan Do on 9/12/21.
//

#ifndef PROJECT1_LEXER_LINECOMMENTAUTOMATON_H
#define PROJECT1_LEXER_LINECOMMENTAUTOMATON_H
#include "Automaton.h"

class LineCommentAutomaton : public Automaton{
public:
    LineCommentAutomaton() : Automaton(TokenType::COMMENT){}
    void S0(const string& input);
    void S1(const string& input);
};


#endif //PROJECT1_LEXER_LINECOMMENTAUTOMATON_H
