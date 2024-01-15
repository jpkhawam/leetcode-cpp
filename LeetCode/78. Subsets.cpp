#include <vector>

using std::vector;

class Solution {
private:
    vector<vector<int>> output;

    void backtrack(int index, vector<int> &curr, vector<int> &nums) {
        if (index == nums.size()) {
            output.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        backtrack(index + 1, curr, nums);
        curr.pop_back();
        backtrack(index + 1, curr, nums);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        backtrack(0, *new vector<int>, nums);
        return output;
    }
};
