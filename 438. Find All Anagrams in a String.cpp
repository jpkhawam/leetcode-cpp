#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> sCount;
        unordered_map<char, int> pCount;

        int left = 0;
        int right = (int) p.length() - 1;

        for (int i = 0; i < p.length(); i++) pCount[p[i]]++;
        for (int i = left; i <= right; i++) sCount[s[i]]++;

        while (right < s.length()) {
            bool isAnagram = true;
            for (auto it = pCount.begin(); it != pCount.end(); ++it) {
                if (sCount[it->first] != pCount[it->first]) {
                    isAnagram = false;
                    break;
                }
            }
            if (isAnagram) result.push_back(left);
            sCount[s[left]]--;
            left++;
            right++;
            if (right != s.length()) sCount[s[right]]++;
        }
        return result;
    }
};
