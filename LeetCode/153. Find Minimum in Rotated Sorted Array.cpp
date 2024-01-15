#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = nums[0];
        size_t left = 0, right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] < nums[right]) {
                // array is now sorted
                result = std::min(result, nums[left]);
                break;
            }
            size_t mid = (left + right) / 2;
            result = std::min(result, nums[mid]); // always store the current minimum value you find in result
            if (nums[mid] >= nums[left]) {
                // we are in left sorted portion, minimum will always be to the right
                left = mid + 1;
            } else {
                // we are in right sorted portion, minimum will always be to the left
                right = mid - 1;
            }
        }
        return result;
    }
};

