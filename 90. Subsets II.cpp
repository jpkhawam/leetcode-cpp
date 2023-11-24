#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> output;

    void backtrack(int index, vector<int> &curr, vector<int> &nums) {
        if (index == nums.size()) {
            output.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        backtrack(index + 1, curr, nums);
        curr.pop_back();
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
        backtrack(index + 1, curr, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        backtrack(0, *new vector<int>, nums);
        return output;
    }
};

