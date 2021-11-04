cmake_minimum_required(VERSION 3.17)
project(Project2_Parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project2_Parser main.cpp
        1_Lexer/Automata/ColonAutomaton.h
        1_Lexer/Automata/ColonAutomaton.cpp
        1_Lexer/Automata/ColonDashAutomaton.h
        1_Lexer/Automata/ColonDashAutomaton.cpp
        1_Lexer/Lexer.h
        1_Lexer/Lexer.cpp
        1_Lexer/Automata/Token.h
        1_Lexer/Automata/Token.cpp
        1_Lexer/Automata/LineCommentAutomaton.cpp
        1_Lexer/Automata/LineCommentAutomaton.h
        1_Lexer/Automata/BlockCommentAutomaton.cpp
        1_Lexer/Automata/BlockCommentAutomaton.h
        1_Lexer/Automata/SchemesAutomaton.cpp 1_Lexer/Automata/SchemesAutomaton.h 1_Lexer/Automata/FactsAutomaton.cpp 1_Lexer/Automata/FactsAutomaton.h 1_Lexer/Automata/QueriesAutomaton.cpp 1_Lexer/Automata/QueriesAutomaton.h 1_Lexer/Automata/RulesAutomaton.cpp 1_Lexer/Automata/RulesAutomaton.h 1_Lexer/Automata/StringAutomaton.cpp 1_Lexer/Automata/StringAutomaton.h 1_Lexer/Automata/IDAutomaton.cpp 1_Lexer/Automata/IDAutomaton.h 1_Lexer/Automata/PeriodAutomaton.cpp 1_Lexer/Automata/PeriodAutomaton.h 1_Lexer/Automata/Q_MarkAutomaton.cpp 1_Lexer/Automata/Q_MarkAutomaton.h 1_Lexer/Automata/MultiplyAutomaton.cpp 1_Lexer/Automata/MultiplyAutomaton.h 1_Lexer/Automata/AddAutomaton.cpp 1_Lexer/Automata/AddAutomaton.h 1_Lexer/Automata/LeftParenAutomaton.cpp 1_Lexer/Automata/LeftParenAutomaton.h 1_Lexer/Automata/RightParenAutomaton.cpp 1_Lexer/Automata/RightParenAutomaton.h 1_Lexer/Automata/CommaAutomaton.cpp 1_Lexer/Automata/CommaAutomaton.h 2_Parser/Parser.cpp 2_Parser/Parser.h 2_Parser/Predicate.cpp 2_Parser/Predicate.h 2_Parser/DataLogProgram.cpp 2_Parser/DataLogProgram.h 2_Parser/Parameter.h 2_Parser/Rule.cpp 2_Parser/Rule.h 3_Interpreter/Tuple.h 3_Interpreter/Header.h 3_Interpreter/Relation.cpp 3_Interpreter/Relation.h 3_Interpreter/Database.cpp 3_Interpreter/Database.h 3_Interpreter/Interpreter.cpp 3_Interpreter/Interpreter.h)