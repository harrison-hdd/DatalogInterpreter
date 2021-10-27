#ifndef LEXER_H
#define LEXER_H
#include <cctype>
#include <vector>
#include "Automaton.h"
#include "Token.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "LineCommentAutomaton.h"
#include "BlockCommentAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "QueriesAutomaton.h"
#include "RulesAutomaton.h"
#include "StringAutomaton.h"
#include "IDAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "CommaAutomaton.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();


public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    string toString() const;
    friend ostream& operator<<(ostream& os, Lexer*& l){
        return os << l->toString();
    }
    vector<Token*> getTokenList() const {return tokens;}

};

#endif // LEXER_H

