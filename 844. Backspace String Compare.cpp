#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stack_s;
        stack<char> stack_t;
        for (auto c: s) {
            if (c == '#') {
                if (!stack_s.empty()) stack_s.pop();
            } else stack_s.push(c);
        }
        for (auto c: t) {
            if (c == '#') {
                if (!stack_t.empty()) stack_t.pop();
            } else stack_t.push(c);
        }
        if (stack_s.size() != stack_t.size()) return false;
        else {
            while (!stack_s.empty()) {
                char char_s = stack_s.top();
                char char_t = stack_t.top();
                if (char_s != char_t) return false;
                stack_s.pop();
                stack_t.pop();
            }
        }
        return true;
    }
};
