#include <vector>
#include <unordered_map>
#include <cmath>

using std::vector;
using std::unordered_map;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> map; // maps int to index
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end() && std::abs(i - map[nums[i]]) <= k)
                return true;
            else map[nums[i]] = i;
        }
        return false;
    }
};

