#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() <= 1) {
            return {nums};
        }

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            // copy nums since it is passed by reference
            vector<int> v(nums.begin(), nums.end());
            // during each iteration, erase the ith element
            v.erase(v.begin() + i);
            // recurse until there is only one element
            auto perms = permute(v);

            for (auto perm: perms) {
                perm.insert(perm.begin(), nums[i]);
                result.push_back(perm);
            }
        }
        return result;
    }
};

/// using std::next_permutation()
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int> &nums) {
//         vector<vector<int>> perms;
//         std::sort(nums.begin(), nums.end());
//         do {
//             perms.push_back(nums);
//         } while (next_permutation(nums.begin(), nums.end()));
//         return perms;
//     }
// };
