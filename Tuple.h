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

    bool operator<(const Tuple& rhs) const{
        return (*this).values < rhs.values;
    }
    void addValue(string value){
        values.push_back(value);
    }
};


#endif //PROJECT2_PARSER_TUPLE_H
