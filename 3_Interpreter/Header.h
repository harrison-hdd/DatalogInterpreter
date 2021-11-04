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
    void addAttribute(const string& newAttribute){
        attributes.push_back(newAttribute);
    }

    void changeAttributeName(const long unsigned int& attributeIndex, string value){
        attributes.at(attributeIndex) = value;
    }

    string at(long unsigned int i) const{
        return attributes.at(i);
    }

    long unsigned int size() const{ return attributes.size();}

    bool empty() const{ return attributes.empty(); }
};


#endif //PROJECT2_PARSER_HEADER_H
