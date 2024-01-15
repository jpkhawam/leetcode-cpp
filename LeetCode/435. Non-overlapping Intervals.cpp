#include <vector>
#include <algorithm>

using std::vector;

class Solution {
private:
    static bool sortIntervalsComp(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), sortIntervalsComp);
        int numberToErase = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if (start >= prevEnd) {
                prevEnd = end;
            } else {
                numberToErase++;
                // by keeping the interval that ends before the second, we minimize our chances of overlapping
                // with the remaining intervals
                prevEnd = std::min(end, prevEnd);
            }
        }
        return numberToErase;
    }
};

