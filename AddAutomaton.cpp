//
// Created by Hoan Do on 9/15/21.
//

#include "AddAutomaton.h"
void AddAutomaton::S0(const std::string& input) {
    if (input[index] == '+') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
