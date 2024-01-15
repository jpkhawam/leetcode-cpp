#include <iostream>
#include <stack>
#include <cassert>

char get_matching_parenthesis(char closing_parenthesis);

bool valid_parentheses(const std::string &str) {
    std::stack<char> st{};
    for (auto current_char: str) {
        switch (current_char) {
            case '[':
            case '(':
            case '{':
                st.push(current_char);
                break;
            default:
                if (st.empty() || st.top() != get_matching_parenthesis(current_char)) {
                    return false;
                }
                st.pop();
        }
    }
    return st.empty();
}

char get_matching_parenthesis(const char closing_parenthesis) {
    switch (closing_parenthesis) {
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
        default:
            throw std::runtime_error("invalid character");
    }
}

int main() {
    const auto valid_str = "(())(){}";
    const auto invalid_str = "(()(])";
    assert(valid_parentheses(valid_str) == true);
    assert(valid_parentheses(invalid_str) == false);
    return 0;
}
