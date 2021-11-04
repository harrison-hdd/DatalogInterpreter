//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_RELATION_H
#define PROJECT2_PARSER_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include <set>
#include <sstream>
#include <iostream>
class Relation {
private:

    string name;
    Header header;
    set<Tuple> tupleSet;

    Tuple naturalJoinHelper_joinTuples(const Tuple& t_A, const Tuple& t_B,
                                       pair<vector<long unsigned int>,vector<long unsigned int>>& matchedIndexes);

    Header naturalJoinHelper_joinHeaders(const Header& h_A, const Header h_B,
                                         pair<vector<long unsigned int>,vector<long unsigned int>>& matchedIndexes);

    bool naturalJoinHelper_checkIfTuplesAreJoinable(const Tuple& t_A, const Tuple& t_B,
                                              pair<vector<long unsigned int>,vector<long unsigned int>>& matchedIndexes);

    string unionizeRelationsHelper_newTupleString(const Header& header, const Tuple& tuple);
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

    void changeName(const string& name){ this->name = name; }
    void changeHeader(const Header& header){ this->header = header; }

    long unsigned int numTuples() const{return tupleSet.size();}

    Header getHeader() const {return header;}
    string getName() const {return name;}

    bool addTuple(const Tuple& tuple){ return tupleSet.insert(tuple).second; }

    Relation* select(const long unsigned int& attributeIndex, const string& value, Relation* inputRelation);
    Relation* select(const vector<pair<string,vector<long unsigned int>>>& variableInstances, Relation* inputRelation);
    Relation* project(const vector<long unsigned int>& attributeIndexes, Relation* inputRelation);
    Relation* rename(const long unsigned int& attributeIndex, const string& value, Relation* inputRelation);
    Relation* naturalJoin(Relation* A, Relation* B);
    long unsigned int unionizeRelations(Relation* newRelation, Relation* existingRelation);

};


#endif //PROJECT2_PARSER_RELATION_H
