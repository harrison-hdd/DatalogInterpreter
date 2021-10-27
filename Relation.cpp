//
// Created by Hoan Do on 10/13/21.
//

#include "Relation.h"

string Relation::toString() const{
    ostringstream oss;
    for(auto i = tupleSet.begin(); i != tupleSet.end(); ++i){
        Tuple t = *i;
        oss << "  ";
        for(long unsigned int j = 0; j < header.size(); ++j){
            oss << header.at(j) << "=" << t.at(j);
            if(j == header.size() - 1){
                oss << endl;
                break;
            }
            oss << ", ";
        }
    }

    return oss.str();
}

Relation* Relation::select(const long unsigned int& attributeIndex, const string& value, Relation* inputRelation){
    Relation* outputRelation = new Relation(inputRelation->getName(), inputRelation->getHeader());
    for(auto i = inputRelation->tupleSet.begin(); i != inputRelation->tupleSet.end(); ++i){
        Tuple t = *i;
        if(t.at(attributeIndex) == value){
            outputRelation->addTuple(t);
        }
    }
    return outputRelation;
}

Relation* Relation::select(const vector<pair<string,vector<long unsigned int>>>& variableInstances, Relation* inputRelation){
    Relation* outputRelation = new Relation(inputRelation->getName(), inputRelation->getHeader());


    vector<vector<long unsigned int>> duplicateIndexes;//store variables with more than 1 instance and their indexes
    for(long unsigned int i = 0; i < variableInstances.size(); ++i){
        if(variableInstances.at(i).second.size() > 1){ //if variable has more than 1 instance
            duplicateIndexes.push_back(variableInstances.at(i).second); //add the indexes of the instances
        }
    }

    /**if there is no duplicate variable, simply the return outputRelation with the original tupleSet from inputRelation*/
    if (duplicateIndexes.empty()){
        outputRelation->tupleSet = inputRelation->tupleSet;
        return outputRelation;
    }


    auto _begin = inputRelation->tupleSet.begin();
    auto _end = inputRelation->tupleSet.end();
    for(auto i = _begin; i != _end; ++i){
        Tuple t = *i;
        bool valuesMatched = true;
        for (long unsigned int j = 0; j < duplicateIndexes.size(); ++j){
            vector<long unsigned int> *instances = &duplicateIndexes.at(j);

            for(long unsigned int k = 0; k < instances->size(); ++k){
                if(t.at(0) != t.at(instances->at(k))){
                    valuesMatched = false;
                    break;
                }
            }
            if(!valuesMatched) break;
        }
        if(valuesMatched) outputRelation->tupleSet.insert(t);
    }
    return outputRelation;

}

Relation* Relation::rename(const long unsigned int& attributeIndex, const string& value, Relation* inputRelation) {
    Relation* outputRelation = new Relation(inputRelation->getName(), inputRelation->getHeader());
    outputRelation->tupleSet = inputRelation->tupleSet;
    outputRelation->header.changeAttributeName(attributeIndex, value);
    return outputRelation;
}

Relation* Relation::project(const vector<long unsigned int>& attributeIndexes, Relation* inputRelation){
    Relation* outputRelation = new Relation(inputRelation->getName());

    for(long unsigned int i = 0; i < attributeIndexes.size(); ++i){//creates new header
        outputRelation->header.addAttribute(inputRelation->header.at(attributeIndexes.at(i)));
    }

    auto _begin = inputRelation->tupleSet.begin();
    auto _end = inputRelation->tupleSet.end();
    for(auto i = _begin; i != _end; ++i){
        Tuple oldTuple = *i;
        Tuple newTuple;
        for(long unsigned int j = 0; j < attributeIndexes.size(); ++j){
            newTuple.addValue(oldTuple.at(attributeIndexes.at(j)));
        }
        outputRelation->addTuple(newTuple);
    }
    return outputRelation;
}

