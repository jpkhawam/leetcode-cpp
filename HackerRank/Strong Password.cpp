#include <bits/stdc++.h>

using namespace std;

bool isSpecialCharacter(char c);

int minimumNumber(int n, string password) {
    int minNum = 0;
    bool hasDigit = false, hasSpecialCharacter = false;
    bool hasLowercase = false, hasUppercase = false;
    for (char c: password) {
        if (hasDigit && hasSpecialCharacter && hasLowercase && hasUppercase) {
            break;
        } else if (c >= '0' && c <= '9') {
            hasDigit = true;
        } else if (c >= 'a' && c <= 'z') {
            hasLowercase = true;
        } else if (c >= 'A' && c <= 'Z') {
            hasUppercase = true;
        } else if (isSpecialCharacter(c)) {
            hasSpecialCharacter = true;
        }
    }

    if (!hasDigit) minNum++;
    if (!hasSpecialCharacter) minNum++;
    if (!hasLowercase) minNum++;
    if (!hasUppercase) minNum++;

    if (n + minNum < 6) {
        return 6 - n;
    } else {
        return minNum;
    }
}

bool isSpecialCharacter(char c) {
    switch (c) {
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '*':
        case '(':
        case ')':
        case '-':
        case '+':
            return true;
        default:
            return false;
    }
}

