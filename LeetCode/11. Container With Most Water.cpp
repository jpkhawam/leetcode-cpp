#include <vector>

using std::vector;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = (int) height.size() - 1;
        int maxArea = -1;
        while (left < right) {
            int currentArea = (right - left) * std::min(height[left], height[right]);
            if (currentArea > maxArea) maxArea = currentArea;
            if (height[left] > height[right]) right--;
            else left++;
        }
        return maxArea;
    }
};
