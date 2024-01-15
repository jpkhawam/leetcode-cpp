#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        // initialize a vector to hold the longest increasing subsequence *leading* to each item
        std::vector<int> lis(nums.size(), 1);
        // pass by every element
        for (int i = 0; i < nums.size(); i++) 
            // and check only the elements that *precede* it
            for (int j = 0; j < i; j++) 
                // if the number is greater AND the lis leading to them is greater than our current lis
                if (nums[i] > nums[j] && lis[i] < lis[j] + 1) 
                    lis[i] = lis[j] + 1;
        return *std::max_element(lis.begin(), lis.end());
    }
};

