#include <optional>
#include <vector>
#include <cassert>

std::optional<size_t> binary_search(const std::vector<int> &nums, const int target) {
    size_t left = 0, right = nums.size() - 1;
    while (left <= right) {
        if (size_t mid = (left + right) / 2; target > nums[mid]) {
            left = mid + 1;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return std::nullopt;
}

int main() {
    assert(binary_search({-1, 0, 3, 5, 9, 12}, 9).value_or(-1) == 4);
    assert(binary_search({-1, 0, 3, 5, 9, 12}, 4).value_or(-1) == -1);
}
