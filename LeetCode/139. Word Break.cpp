#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        // dp[i] = can we break the word from index i?
        dp[s.size()] = true;
        for (int i = s.size(); i > -1; i--) {
            for (string &w: wordDict) {
                // check for every word if it is a match at this position
                if (i + w.size() <= s.size() and s.substr(i, w.size()) == w) {
                    // we can word break here as we can also word break from index + word.size()
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]) break;
            }
        }
        // if dp[0] = true it means that we can reach dp[8] from it
        return dp[0];
    }
};

