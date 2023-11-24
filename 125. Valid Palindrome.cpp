#include <string>

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        size_t left = 0, right = s.length() - 1;
        while (left <= right) {
            if (left == right)
                return true;
            else if (!std::isalnum(s[left]))
                left++;
            else if (!std::isalnum(s[right]))
                right--;
            else if (std::tolower(s[left]) != std::tolower(s[right]))
                return false;
            else
                left++, right--;
        }
        return true;
    }
};

