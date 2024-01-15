#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
private:
    vector<vector<int>> output;
    vector<int> perm; // current permutation to be shared across recursive calls
    unordered_map<int, int> count; // hash map that stores count of each element in array

    void dfs(vector<int> &nums) {
        if (perm.size() == nums.size()) {
            // permutation is done, return
            output.push_back(perm);
            return;
        }

        for (auto pair: count) {
            // pair is [num => count]
            int num = pair.first, num_count = pair.second;
            if (num_count > 0) {
                perm.push_back(num);
                count[num]--;

                dfs(nums);

                // clean up
                count[num]++;
                perm.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        for (int num: nums)
            count[num]++;
        dfs(nums);
        return output;
    }
};
