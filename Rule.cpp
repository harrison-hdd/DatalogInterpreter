//
// Created by Hoan Do on 9/23/21.
//

#include "Rule.h"
string Rule::toString() const {
    ostringstream ss;
    ss << headPredicate << " :- ";
    for (long unsigned int i = 0; i < predicateList.size(); ++i){
        ss << predicateList.at(i);
        if (i == predicateList.size() - 1){
            ss << ".";
            break;
        }
        ss << ",";
    }
    return ss.str();
}
