//
// Created by Hoan Do on 10/13/21.
//

#include "Interpreter.h"


void Interpreter::interpret(const DataLogProgram& program) {
    buildDatabase(program.getSchemes(), program.getFacts());
    evaluateQueries(program.getQueries());
}

/**databaseBuilder takes vectors of schemes and facts from a DataLogProgram to populate the data member database*/
void Interpreter::buildDatabase(const vector<Predicate>& schemes, const vector<Predicate>& facts){
    /**the first for loop creates new relations in database
       using a vector of schemes*/
    for(long unsigned int i = 0; i < schemes.size(); ++i){
        string ID = schemes.at(i).getID();
        /**ID is the name of a scheme, e.g., snap, cdh*/

        vector<Parameter> parameters = schemes.at(i).getParameters();
        /**parameters contains the attributes of the scheme, e.g., (S, N, A, P)*/

        Header header;
        for(long unsigned int j = 0; j < parameters.size(); ++j){
            header.addAttribute(parameters.at(j).toString());
        }

        Relation relation(ID, header);//create new empty relation using ID and header
        database.addNewPair(ID, relation); //add the relation above to data base
    }

    /**the second for loop populates relations created above
       with tuples derived from facts*/
    for(long unsigned int i = 0; i < facts.size(); ++i){
        string ID = facts.at(i).getID();
        /**ID is the name of a scheme, e.g., snap, cdh*/

        vector<Parameter> parameters = facts.at(i).getParameters();
        /**(vector<Parameter> parameters) contains the actual values of attributes*/

        Tuple tuple;
        for(long unsigned int j = 0; j < parameters.size(); ++j){
            tuple.addValue(parameters.at(j).toString());
        }
        database.addFact(ID, tuple);
    }
}

void Interpreter::evaluateQueries(const vector<Predicate> &queries) {
    for(long unsigned int i = 0; i < queries.size(); ++i){
        cout << queries.at(i) << "? ";

        if(!database.isInDatabase(queries.at(i).getID())){// if no scheme in the database has the same name as the query's name
            cout << "No scheme named \"" << queries.at(i).getID() << "\" was found!\n";
        }
        else {
            Relation *relation = queryEvaluator(queries.at(i));
            if (relation->empty()) cout << "No\n";
            else {
                cout << "Yes(" << relation->numTuple() << ")\n";
                if (!relation->getHeader().empty()) cout << *relation;// if relation has more than 0 column
            }
            delete relation;
        }
    }
}

Relation* Interpreter::queryEvaluator(const Predicate &query) {
    string ID = query.getID();

    Relation* relation = new Relation(database.getRelationByName(ID));

    Relation* oldRelation = relation;

    vector<Parameter> parameters = query.getParameters();

    /**the vector of pairs below keeps track of the variables with multiple instances within the same query,
     * e.g., variable A in the query ABC(A,B,A)?. The first element of each pair is a string containing
     * the variable's name (A in this example). The second element is a vector containing the index(es) at which
     * the variable's instances occur (e.g., {0,2}). The outer vector is updated with each variable
     * by the method variableTracker(...). The final outer vector looks like { ( A, {0,2} ), ( B, {1} ) }.
     * */
    vector<pair<string, vector<long unsigned int>>> variableInstances;

    //pair<vector<string>, vector<vector<long unsigned int>>> variableInstances;

    pair<vector<string>,vector<long unsigned int>> variableFirstInstances; // to be passed into Relation::project

    for(long unsigned int i = 0; i < parameters.size(); ++i){
        /**if the parameter is a constant (i.e. a STRING token)*/
        if(parameters.at(i).isConstant()){

            /**select the rows with the same constant at i-th column.*/
            relation = relation->select(i, parameters.at(i).toString(), relation);


            delete oldRelation;
            oldRelation = nullptr;
            oldRelation = relation;
        }

        /**if the parameter is a variable*/
        else{
            /**track the new instance of the variable using variableTracker(...) and variableFirstInstanceTracker(...)*/
            variableTracker(parameters.at(i).toString(), i, variableInstances);
            variableFirstInstanceTracker(parameters.at(i).toString(), i, variableFirstInstances);

            /**update variable's corresponding header column to variable's name*/
            relation = relation->rename(i, parameters.at(i).toString(), relation);

            delete oldRelation;
            oldRelation = nullptr;
            oldRelation = relation;
        }
    }

    /***/
    relation = relation->select(variableInstances, relation);
    delete oldRelation;
    oldRelation = nullptr;
    oldRelation = relation;

    relation = relation->project(variableFirstInstances.second, relation);
    delete oldRelation;
    oldRelation = nullptr;

    return relation;
}

void Interpreter::variableTracker(const string& variable,
                                  const long unsigned int& index ,
                                  vector<pair<string,vector<long unsigned int>>>& variableInstances){

    for(long unsigned int i = 0; i < variableInstances.size(); ++i){//iterate thru the big vector out side
        if(variableInstances.at(i).first == variable){//if variable already exist
            variableInstances.at(i).second.push_back(index); //add new index where it appears to its corresponding vector
            return;
        }
    }

    //if variable is not found
    pair<string,vector<long unsigned int>> newPair; //create new pair
    newPair.first = variable; //with variable's name
    newPair.second.push_back(index); //and its first index
    variableInstances.push_back(newPair); //add the new pair to the big vector
}

void Interpreter::variableFirstInstanceTracker(const string& variable, const long unsigned int& index ,
                                  pair<vector<string>,vector<long unsigned int>>& variableFirstInstances){
    for(long unsigned int i = 0; i < variableFirstInstances.first.size(); ++i){
        if(variableFirstInstances.first.at(i) == variable){//if variable already exists
            return;//then do nothing
        }
    }
    variableFirstInstances.first.push_back(variable);
    variableFirstInstances.second.push_back(index);
}


