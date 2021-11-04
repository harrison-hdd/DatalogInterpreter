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
                if(t.at(instances->at(0)) != t.at(instances->at(k))){
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
//    Relation* outputRelation = new Relation(inputRelation->getName(), inputRelation->getHeader());
//    outputRelation->tupleSet = inputRelation->tupleSet;
    Relation* outputRelation = new Relation(*inputRelation);
    outputRelation->header.changeAttributeName(attributeIndex, value);
    return outputRelation;
}

Relation* Relation::project(const vector<long unsigned int>& attributeIndexes, Relation* inputRelation){
    Relation* outputRelation = new Relation(inputRelation->getName());

    for(long unsigned int i = 0; i < attributeIndexes.size(); ++i){//creates new header
        outputRelation->header.addAttribute(inputRelation->header.at(attributeIndexes.at(i)));
//        long unsigned int currIndex = attributeIndexes.at(i);
//        string currAttribute = inputRelation->header.at(currIndex);
//        outputRelation->header.addAttribute(currAttribute);

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

Relation* Relation::naturalJoin(Relation* A, Relation* B){

    Relation* outputRelation = new Relation();

    /**find the indexes of the common header attributes of relations A and B*/
    pair<vector<long unsigned int>,vector<long unsigned int>> matchedIndexes;

    for(long unsigned int i = 0; i < A->header.size(); ++i){
        for(long unsigned int j = 0; j < B->header.size(); ++j){
            if(A->header.at(i) == B->header.at(j)){
                /**emplace_back is supposed to be better than push_back when it comes to adding objects.
                 * Read more here:
                 * https://yasenh.github.io/post/cpp-diary-1-emplace_back/
                 * */
                matchedIndexes.first.push_back(i);
                matchedIndexes.second.push_back(j);
                break;
            }
        }
    }
    /**end of finding common attributes' indexes*/

    outputRelation->header = naturalJoinHelper_joinHeaders(A->header, B->header, matchedIndexes);

    for(auto i = A->tupleSet.begin(); i != A->tupleSet.end(); ++i){
        Tuple t_A = *i;
        for (auto j = B->tupleSet.begin(); j != B->tupleSet.end(); ++j){
            Tuple t_B = *j;

            bool tuplesJoinable = naturalJoinHelper_checkIfTuplesAreJoinable(t_A, t_B, matchedIndexes);

            if(tuplesJoinable){
                Tuple newTuple = naturalJoinHelper_joinTuples(t_A, t_B, matchedIndexes);
                outputRelation->addTuple(newTuple);
            }
        }
    }

    return outputRelation;
}

Tuple Relation::naturalJoinHelper_joinTuples(const Tuple &t_A, const Tuple &t_B,
                                                    pair<vector<unsigned long>, vector<unsigned long>>& matchedIndexes) {
    Tuple outputTuple(t_A);

    for(long unsigned int i = 0; i < t_B.size(); ++i){
        bool isADuplicate = false;
        for(long unsigned int j = 0; j < matchedIndexes.second.size(); ++j) {
            long unsigned int currDuplicateIndexOfB = matchedIndexes.second.at(j);
            if(i == currDuplicateIndexOfB){
                isADuplicate = true;
                break;
            }
        }
        if(!isADuplicate){
            outputTuple.addValue(t_B.at(i));
        }
    }

    return outputTuple;
}

Header Relation::naturalJoinHelper_joinHeaders(const Header &h_A, const Header h_B,
                                               pair<vector<unsigned long>, vector<unsigned long>> &matchedIndexes) {
    Header outputHeader(h_A);

    for(long unsigned int i = 0; i < h_B.size(); ++i){
        bool isADuplicate = false;
        for(long unsigned int j = 0; j < matchedIndexes.second.size(); ++j) {
            long unsigned int currDuplicateIndexOfB = matchedIndexes.second.at(j);
            if(i == currDuplicateIndexOfB){
                isADuplicate = true;
                break;
            }
        }
        if(!isADuplicate){
            outputHeader.addAttribute(h_B.at(i));
        }
    }

    return outputHeader;
}

bool Relation::naturalJoinHelper_checkIfTuplesAreJoinable(const Tuple &t_A, const Tuple &t_B,
                                                    pair<vector<unsigned long>, vector<unsigned long>> &matchedIndexes) {
    for(long unsigned int k = 0; k < matchedIndexes.first.size(); ++k){
        long unsigned int currIndexA = matchedIndexes.first.at(k);
        long unsigned int currIndexB = matchedIndexes.second.at(k);
        if(t_A.at(currIndexA) != t_B.at(currIndexB)){
            return false;
        }
    }
    return true;
}

long unsigned int Relation::unionizeRelations(Relation *newRelation, Relation *existingRelation) {

    Header header = newRelation->header;

    long unsigned int numNewTuples = 0;

    for(auto i = newRelation->tupleSet.begin(); i != newRelation->tupleSet.end(); ++i){
        if(existingRelation->tupleSet.insert(*i).second) {
            ++numNewTuples;
            cout << unionizeRelationsHelper_newTupleString(header, *i);
        }
    }

    return numNewTuples;
}

string Relation::unionizeRelationsHelper_newTupleString(const Header &header, const Tuple &tuple) {
    ostringstream oss;
    oss << "  ";
    for(long unsigned int j = 0; j < header.size(); ++j){
        oss << header.at(j) << "=" << tuple.at(j);
        if(j == header.size() - 1){
            oss << endl;
            break;
        }
        oss << ", ";
    }
    return oss.str();
}