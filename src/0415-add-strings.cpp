/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:
    Input: num1 = "11", num2 = "123"
    Output: "134"
Example 2:
    Input: num1 = "456", num2 = "77"
    Output: "533"
Example 3:
    Input: num1 = "0", num2 = "0"
    Output: "0"

Constraints:
    1 <= num1.length, num2.length <= 10^4
    num1 and num2 consist of only digits.
    num1 and num2 don't have any leading zeros except for the zero itself.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> str;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int k = 0;
            if (i >= 0) {
                k += num1[i] - '0';
            }
            if (j >= 0) {
                k += num2[j] - '0';
            }
            str.push_back(k);
        }
        str.push_back(0);
        for (int i = 0; i < str.size() - 1; i++) {
            str[i+1] += str[i] / 10;
            str[i] %= 10;
        }
        string res;
        for (int i = str.back() ? str.size() - 1 : str.size() - 2; i >= 0; i--) {
            res += str[i] + '0';
        }
        return res;
    }
};
