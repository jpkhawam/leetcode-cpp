#include <string>
#include <unordered_map>
#include <cassert>

bool is_anagram(const std::string &str1, const std::string &str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    std::unordered_map<char, int> map{};
    for (auto c: str1) {
        map.insert_or_assign(c, map[c] + 1);
    }

    for (auto c: str2) {
        if (map[c] <= 0) {
            return false;
        }
        map[c]--;
    }
    return true;
}

int main() {
    assert(is_anagram("anagram", "nagaram"));
    assert(!is_anagram("rat", "car"));
}
