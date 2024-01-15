#include <vector>

using std::vector;

class Solution {
private:
    vector<vector<int>> solution;

    void findPaths(vector<vector<int>> &graph, vector<int> &currentPath) {
        int lastElement = currentPath.back();
        for (int node: graph[lastElement]) {
            if (node == graph.size() - 1) {
                currentPath.push_back(node);
                solution.push_back(currentPath);
                currentPath.pop_back();
            }
            currentPath.push_back(node);
            findPaths(graph, currentPath);
            currentPath.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        findPaths(graph, *new vector<int>({0}));
        return solution;
    }
};
