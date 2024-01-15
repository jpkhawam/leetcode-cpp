#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
private:
    string getKey(string str) {
        std::sort(str.begin(), str.end());
        return str;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (const string& str: strs)
            map[getKey(str)].push_back(str);

        vector<vector<string>> result;
        for(const auto& pair: map)
            result.push_back(pair.second);
        return result;
    }
};

