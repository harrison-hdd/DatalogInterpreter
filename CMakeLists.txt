cmake_minimum_required(VERSION 3.17)
project(Project2_Parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project2_Parser main.cpp
        ColonAutomaton.h
        ColonAutomaton.cpp
        ColonDashAutomaton.h
        ColonDashAutomaton.cpp
        Lexer.h
        Lexer.cpp
        Token.h
        Token.cpp
        LineCommentAutomaton.cpp
        LineCommentAutomaton.h
        BlockCommentAutomaton.cpp
        BlockCommentAutomaton.h
        SchemesAutomaton.cpp SchemesAutomaton.h FactsAutomaton.cpp FactsAutomaton.h QueriesAutomaton.cpp QueriesAutomaton.h RulesAutomaton.cpp RulesAutomaton.h StringAutomaton.cpp StringAutomaton.h IDAutomaton.cpp IDAutomaton.h PeriodAutomaton.cpp PeriodAutomaton.h Q_MarkAutomaton.cpp Q_MarkAutomaton.h MultiplyAutomaton.cpp MultiplyAutomaton.h AddAutomaton.cpp AddAutomaton.h LeftParenAutomaton.cpp LeftParenAutomaton.h RightParenAutomaton.cpp RightParenAutomaton.h CommaAutomaton.cpp CommaAutomaton.h Parser.cpp Parser.h Predicate.cpp Predicate.h DataLogProgram.cpp DataLogProgram.h Parameter.h Rule.cpp Rule.h Tuple.cpp Tuple.h Header.cpp Header.h Relation.cpp Relation.h Database.cpp Database.h Interpreter.cpp Interpreter.h)