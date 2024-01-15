#include <string>

using std::string;

class Solution {
private:
    int result = 0;

public:
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            expandAroundCenter(s, i, i);
            expandAroundCenter(s, i, i + 1);
        }
    }

private:
    void expandAroundCenter(string s, int left, int right) {
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            left--, right++;
            result++;
        }
    }
};

