#include <string>
#include <cassert>

bool is_palindrome(const std::string &s) {
    using std::isalnum, std::tolower;

    size_t left = 0;
    size_t right = s.length() - 1;
    while (left < right) {
        if (!isalnum(s.at(left))) {
            left++;
        } else if (!isalnum(s.at(right))) {
            right--;
        } else if (tolower(s.at(left)) != tolower(s.at(right))) {
            return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}

int main() {
    const std::string valid_palindrome = "A man, a plan, a canal: Panama";
    const std::string invalid_palindrome = "race a car";
    assert(is_palindrome(valid_palindrome));
    assert(!is_palindrome(invalid_palindrome));
}
