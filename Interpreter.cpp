//
// Created by Hoan Do on 10/13/21.
//

#include "Interpreter.h"
void Interpreter::interpret(const DataLogProgram& program) {
    databaseBuilder(program.getSchemes(), program.getFacts());

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
        database.addFacts(ID, tuple);
    }
}

void Interpreter::queryHandler(const vector<Predicate>& queries){

}

