#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], currSum = 0;
        for (int num: nums) {
            if (currSum < 0) currSum = 0;
            currSum += num;
            if (currSum > maxSub) maxSub = currSum;
        }
        return maxSub;
    }
};

