#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::max;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res{}, left{}, maxFreq{};
        
        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            maxFreq = max(maxFreq, count[s[right]]);
            while (right - left + 1 - maxFreq > k) {
                count[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

