//
// Created by Hoan Do on 9/23/21.
//

#ifndef PROJECT2_PARSER_RULE_H
#define PROJECT2_PARSER_RULE_H
#include "Predicate.h"

class Rule {
private:
    Predicate headPredicate;
    vector<Predicate> predicateList;
public:
    Rule(){}
    //~Rule(){}
    string toString() const;
    void reset(){
        headPredicate.reset();
        predicateList.clear();
    }
    void setHeadPredicate(Predicate newHeadPredicate){
        headPredicate = newHeadPredicate;
    }
    void addPredicate(Predicate newPredicate){
        predicateList.push_back(newPredicate);
    }
    Predicate getHeadPredicate() const {return headPredicate;}

    vector<Predicate> getPredicateList() const { return predicateList; }

    friend ostream& operator<<(ostream& os, const Rule& r){
        return os << r.toString();
    }
};


#endif //PROJECT2_PARSER_RULE_H
