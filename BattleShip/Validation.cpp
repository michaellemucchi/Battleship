#include "Validation.h"

bool is_a_number(std::string input) {
    for (int i = 0; i < input.size(); i++) {
        if (!isdigit(input.at(i))) {
            return false;
        }
    }
    return true;
}

bool is_a_number_or_whitespace(std::string input) {
    for (int i = 0; i < input.size(); i++) {
        if (!isdigit(input.at(i)) && input.at(i) != ' ') {
            return false;
        }
    }
    return true;
}