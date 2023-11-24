#include <vector>

using std::vector;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> candidates;
    int target{};

    void combinationSum(int i, vector<int> &curr, int total) {
        if (total == target) {
            result.push_back(curr);
            return;
        } else if (i >= candidates.size() || total > target) {
            return;
        }
        curr.push_back(candidates[i]);
        combinationSum(i, curr, total + candidates[i]);
        curr.pop_back();
        combinationSum(i + 1, curr, total);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &f_candidates, int f_target) {
        this->candidates = f_candidates;
        this->target = f_target;
        combinationSum(0, *new vector<int>, 0);
        return result;
    }
};

