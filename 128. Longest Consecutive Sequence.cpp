#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numSet;
        for (int num: nums) {
            numSet.insert(num);
        }

        int longestStreak{};
        for (int num: numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

