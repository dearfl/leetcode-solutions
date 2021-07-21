// Given a string s of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.
//
// Formally, a parentheses string is valid if and only if:
//
// It is the empty string, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
//

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        vector<char> stack;
        for (const auto c : s) {
            if (c == '(') {
                stack.push_back(c);
            } else {
                if (stack.empty()) {
                    ans++;
                } else {
                    stack.pop_back();
                }
            }
        }
        return ans + stack.size();
    }
};

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, open = 0;
        for (const auto c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open == 0) {
                    ans++;
                } else {
                    open--;
                }
            }
        }
        return ans + open;
    }
};
