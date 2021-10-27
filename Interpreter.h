//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_INTERPRETER_H
#define PROJECT2_PARSER_INTERPRETER_H
#include "Database.h"
#include "DataLogProgram.h"
#include <iostream>
class Interpreter {
private:
    Database database;

    void buildDatabase(const vector<Predicate>& schemes, const vector<Predicate>& facts);

    void evaluateQueries(const vector<Predicate>& queries);

    void variableTracker(const string& variable, const long unsigned int& index ,
                         vector<pair<string,vector<long unsigned int>>>& variableInstances);

    void variableFirstInstanceTracker(const string& variable, const long unsigned int& index ,
                                      pair<vector<string>,vector<long unsigned int>>& variableFirstInstances);

    Relation* queryEvaluator(const Predicate& query);

public:
    Interpreter(){}
    void interpret(const DataLogProgram& program);
};


#endif //PROJECT2_PARSER_INTERPRETER_H
