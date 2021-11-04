//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_DATABASE_H
#define PROJECT2_PARSER_DATABASE_H
#include "Relation.h"
#include <map>
#include <iostream>
class Database {
private:
    map<string, Relation> database;
    long unsigned int numTuples = 0;
public:
    Database(){}

    void addNewPair(const string& name, const Relation& relation){
        database.insert(pair<string, Relation>(name, relation));
    }


    void addFact(const string& name, const Tuple& tuple){
        for(auto i = database.begin(); i != database.end(); ++i){
            if((*i).first == name){
                if((*i).second.addTuple(tuple)) {
                    ++numTuples;
                    break;
                }
            }
        }
    }

    Relation* getRelationByName (const string& name){
        for (auto i = database.begin(); i != database.end(); ++i) {
                if ((*i).first == name) return &(*i).second;
        }

        throw "";
    }

    /**check if a scheme with the same name is in database*/
    bool isInDatabase(const string& name) const {
        for (auto i = database.begin(); i != database.end(); ++i) {
            if ((*i).first == name) return true;
        }
        return false;
    }

    void updateNumTuples(long unsigned numNewTuples){ numTuples += numNewTuples; }

    long unsigned int getNumTuples() const{ return numTuples; }



};


#endif //PROJECT2_PARSER_DATABASE_H
