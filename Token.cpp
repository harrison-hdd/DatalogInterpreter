#include "Token.h"

Token::Token(TokenType type, string description, int line) {
    this->type = type;
    this->description = description;
    this->line = line;
}

string Token::toString() const{
    stringstream ss;
    ss << "(";
    if(type == TokenType::COLON)            ss << "COLON,\"";
    else if(type == TokenType::COMMA)       ss << "COMMA,\"";
    else if(type == TokenType::PERIOD)      ss << "PERIOD,\"";
    else if(type == TokenType::Q_MARK)      ss << "Q_MARK,\"";
    else if(type == TokenType::LEFT_PAREN)  ss << "LEFT_PAREN,\"";
    else if(type == TokenType::RIGHT_PAREN) ss << "RIGHT_PAREN,\"";
    else if(type == TokenType::Q_MARK)      ss << "Q_MARK,\"";
    else if(type == TokenType::MULTIPLY)    ss << "MULTIPLY,\"";
    else if(type == TokenType::ADD)         ss << "ADD,\"";
    else if(type == TokenType::COLON_DASH)  ss << "COLON_DASH,\"";
    else if(type == TokenType::SCHEMES)     ss << "SCHEMES,\"";
    else if(type == TokenType::FACTS)       ss << "FACTS,\"";
    else if(type == TokenType::QUERIES)     ss << "QUERIES,\"";
    else if(type == TokenType::RULES)       ss << "RULES,\"";
    else if(type == TokenType::STRING)      ss << "STRING,\"";
    else if(type == TokenType::COMMENT)     ss << "COMMENT,\"";
    else if(type == TokenType::ID)          ss << "ID,\"";
    else if(type == TokenType::END_OF_FILE) ss << "EOF,\"";
    else if(type == TokenType::UNDEFINED)   ss << "UNDEFINED,\"";
    ss << description << "\"," << line << ")\n";
    return ss.str();
}


