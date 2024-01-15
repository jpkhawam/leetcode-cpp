#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] < intervals[i][0])
                result.push_back(intervals[i]);
            else
                result.back()[1] = std::max(result.back()[1], intervals[i][1]);
        }
        return result;
    }
};

