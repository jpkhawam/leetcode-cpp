#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] > intervals[i][1]) {
                // this interval ends before new interval starts, just add it
                res.push_back(intervals[i]);
            } else if (newInterval[1] < intervals[i][0]) {
                // newInterval ends before next one starts, insert it here, and add remaining intervals before returning
                res.push_back(newInterval);
                for (auto it = intervals.begin() + i; it != intervals.end(); it++)
                    res.push_back(*it);
                return res;
            } else {
                // new interval overlaps with current interval
                // don't add either, instead, change the new interval to be a bigger one encompassing both
                // if result still overlaps with next interval, it will merge with this one on the next iteration of
                // the loop
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        // this case is when new interval is the last element to be inserted (overlaps with last element)
        res.push_back(newInterval);
        return res;
    }
};

