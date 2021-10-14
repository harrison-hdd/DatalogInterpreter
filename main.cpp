#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();
    ifstream inFS(argv[1]);
    if(!inFS.is_open()){
        cout << "Failed to open input file\n";
        return 1;
    }
    ostringstream oss;

    //the next loop converts the input file into a string
    do{
        string inputLine;
        getline(inFS, inputLine);
        oss << inputLine << endl;
    }while(!inFS.eof());

    string input = oss.str();
    input.erase(input.size() - 1, input.size()); //gets rid of the extra \n at the end
    lexer->Run(input);


    /**start of parser code*/
    vector<Token*> tokens = lexer->getTokenList();
    vector<Token*> tokensNoComments;
    inFS.close();


    for(long unsigned int i = 0; i < tokens.size(); ++i){
        if(tokens.at(i)->getType() != TokenType::COMMENT)
            tokensNoComments.push_back(tokens.at(i));
    }
    Parser parser;
    parser.parse(tokensNoComments);
    //if(!parser.hasError()) cout << parser;


    /**start of interpreter code*/
    Interpreter interpreter;
    interpreter.interpret(parser.getProgram());

    delete lexer;
    return 0;
}
