#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0;
        int right = (int) numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] > target) right--;
            else if (numbers[left] + numbers[right] < target) left++;
            else break;
        }
        // the problem supposes the array starts at index 1
        return {left + 1, right + 1};
    }
};
