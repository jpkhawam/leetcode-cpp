#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // first binary search the rows
        // then we only need to search the row before the first invalid element (bigger than target)
        int left = 0;
        int right = (int) matrix.size() - 1;

        int index = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > matrix[mid].front()) {
                index = mid;
                left = mid + 1;
            } else if (target < matrix[mid].front()) {
                right = mid - 1;
            } else {
                return true;
            }
        }

        if (index == -1)
            return false;

        // if we reached here, we need to do a regular binary search on matrix[index]
        left = 1;
        right = (int) matrix[index].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > matrix[index][mid]) {
                left = mid + 1;
            } else if (target < matrix[index][mid]) {
                right = mid - 1;
            } else return true;
        }
        return false;
    }
};
