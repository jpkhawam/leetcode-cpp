#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
private:
    char getMatchingCharacter(char c) {
        switch (c) {
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';
            default: return ' ';
        }
    }

public:
    bool isValid(string s) {
        stack<char> st;
        for (char c: s)
            if (!st.empty() && getMatchingCharacter(c) == st.top())
                st.pop();
            else
                st.push(c);
        return st.empty();
    }
};

