//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_TUPLE_H
#define PROJECT2_PARSER_TUPLE_H
#include <vector>
#include <string>
using namespace std;

class Tuple {
private:

    vector<string> values;

public:

    Tuple(){}

    Tuple(const Tuple& t){ *this = t; }

    bool operator<(const Tuple& rhs) const{
        return (*this).values < rhs.values;
    }

    long unsigned int size() const{ return values.size(); }

    void addValue(string value){
        values.push_back(value);
    }

    string at(long unsigned int index) const{
        return values.at(index);
    }
};


#endif //PROJECT2_PARSER_TUPLE_H
