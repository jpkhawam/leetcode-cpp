class Solution {
public:
    int climbStairs(int n) {
        // start at the end of the array
        // there is one way to reach the end from the end (two is the right/end pointer)
        // and from the one right before the end, there is also one way to reach the end (one is the left/start pointer)
        // what is the value of the one right before them? it's the sum of these two
        // so just shifting these values n - 1 times gives us the end result
        int one = 1, two = 1;
        for (int i = 0; i < n - 1; i++) {
            int tmp = one;
            one = one + two;
            two = tmp;
        }
        return one;
    }
};

