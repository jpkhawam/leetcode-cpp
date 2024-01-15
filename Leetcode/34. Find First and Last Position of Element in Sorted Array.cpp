#include <vector>

using std::vector;

class Solution {
public:
    int binarySearch(vector<int> &nums, int target, bool leftBias) {
        int left{};
        int right = (int) nums.size() - 1;

        int index = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                index = mid;
                if (leftBias) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return index;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }
};
