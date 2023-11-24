#include <bits/stdc++.h>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    // an easier operation is shifting to the right
    // shifting to the left n times is equal to shifting to the right arr.size() - n times
    d = arr.size() - d;
    while (d > 0) {
        arr.insert(arr.begin(), arr.at(arr.size() - 1));
        arr.erase(arr.end() - 1);
        d--;
    }
    return arr;
}

