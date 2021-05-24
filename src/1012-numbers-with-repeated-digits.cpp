// Given a positive integer n, return the number of positive integers less than
// or equal to n that have at least 1 repeated digit.

class Solution {
public:

    bool hasRepeatedDigit(int n) {
        int count[10] = { 0 };
        int m = 0;
        while (n) {
            m = n % 10;
            if (count[m] > 0) {
                return true;
            }
            count[m]++;
            n /= 10;
        }
        return false;
    }

    int numDupDigitsAtMostN(int n) {
        if (n < 10) {
            return 0;
        }
        int len = to_string(n).length();
        vector<int> digit(len + 1, 0);
        int tmp = n;
        for (int i = 0; i < len; i++) {
            digit[len - i] = tmp % 10;
            tmp /= 10;
        }
        int res = 9;
        int total = res;
        for (int i = 2; i < len; i++) {
            res = res * (10 - i + 1);
            total += res;
        }
        res = digit[1];
        int count = 0;
        tmp = digit[1];
        for (int i = 2; i <= len; i++) {
            res = res * (10 - i + 1);
            count = 0;
            for (int j = tmp * 10 + digit[i] + 1; j <= tmp * 10 + 9; j++) {
                if (!hasRepeatedDigit(j)) {
                    count++;
                }
            }
            res -= count;
            tmp = tmp * 10 + digit[i];
        }
        total += res;
        return n - total;
    }
};
