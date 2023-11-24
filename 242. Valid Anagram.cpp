#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> map_s, map_t;
        for (int i = 0; i < s.size(); i++) {
            map_s[s[i]]++;
            map_t[t[i]]++;
        }
        for (auto pair: map_s)
            if (map_s[pair.first] != map_t[pair.first])
                return false;
        return true;
    }
};

