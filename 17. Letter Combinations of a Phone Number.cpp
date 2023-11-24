#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    vector<string> output;
    vector<string> letters;

    void backtrack(string &digits, int i, string currentString) {
        if (i == digits.size()) {
            output.push_back(currentString);
            return;
        }
        string currentCharacter;
        currentCharacter += digits[i];
        for (auto c: letters[std::stoi(currentCharacter)]) {
            currentString.push_back(c);
            backtrack(digits, i + 1, currentString);
            currentString.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return output;
        letters = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, 0, *new string);
        return output;
    }
};

