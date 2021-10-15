//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_RELATION_H
#define PROJECT2_PARSER_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include <set>
class Relation {
private:
    string name;
    Header header;
    set<Tuple> relation;
public:
    Relation(const string& name, const Header& header): name(name), header(header){}

    void addTuple(const Tuple& tuple){ relation.insert(tuple); }



    Relation select(long unsigned int attributeIndex, string value);
    Relation* project();
    void rename();
};


#endif //PROJECT2_PARSER_RELATION_H
