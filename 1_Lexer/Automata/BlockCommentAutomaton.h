//
// Created by Hoan Do on 9/12/21.
//

#ifndef PROJECT1_LEXER_BLOCKCOMMENTAUTOMATON_H
#define PROJECT1_LEXER_BLOCKCOMMENTAUTOMATON_H
#include "Automaton.h"

class BlockCommentAutomaton : public Automaton {
public:
    BlockCommentAutomaton(): Automaton(TokenType::COMMENT){}
    void S0(const string& input);

    void S1(const string& input);

    void S2(const string& input);

    void S3(const string& input);
};


#endif //PROJECT1_LEXER_BLOCKCOMMENTAUTOMATON_H
