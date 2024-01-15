#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left{}, res{};
        for (int right = 0; right < s.length(); right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(set.find(s[left]));
                left++;
            }
            set.insert(s[right]);
            res = std::max(res, right - left + 1);
        }
        return res;
    }
};

