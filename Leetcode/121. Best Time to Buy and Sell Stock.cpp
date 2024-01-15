#include <vector>
#include <algorithm>

using std::vector;

int maxProfit(vector<int> &prices) {
    size_t left = 0, right = 1;
    int max = 0;
    while (right < prices.size()) {
        if (prices[left] < prices[right]) {
            int currentProfit = prices[right] - prices[left];
            max = std::max(max, currentProfit);
        } else {
            left = right;
        }
        right++;
    }
    return max;
}

