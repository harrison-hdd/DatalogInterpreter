//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_RELATION_H
#define PROJECT2_PARSER_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include <set>
#include <sstream>
class Relation {
private:

    string name;
    Header header;
    set<Tuple> tupleSet;
public:
    Relation(){}
    Relation(string name): name(name){}

    Relation(const string& name, const Header& header): name(name), header(header){}

    Relation(const Relation& r){ *this = r;}

    bool empty(){ return tupleSet.empty(); }
    string toString() const;
    friend ostream& operator<<(ostream& os, const Relation& r){
        return os << r.toString();
    }


    long unsigned int numTuple() const{return tupleSet.size();}

    Header getHeader() const {return header;}
    string getName() const {return name;}

    void addTuple(const Tuple& tuple){ tupleSet.insert(tuple); }

    Relation* select(const long unsigned int& attributeIndex, const string& value, Relation* inputRelation);
    Relation* select(const vector<pair<string,vector<long unsigned int>>>& variableInstances, Relation* inputRelation);
    Relation* project(const vector<long unsigned int>& attributeIndexes, Relation* inputRelation);
    Relation* rename(const long unsigned int& attributeIndex, const string& value, Relation* inputRelation);

};


#endif //PROJECT2_PARSER_RELATION_H
