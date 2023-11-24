#include <vector>
#include <algorithm>

using std::vector;

class Solution {
private:
    vector<bool> visited;
    size_t numberOfNodes{};
    int numberOfSets{};

    void dfs(vector<vector<int>> &isConnected, int i) {
        visited[i] = true;
        for (int j = 0; j < numberOfNodes; j++) {
            if (isConnected[i][j] && !visited[j]) {
                dfs(isConnected, j);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        numberOfNodes = isConnected.size();
        if (numberOfNodes == 0) {
            return 0;
        }
        visited = *new vector<bool>(numberOfNodes, false);
        for (int i = 0; i < numberOfNodes; i++) {
            if (!visited[i]) {
                numberOfSets++;
                dfs(isConnected, i);
            }
        }
        return numberOfSets;
    }
};
