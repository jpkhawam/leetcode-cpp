#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for (int num: nums)
            count[num]++;
        for (auto pair: count)
            freq[pair.second].push_back(pair.first);

        vector<int> result;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n: freq[i]) {
                result.push_back(n);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};

