#include <bits/stdc++.h>

using namespace std;

int getHeight(vector<int> &h) {
    int height = 0;
    for (auto i: h)
        height += i;
    return height;
}

bool notEqual(int ht1, int ht2, int ht3) {
    return ht1 != ht2 || ht1 != ht3 || ht2 != ht3;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    vector<vector<int>> vectors({{}, h1, h2, h3});
    vector<int> height({0, getHeight(h1), getHeight(h2), getHeight(h3)});

    while (notEqual(height[1], height[2], height[3])) {
        int max_height = max(max(height[1], height[2]), height[3]);
        for (int i = 1; i <= 3; i++) {
            if (height[i] == max_height) {
                height[i] -= vectors[i].at(0);
                vectors[i].erase(vectors[i].begin());
            }
        }
    }
    return height[1];
}

