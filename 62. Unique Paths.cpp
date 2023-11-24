#include <vector>

using std::vector;

class Solution {
public:
    int uniquePaths(int rows, int cols) {
        // start from bottom-most row. all values are 1 as we can only go right from each cell
        vector<int> bottomRow(cols, 1);
        // you need to create m - 1 more rows, starting from bottom up each time
        for (int i = 0; i < rows - 1; i++) {
            vector<int> newRow(cols, 1);
            // don't check the right-most column as that one 1) would go out of bound checking right
            // and 2) all the values will be 1 anyway (can only go down)
            for (int j = cols - 2; j > -1; j--) {
                // each cell is equal to the value of the bottom + right cells
                newRow[j] = newRow[j + 1] + bottomRow[j];
            }
            bottomRow = newRow;
        }
        return bottomRow[0];
    }
};

