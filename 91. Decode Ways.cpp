#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        vector<int> mem(s.size() + 1, -1);
        mem[s.size()] = 1;
        return decodeWays(0, s, mem);
    }

private:
    int decodeWays(int i, string &s, vector<int> &mem) {
        if (mem[i] > -1) {
            return mem[i];
        } else if (s[i] == '0') {
            return mem[i] = 0;
        }
        int res = decodeWays(i + 1, s, mem);
        if (i < s.size() - 1 and (s[i] == '1' or s[i] == '2' and s[i + 1] < '7')) {
            res += decodeWays(i + 2, s, mem);
        }
        return mem[i] = res;
    }
};

