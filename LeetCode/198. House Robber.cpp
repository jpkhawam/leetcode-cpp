#include <vector>

using std::vector;

class Solution {
public:
    /* the order is: prev2, prev1, num */
    int rob(vector<int> &nums) {
        if (nums.empty()) 
            return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int num: nums) {
            int tmp = prev1;
            prev1 = std::max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};

