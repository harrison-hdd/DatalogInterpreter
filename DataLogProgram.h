//
// Created by Hoan Do on 9/23/21.
//

#ifndef PROJECT2_PARSER_DATALOGPROGRAM_H
#define PROJECT2_PARSER_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include <set>

using namespace std;

class DataLogProgram {
private:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> queries;
    vector<Rule> rules;
    set<string> domain;
public:
    DataLogProgram(){}
    //~DataLogProgram(){}
    string toString() const;
    void addScheme(Predicate newScheme);
    void addFact(Predicate newFact);
    void addQuery(Predicate newQuery);
    void addRule(Rule newRule);
    friend ostream& operator<<(ostream& os, const DataLogProgram& p){
        return os << p.toString();
    }

    vector<Predicate> getSchemes() const{ return schemes;}
    vector<Predicate> getFacts() const{ return facts;}
};


#endif //PROJECT2_PARSER_DATALOGPROGRAM_H
