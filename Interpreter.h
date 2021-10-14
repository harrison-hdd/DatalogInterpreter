//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_INTERPRETER_H
#define PROJECT2_PARSER_INTERPRETER_H
#include "Database.h"
#include "DataLogProgram.h"
class Interpreter {
private:
    Database database;

    void databaseBuilder(const vector<Predicate>& schemes, const vector<Predicate>& facts);
    void queryHandler(const vector<Predicate>& queries);

public:
    Interpreter(){}

    void interpret(const DataLogProgram& program);


};


#endif //PROJECT2_PARSER_INTERPRETER_H
