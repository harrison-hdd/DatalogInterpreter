//
// Created by Hoan Do on 9/23/21.
//

#include "Predicate.h"
string Predicate::toString() const{
    ostringstream ss;
    ss << ID << "(";
    for(long unsigned int i = 0; i < parameters.size(); ++i){
        ss << parameters.at(i);
        if(i == parameters.size() - 1){
            ss << ")";
            break;
        }
        ss << ",";
    }
    return ss.str();
}
