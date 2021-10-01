#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <sstream>
using namespace std;

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END_OF_FILE
};

class Token
{
private:
    TokenType type;
    string description;
    int line;
public:
    Token(TokenType type, std::string description, int line);
    string toString() const;
    TokenType getType() const {return type;};
    string getDescription() const {return description;}
    friend ostream& operator<<(ostream& os, Token& t){
        return os << t.toString();
    }

};

#endif // TOKEN_H

