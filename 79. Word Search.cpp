#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    vector<vector<char>> board;
    string word;
    int rows{}, cols{};

public:
    bool exist(vector<vector<char>> &BOARD, string WORD) {
        init(BOARD, WORD);
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (board[r][c] == word[0] && dfs(0, r, c))
                    return true;
        return false;
    }

private:
    bool dfs(int index, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index])
            return false;
        if (index == word.size() - 1)
            return true;

        board[r][c] = '#';
        if (dfs(index + 1, r - 1, c) ||
            dfs(index + 1, r + 1, c) ||
            dfs(index + 1, r, c - 1) ||
            dfs(index + 1, r, c + 1))
            return true;
        board[r][c] = word[index];
        return false;
    }

    void init(vector<vector<char>> &BOARD, string WORD) {
        board = BOARD;
        word = WORD;
        rows = board.size(), cols = board[0].size();
    }
};

