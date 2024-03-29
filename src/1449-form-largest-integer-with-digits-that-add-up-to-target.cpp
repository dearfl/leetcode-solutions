/*
Given an array of integers cost and an integer target, return the maximum integer you can paint under the following rules:

The cost of painting a digit (i + 1) is given by cost[i] (0-indexed).
The total cost used must be equal to target.
The integer does not have 0 digits.
Since the answer may be very large, return it as a string. If there is no way to paint any integer given the condition, return "0".

Example 1:
    Input: cost = [4,3,2,5,6,7,2,5,5], target = 9
    Output: "7772"
    Explanation: The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also paint "977", but "7772" is the largest number.
    Digit    cost
      1  ->   4
      2  ->   3
      3  ->   2
      4  ->   5
      5  ->   6
      6  ->   7
      7  ->   2
      8  ->   5
      9  ->   5
Example 2:
    Input: cost = [7,6,5,5,5,6,8,7,8], target = 12
    Output: "85"
    Explanation: The cost to paint the digit '8' is 7, and the digit '5' is 5. Then cost("85") = 7 + 5 = 12.
Example 3:
    Input: cost = [2,4,6,2,4,6,4,4,4], target = 5
    Output: "0"
    Explanation: It is impossible to paint any integer with total cost equal to target.

Constraints:
    cost.length == 9
    1 <= cost[i], target <= 5000
*/

class Solution {
public:
    bool sless(string &s1, string &s2) {
        return s1.length() < s2.length() || s1.length() == s2.length() && s1 < s2;
    }
    
    string comb(string &s, char digit) {
        string res = s + digit;
        sort(res.begin(), res.end(), greater<char>());
        return res;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp;
        dp.push_back("0");
        map<int, char> _map;
        for (int i = 0; i < cost.size(); i++) {
            _map[cost[i]] = '1' + i;
        }
        for (int i = 1; i <= target; i++) {
            dp.push_back("0");
            // cout << i << " 0";
            for (const auto &[k, v] : _map) {
                int j = i - k;
                if (j == 0) {
                    string m = string(1, v);
                    if (sless(dp[i], m)) {
                        // cout << ' ' << m;
                        dp[i] = m;
                    }
                }
                else if (j > 0 && dp[j] != "0") {
                    string s = comb(dp[j], v);
                    if (sless(dp[i], s)) {
                        // cout << ' ' << s;
                        dp[i] = s;
                    }
                }
            }
            // cout << endl;
        }
        return dp[target];
    }
};
