#ifndef AUTOMATON_H
#define AUTOMATON_H
#include "Token.h"
#include <string>

class Automaton
{
protected:
    int inputRead = 0;
    int newLines = 0;
    long unsigned int index = 0;
    TokenType type;

public:
    // Default constructor -- since we have a constructor that takes a parameter,
    //   the compiler will autogenerate a default constructor if not explicit.
    Automaton() : type(TokenType::UNDEFINED){}

    Automaton(TokenType type) { this->type = type; }
    virtual ~Automaton(){}

    // Start the automaton and return the number of characters read
    //   read == 0 indicates the input was rejected
    //   read  > 0 indicates the input was accepted
    int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }

    // Every subclass must define this method
    virtual void S0(const std::string& input) = 0;

    void Serr() {
        // Indicate the input was rejected
        inputRead = 0;
    }

    virtual Token* CreateToken(std::string input, int lineNumber) { return new Token(type, input, lineNumber); }

    int NewLinesRead() const { return newLines; }

    TokenType getType() const { return type;}
};

#endif // AUTOMATON_H

