//
// Created by Hoan Do on 9/23/21.
//

#include "Parser.h"
string Parser::toString() const{
    ostringstream ss;
    ss << "Success!\n";
    ss << program;
    return ss.str();
}
void Parser::parse(vector<Token*>& tokens){
    try{
        parseDatalog(tokens);
    } catch (Token* t) {
        cout << "Failure!\n"
             << "  " << *t; //output token as string
        failed = true;
        return;
    }
}

void Parser::parseDatalog(vector<Token*>& tokens){
    matcher(tokens.at(index), TokenType::SCHEMES);
    matcher(tokens.at(index), TokenType::COLON);
    parseScheme(tokens); //a Datalog program has at least 1 scheme
    parseSchemeList(tokens);

    matcher(tokens.at(index), TokenType::FACTS);
    matcher(tokens.at(index), TokenType::COLON);
    parseFactList(tokens);

    matcher(tokens.at(index), TokenType::RULES);
    matcher(tokens.at(index), TokenType::COLON);
    parseRuleList(tokens);

    matcher(tokens.at(index), TokenType::QUERIES);
    matcher(tokens.at(index), TokenType::COLON);
    parseQuery(tokens); //a Datalog program has at least 1 query
    parseQueryList(tokens);

    matcher(tokens.at(index), TokenType::END_OF_FILE);

}
void Parser::parseScheme(vector<Token*>& tokens){
    currPredicate.reset(); //reset currScheme before parsing a new one
    matcher(tokens.at(index), TokenType::ID);

    /**ID is the description of the last token since matcher() already incremented the index*/
    string ID = tokens.at(index - 1)->getDescription();
    currPredicate.setID(ID);//set ID with the string above

    matcher(tokens.at(index), TokenType::LEFT_PAREN);
    matcher(tokens.at(index), TokenType::ID);

    /**push back the first new parameter object set using the description of the last token
     * to vector<Parameter> of the currScheme object*/
    currPredicate.addParameter(Parameter(tokens.at(index - 1)->getDescription()));

    parseIDList(tokens);
    matcher(tokens.at(index), TokenType::RIGHT_PAREN);
    program.addScheme(currPredicate);
}
void Parser::parseSchemeList(vector<Token*> &tokens){
    if(tokens.at(index)->getType() == TokenType::FACTS){
        return;
    }
    parseScheme(tokens);
    parseSchemeList(tokens);
}
void Parser::parseFact(vector<Token *> &tokens) {
    currPredicate.reset(); //reset currFact before parsing a new one
    matcher(tokens.at(index), TokenType::ID);

    /**ID is the description of the last token since matcher() already incremented the index*/
    string ID = tokens.at(index - 1)->getDescription();
    currPredicate.setID(ID);

    matcher(tokens.at(index), TokenType::LEFT_PAREN);
    matcher(tokens.at(index), TokenType::STRING);
    /**push back the first new parameter object set using the description of the last token
     * to vector<Parameter> of the currFact object*/
    currPredicate.addParameter(Parameter(tokens.at(index - 1)->getDescription()));

    parseStringList(tokens);
    matcher(tokens.at(index), TokenType::RIGHT_PAREN);
    matcher(tokens.at(index), TokenType::PERIOD);

    program.addFact(currPredicate);
}
void Parser::parseFactList(vector<Token*> &tokens){
    if(tokens.at(index)->getType() == TokenType::RULES){
        return;
    }
    parseFact(tokens);
    parseFactList(tokens);
}
void Parser::parseRule(vector<Token *> &tokens) {
    currRule.reset();
    parseHeadPredicate(tokens);
    matcher(tokens.at(index), TokenType::COLON_DASH);

    parsePredicate(tokens);
    currRule.addPredicate(currPredicate);

    parsePredicateList(tokens);
    matcher(tokens.at(index), TokenType::PERIOD);

    program.addRule(currRule);
}
void Parser::parseRuleList(vector<Token *> &tokens) {
    if(tokens.at(index)->getType() == TokenType::QUERIES){
        return;
    }
    parseRule(tokens);
    parseRuleList(tokens);
}
void Parser::parseQuery(vector<Token*> &tokens) {
    currPredicate.reset();
    parsePredicate(tokens);
    matcher(tokens.at(index), TokenType::Q_MARK);
    program.addQuery(currPredicate);
}
void Parser::parseQueryList(vector<Token*>& tokens) {
    if(tokens.at(index)->getType() == TokenType::END_OF_FILE){
            return;
    }
    parseQuery(tokens);
    parseQueryList(tokens);
}



void Parser::parseIDList(vector<Token *> &tokens) {
    if(tokens.at(index)->getType() == TokenType::RIGHT_PAREN){//idList->lambda
        return;
    }
    matcher(tokens.at(index), TokenType::COMMA);

    matcher(tokens.at(index), TokenType::ID);
    /**push back the first new parameter object set using the description of the last token
     * to vector<Parameter> of the currScheme object*/
    currPredicate.addParameter(Parameter(tokens.at(index - 1)->getDescription()));

    parseIDList(tokens);//recursion
}
void Parser::parseStringList(vector<Token *> &tokens) {
    if(tokens.at(index)->getType() == TokenType::RIGHT_PAREN){//stringList->lambda
        return;
    }
    matcher(tokens.at(index), TokenType::COMMA);

    matcher(tokens.at(index), TokenType::STRING);
    /**push back the first new parameter object set using the description of the last token
     * to vector<Parameter> of the currPredicate object*/
    currPredicate.addParameter(Parameter(tokens.at(index - 1)->getDescription()));

    parseStringList(tokens);
}

void Parser::parseParameterList(vector<Token*>& tokens) {
    if(tokens.at(index)->getType() == TokenType::RIGHT_PAREN){//parameterList->lambda
        return;
    }
    matcher(tokens.at(index), TokenType::COMMA);
    parseParameter(tokens);
    parseParameterList(tokens);

}
void Parser::parsePredicateList(vector<Token *> &tokens){
    if(tokens.at(index)->getType() == TokenType::PERIOD){//parameterList->lambda
        return;
    }
    matcher(tokens.at(index), TokenType::COMMA);
    parsePredicate(tokens);
    currRule.addPredicate(currPredicate);
    parsePredicateList(tokens);
}
void Parser::parsePredicate(vector<Token*>& tokens) {
    currPredicate.reset();
    matcher(tokens.at(index), TokenType::ID);
    currPredicate.setID(tokens.at(index - 1)->getDescription());

    matcher(tokens.at(index), TokenType::LEFT_PAREN);
    parseParameter(tokens);
    parseParameterList(tokens);
    matcher(tokens.at(index), TokenType::RIGHT_PAREN);
}

void Parser::parseHeadPredicate(vector<Token*>& tokens){// headPredicate is stored in currPredicate
    currPredicate.reset();//reset currPredicate before using it to store a new predicate

    matcher(tokens.at(index), TokenType::ID);

    currPredicate.setID(tokens.at(index - 1)->getDescription());

    matcher(tokens.at(index), TokenType::LEFT_PAREN);

    matcher(tokens.at(index), TokenType::ID);
    currPredicate.addParameter(tokens.at(index - 1)->getDescription());

    parseIDList(tokens);
    matcher(tokens.at(index), TokenType::RIGHT_PAREN);
    currRule.setHeadPredicate(currPredicate);
}

void Parser::parseParameter(vector<Token *> &tokens){
//    if(tokens.at(index)->getType() == TokenType::STRING
//    || tokens.at(index)->getType() == TokenType::ID){
//        ++index;
        /**push back the first new parameter object, set using the description of the last token,
     * to vector<Parameter> of the currPredicate object*/
//        currPredicate.addParameter(tokens.at(index - 1)->getDescription());
//    }else throw tokens.at(index);
    if(tokens.at(index)->getType() == TokenType::STRING){
        matcher(tokens.at(index), TokenType::STRING);
        currPredicate.addParameter(tokens.at(index - 1)->getDescription());
    }
    else if(tokens.at(index)->getType() == TokenType::ID){
        matcher(tokens.at(index), TokenType::ID);
        currPredicate.addParameter(tokens.at(index - 1)->getDescription());
    }
}
void Parser::matcher(Token*& input, TokenType matchType){
    if(input->getType() == matchType) {
        ++index;
    } else throw input;
}
