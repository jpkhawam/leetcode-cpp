#include <string>

using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        // start and end indices of result
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            // check for odd palindromes
            int len1 = expandAroundCenter(s, i, i);
            // check for even palindromes
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end + 1 - start);
    }

private:
    int expandAroundCenter(string s, int left, int right) {
        int l = left, r = right;
        while (l >= 0 and r < s.length() and s[l] == s[r])
            l--, r++;
        return r - l - 1;
    }
};

