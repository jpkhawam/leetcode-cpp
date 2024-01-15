#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // create a 2D grid of size m + 1 * n + 1 (size of two strings)
        // the extra column/row with zeroes for out of bound additions below
        vector<vector<int>> dp(text1.size() + 1, *new vector<int>(text2.size() + 1, 0));
        // start from the bottom corner up
        for (int i = text1.size() - 1; i > -1; i--) {
            for (int j = text2.size() - 1; j > -1; j--) {
                if (text1[i] == text2[j])
                    // for each cell, if it is the same character, the value to fill is the diagonal below + 1
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    // else it is the max between the bottom and the right values
                    dp[i][j] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        // the top left cell will have the LCS value
        return dp[0][0];
    }
};

