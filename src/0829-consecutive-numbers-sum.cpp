// Given a positive integer n, how many ways can we write it as a sum of consecutive positive integers?

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int i = 1; (i - 1) * i < 2 * n; i++) {
            if ((n - (i - 1) * i / 2) % i == 0) {
                ans++;
            }
        }
        return ans;
    }
};
