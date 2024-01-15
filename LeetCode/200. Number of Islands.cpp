#include <vector>
#include <algorithm>

using std::vector;

class Solution {
private:
    size_t rows, cols;

    void mark(vector<vector<char>> &grid, size_t i, size_t j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') {
            return;
        }
        // mark cell as 2 to indicate it is land and it has been visited
        grid[i][j] = '2';
        // then go in all directions
        mark(grid, i + 1, j);
        mark(grid, i, j + 1);
        mark(grid, i - 1, j);
        mark(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty())
            return 0;
        int numberOfIslands{};
        rows = grid.size();
        cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    mark(grid, i, j);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }
};

