#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> intersection;
        for (auto curr: firstList) {
            for (auto it = secondList.begin(); it < secondList.end(); it++) {
                // if the end of this interval is before the start of this one
                // we can remove it as it is no longer useful
                if (it->at(1) < curr.at(0)) {
                    secondList.erase(it);
                    it--;
                } else if (it->at(0) > curr.at(1)) {
                    // if the interval from second list starts after the interval
                    // from first list we can move on to the next item from first list
                    continue;
                } else if (it->at(0) >= curr.at(0) || it->at(1) >= curr.at(0)) {
                    int maxStart = std::max(curr.at(0), it->at(0));
                    int minEnd = std::min(curr.at(1), it->at(1));
                    intersection.push_back(std::vector<int>({maxStart, minEnd}));
                }
            }
        }
        return intersection;
    }
};
