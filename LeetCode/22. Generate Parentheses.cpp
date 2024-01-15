#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    vector<string> output;

    void backtrack(string curr, int open, int close, int max) {
        if (curr.length() == max * 2) {
            output.push_back(curr);
            return;
        }
        if (open < max) {
            curr.push_back('(');
            backtrack(curr, open + 1, close, max);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            backtrack(curr, open, close + 1, max);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        backtrack(*new string, 0, 0, n);
        return output;
    }
};

