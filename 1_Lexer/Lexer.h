#ifndef LEXER_H
#define LEXER_H
#include <cctype>
#include <vector>
#include "Automata/Automaton.h"
#include "Automata/Token.h"
#include "Automata/ColonAutomaton.h"
#include "Automata/ColonDashAutomaton.h"
#include "Automata/LineCommentAutomaton.h"
#include "Automata/BlockCommentAutomaton.h"
#include "Automata/SchemesAutomaton.h"
#include "Automata/FactsAutomaton.h"
#include "Automata/QueriesAutomaton.h"
#include "Automata/RulesAutomaton.h"
#include "Automata/StringAutomaton.h"
#include "Automata/IDAutomaton.h"
#include "Automata/PeriodAutomaton.h"
#include "Automata/Q_MarkAutomaton.h"
#include "Automata/MultiplyAutomaton.h"
#include "Automata/AddAutomaton.h"
#include "Automata/LeftParenAutomaton.h"
#include "Automata/RightParenAutomaton.h"
#include "Automata/CommaAutomaton.h"

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

