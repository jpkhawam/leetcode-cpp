#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        // pass twice over the vector. first time take into consideration the first element, but not the last
        // second time, do the opposite
        // order is [..., prev2, prev1, nums[i], ...]
        int prev2 = 0, prev1 = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int tmp = prev1;
            prev1 = std::max(prev2 + nums[i], prev1);
            prev2 = tmp;
        }
        // store result of taking first element but not last
        int result = prev1;
        // reset values
        prev1 = 0, prev2 = 0;
        // start from second element
        for (int i = 1; i < nums.size(); i++) {
            int tmp = prev1;
            prev1 = std::max(prev2 + nums[i], prev1);
            prev2 = tmp;
        }
        return std::max(result, prev1);
    }
};

