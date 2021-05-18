// Given two non-negative integers num1 and num2 represented as strings, return
// the product of num1 and num2, also represented as a string.
//
// Note: You must not use any built-in BigInteger library or convert the inputs
// to integer directly.

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> result(m + n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp1 = num1[m - i - 1] - '0', tmp2 = num2[n - j - 1] - '0';
                result[i + j] += tmp1 * tmp2;
            }
        }

        for (int i = 0; i < m + n - 1; i++) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
        int i = m + n - 1;
        while (i >= 0 && result[i] == 0) {
            i--;
        }
        i = max(i, 0);
        string ret = "";
        for ( ; i >= 0; i--) {
            ret += ('0' + result[i]);
        }
        return ret;
    }
};

