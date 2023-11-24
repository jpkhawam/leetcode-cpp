#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        size_t left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                // found the target
                return mid;

            // are we in the left sorted portion?
            if (nums[left] <= nums[mid]) {
                if (target > nums[mid] || target < nums[left])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else { // we would be in right sorted portion
                if (target < nums[mid] || target > nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};

