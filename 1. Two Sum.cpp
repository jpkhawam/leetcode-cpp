#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums.at(i)) != map.end()) {
                return {map.at(target - nums.at(i)), i};
            } else {
                map[nums.at(i)] = i;
            }
        }
        return {-1, -1};
    }
};
