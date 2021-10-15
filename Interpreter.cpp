//
// Created by Hoan Do on 10/13/21.
//

#include "Interpreter.h"
void Interpreter::interpret(const DataLogProgram& program) {
    databaseBuilder(program.getSchemes(), program.getFacts());
    queryHandler(program.getQueries());
}

void Interpreter::databaseBuilder(const vector<Predicate>& schemes, const vector<Predicate>& facts){
    /**the first for loop creates new relations in database
       using a vector of schemes*/
    for(auto i = 0; i < schemes.size(); ++i){
        string ID = schemes.at(i).getID();
        /**ID is the name of a scheme, e.g., snap, cdh*/

        vector<Parameter> parameters = schemes.at(i).getParameters();
        /**parameters contains the attributes of the scheme, e.g., (S, N, A, P)*/

        Header header;
        for(auto j = 0; j < parameters.size(); ++j){
            header.addAttribute(parameters.at(j).toString());
        }
        Relation relation(ID, header);
        database.addNewPair(ID, relation);
    }

    /**the second for loop populates relations created above
       with tuples derived from facts*/
    for(auto i = 0; i < facts.size(); ++i){
        string ID = facts.at(i).getID();
        /**ID is the name of a scheme, e.g., snap, cdh*/

        vector<Parameter> parameters = facts.at(i).getParameters();
        /**(vector<Parameter> parameters) contains the actual values of attributes*/

        Tuple tuple;
        for(auto j = 0; j < parameters.size(); ++j){
            tuple.addValue(parameters.at(j).toString());
        }
        database.addFact(ID, tuple);
    }
}

void Interpreter::queryHandler(const vector<Predicate>& queries){
    for(auto i = 0; i < queries.size(); ++i){
        cout << queries.at(i) << "?" << endl;
        queryEvaluator(queries.at(i));
    }
}
Relation* Interpreter::queryEvaluator(const Predicate &query) {
    string ID = query.getID();
    Relation relation = database.getRelationByName(ID);
    vector<Parameter> parameters = query.getParameters();
    for(auto i = 0; i < parameters.size(); ++i){
        if(parameters.at(i).toString().at(0) == '\''){ //if the parameter is a string, i.e., starting with '
            relation = relation.select(i, parameters.at(i).toString());
        }
        else{

        }
    }
    return &relation;
}


