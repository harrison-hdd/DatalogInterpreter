//
// Created by Hoan Do on 9/23/21.
//

#ifndef PROJECT2_PARSER_PARAMETER_H
#define PROJECT2_PARSER_PARAMETER_H
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Parameter{
private:
    string parameter;
public:
    Parameter(){}
    Parameter(string parameter): parameter(parameter){}
    //~Parameter(){}
    string toString() const{
        return parameter;
    }
    friend ostream& operator<<(ostream& os, const Parameter& p){
        return os << p.toString();
    }
    bool isConstant(){
        if(parameter.at(0) == '\'') return true;
        return false;
    }
};


#endif //PROJECT2_PARSER_PARAMETER_H
