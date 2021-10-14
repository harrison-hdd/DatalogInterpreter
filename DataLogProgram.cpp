//
// Created by Hoan Do on 9/23/21.
//

#include "DataLogProgram.h"
string DataLogProgram::toString() const {
    ostringstream ss;
    ss << "Schemes(" << schemes.size() << "):\n";
    for(long unsigned int i = 0; i < schemes.size(); ++i){
        ss << "  " << schemes.at(i) << endl;
    }

    ss << "Facts(" << facts.size() << "):\n";
    for(long unsigned int i = 0; i < facts.size(); ++i){
        ss << "  " << facts.at(i) << ".\n";
    }

    ss << "Rules(" << rules.size() << "):\n";
    for(long unsigned int i = 0; i < rules.size(); ++i){
        ss << "  " << rules.at(i) << "\n";
    }

    ss << "Queries(" << queries.size() << "):\n";
    for(long unsigned int i = 0; i < queries.size(); ++i){
        ss << "  " << queries.at(i) << "?\n";
    }
    /*for(const auto & querie : queries){
        ss << "  " << querie << "?\n";
    }*/

    ss << "Domain(" << domain.size() << "):\n";
    for(auto i = domain.begin(); i != domain.end(); ++i){
        ss << "  " << *i << endl;
    }
    return ss.str();
}
void DataLogProgram::addScheme(Predicate newScheme) {
    schemes.push_back(newScheme);
}
void DataLogProgram::addFact(Predicate newFact) {
    facts.push_back(newFact);
    vector<Parameter> parameters = newFact.getParameters();
    for(long unsigned int i = 0; i < parameters.size(); ++i){
        domain.insert(parameters.at(i).toString());
    }
}
void DataLogProgram::addQuery(Predicate newQuery) {
    queries.push_back(newQuery);
}
void DataLogProgram::addRule(Rule newRule) {
    rules.push_back(newRule);
}