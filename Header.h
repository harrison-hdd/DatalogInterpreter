//
// Created by Hoan Do on 10/13/21.
//

#ifndef PROJECT2_PARSER_HEADER_H
#define PROJECT2_PARSER_HEADER_H
#include <vector>
#include <string>

using namespace std;

class Header {
private:
    vector<string> attributes;
public:
    //Header(const vector<string>& attributes): attributes(attributes){}
    void addAttribute(string newAttribute){
        attributes.push_back(newAttribute);
    }

};


#endif //PROJECT2_PARSER_HEADER_H
