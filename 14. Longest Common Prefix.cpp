#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result;
        for (int i = 0; i < strs[0].size(); i++) {
            for (auto &str: strs) {
                if (i >= str.size() || str[i] != strs[0][i])
                    return result;
            }
            result += strs[0][i];
        }
        return result;
    }
};

