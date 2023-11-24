#include <vector>
#include <cstdint>

using std::vector;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        // size = amount + 1 because we want to go from 0 -> amount
        // value needs to be greater than amount, can set to INT_MAX or >= amount + 1
        vector<int> dp(amount + 1, INT16_MAX);
        dp[0] = 0;

        for (int currAmount = 1; currAmount <= amount; currAmount++) {
            for (int coin: coins) {
                if (coin <= currAmount) {
                    dp[currAmount] = std::min(dp[currAmount], dp[currAmount - coin] + 1);
                }
            }
        }
        return dp[amount] != INT16_MAX ? dp[amount] : -1;
    }
};

