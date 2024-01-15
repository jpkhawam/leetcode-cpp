#include <iostream>
#include <vector>
#include <cassert>
#include <optional>
#include <unordered_map>

using std::vector, std::tuple, std::make_tuple, std::optional, std::unordered_map;

optional<tuple<size_t, size_t>> two_sum(const vector<int> &nums, const int target) {
    unordered_map<int64_t, size_t> map = {};

    for (size_t i = 0; i < nums.size(); i++) {
        if (map.contains(target - nums[i])) {
            return make_tuple(map[target - nums[i]], i);
        }
        map[nums[i]] = i;
    }

    return std::nullopt;
}

int main() {
    const vector nums = {3, 4, 5, 1, 8, 7, 13, 20, 21, 18};
    assert(two_sum(nums, 20).value_or(make_tuple(-1, -1)) == make_tuple(5, 6));
    return 0;
}
