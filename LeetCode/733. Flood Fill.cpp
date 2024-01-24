#include <vector>
#include <set>
#include <cassert>

using std::vector, std::make_pair;

void flood_fill(vector<vector<int>> &image,
                const int sr,
                const int sc,
                const int new_color,
                const int old_color,
                std::set<std::pair<int, int>> &visited_pixels) {

    image[sr][sc] = new_color;

    vector<std::pair<int, int>> next = {
            make_pair(sr - 1, sc),
            make_pair(sr + 1, sc),
            make_pair(sr, sc - 1),
            make_pair(sr, sc + 1)
    };

    for (auto [row, col]: next) {
        if (row < 0 || row >= image.size() || col < 0 || col >= image.front().size()) {
            continue;
        }
        if (image[row][col] == old_color && !visited_pixels.contains(make_pair(row, col))) {
            visited_pixels.insert(make_pair(row, col));
            flood_fill(image, row, col, new_color, old_color, visited_pixels);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    std::set<std::pair<int, int>> set{};
    flood_fill(image, sr, sc, color, image[sr][sc], set);
    return image;
}

int main() {
    vector<vector<int>> image = {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1}
    };
    vector<vector<int>> expected_result = {
            {2, 2, 2},
            {2, 2, 0},
            {2, 0, 1}
    };
    int source_row = 1, source_col = 1, color = 2;
    vector<vector<int>> actual_result = floodFill(image, source_row, source_col, color);
    assert(actual_result == expected_result);
    return 0;
}
