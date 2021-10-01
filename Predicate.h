//
// Created by Hoan Do on 9/23/21.
//

#ifndef PROJECT2_PARSER_PREDICATE_H
#define PROJECT2_PARSER_PREDICATE_H
#include "Parameter.h"

class Predicate {
private:
    string ID;
    mutable vector<Parameter> parameters;
public:
    Predicate(){}
    Predicate(string ID): ID(ID){}
    //~Predicate(){}
    string toString() const;
    void setID(string ID){
        this->ID = ID;
    }
    void addParameter(Parameter newParameter){
        parameters.push_back(newParameter);
    }
    void reset(){
        parameters.clear();
    }
    vector<Parameter>& getParameters() const {return parameters;}

    friend ostream& operator<<(ostream& os, const Predicate& p){
        return os << p.toString();
    }
};


#endif //PROJECT2_PARSER_PREDICATE_H
