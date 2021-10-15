//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_DATABASE_H
#define PROJECT2_PARSER_DATABASE_H
#include "Relation.h"
#include <map>
class Database {
private:
    map<string, Relation> database;
public:
    Database(){}

    void addNewPair(const string& name, const Relation& relation){
        database.insert(pair<string, Relation>(name, relation));
    }

    void addFact(const string& name, const Tuple& tuple){
        for(auto i = database.begin(); i != database.end(); ++i){
            if((*i).first == name){
                (*i).second.addTuple(tuple);
                break;
            }
        }
    }

    Relation getRelationByName(const string& name){
        for(auto i = database.begin(); i != database.end(); ++i){
            if((*i).first == name) return (*i).second;
        }
    }
};


#endif //PROJECT2_PARSER_DATABASE_H
