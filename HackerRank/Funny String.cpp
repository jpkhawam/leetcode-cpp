#include <bits/stdc++.h>

using namespace std;

string funnyString(string s) {
    string s_reverse;
    for (int i = s.length() - 1; i > -1; i--)
        s_reverse += s[i];
    for (int i = 0; i < s.length() - 1; i++)
        if (std::abs(s[i] - s[i + 1]) != std::abs(s_reverse[i] - s_reverse[i + 1]))
            return "Not Funny";
    return "Funny";
}

