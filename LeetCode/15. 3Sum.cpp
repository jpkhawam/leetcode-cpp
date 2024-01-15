#include <vector>
#include <cstddef>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // sorting the array and fixing one pointer reduces the solution to the sorted 2sum problem
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++) {
            // should not have two combinations that start with the same number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            size_t left = i + 1;
            size_t right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) right--;
                else if (sum < 0) left++;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    // the left pointer shouldn't point to the same number twice
                    while (nums[left] == nums[left - 1] && left < right) left++;
                }
            }
        }
        return res;
    }
};
