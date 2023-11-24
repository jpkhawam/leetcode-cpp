#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int result = *std::max_element(nums.begin(), nums.end());
        int currMin = 1, currMax = 1;
        for (int num: nums) {
            if (num == 0) {
                currMin = 1, currMax = 1;
                continue;
            }
            int tempCurrMax = currMax;
            currMax = max(num * currMax, num * currMin, num);
            currMin = min(num * tempCurrMax, num * currMin, num);
            result = std::max(result, currMax);
        }
        return result;
    }

private:
    int max(int first, int second, int third) {
        return std::max(std::max(first, second), third);
    }

    int min(int first, int second, int third) {
        return std::min(std::min(first, second), third);
    }
};

