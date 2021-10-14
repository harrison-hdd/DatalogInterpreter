//
// Created by Hoan Do on 9/23/21.
//

#ifndef PROJECT2_PARSER_PARSER_H
#define PROJECT2_PARSER_PARSER_H
#include "Token.h"
#include <iostream>
#include <vector>
#include "DataLogProgram.h"
using namespace std;


class Parser{
private:
    long unsigned int index;
    DataLogProgram program;
    Predicate currPredicate; //can store one scheme or one fact or one query or one predicate of a Rule object
    Rule currRule;
    bool failed = false; //will be changed to true after the first illegal token is caught

    /**=========================================*/
    void parseDatalog (vector<Token*>& tokens);

    void parseScheme(vector<Token*>& tokens);
    void parseSchemeList(vector<Token*>& tokens);
    void parseFact(vector<Token*>& tokens) ;
    void parseFactList(vector<Token*>& tokens);
    void parseRule(vector<Token*>& tokens);
    void parseRuleList(vector<Token*>& tokens);
    void parseQuery(vector<Token*>& tokens);
    void parseQueryList(vector<Token*>& tokens);

    void parseIDList(vector<Token*>& tokens);
    void parseStringList(vector<Token*>& tokens);
    void parseParameterList(vector<Token*>& tokens);
    void parsePredicateList(vector<Token*>& tokens);

    void parsePredicate(vector<Token*>& tokens);
    void parseHeadPredicate(vector<Token*>& tokens);

    void parseParameter(vector<Token*>& tokens);

    void matcher(Token*& input, TokenType matchType);

public:
    Parser(): index(0){};
    //~Parser(){}
    string toString() const;
    friend ostream& operator<<(ostream& os, const Parser& p){
        return os << p.toString();
    }
    bool hasError() const{ return failed; }
    DataLogProgram getProgram() const{ return program; }

    void parse(vector<Token*>& tokens);
};


#endif //PROJECT2_PARSER_PARSER_H
