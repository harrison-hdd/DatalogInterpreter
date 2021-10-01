//
// Created by Hoan Do on 9/14/21.
//

#ifndef PROJECT1_LEXER_QUERIESAUTOMATON_H
#define PROJECT1_LEXER_QUERIESAUTOMATON_H
#include "Automaton.h"

class QueriesAutomaton : public Automaton{
public:
    QueriesAutomaton(): Automaton(TokenType::QUERIES){}
    void S0(const string& input);

    void S1(const string& input);

    void S2(const string& input);

    void S3(const string& input);

    void S4(const string& input);

    void S5(const string& input);

    void S6(const string& input);
};


#endif //PROJECT1_LEXER_QUERIESAUTOMATON_H
