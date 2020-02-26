// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:
// Input: "()"
// Output: true

// Example 2:
// Input: "()[]{}"
// Output: true

// Example 3:
// Input: "(]"
// Output: false

// Example 4:
// Input: "([)]"
// Output: false

// Example 5:
// Input: "{[]}"
// Output: true
//
//

// 1st sub
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto& c : s) {
            switch (c) {
                case '[':
                case '{':
                case '(':
                    stk.push(c);
                    break;
                case ']':
                    if (stk.empty() || stk.top() != '[') {
                        return false;
                    }
                    stk.pop();
                    break;
                case '}':
                    if (stk.empty() || stk.top() != '{') {
                        return false;
                    }
                    stk.pop();
                    break;
                case ')':
                    if (stk.empty() || stk.top() != '(') {
                        return false;
                    }
                    stk.pop();
                    break;
            }
        }
        return stk.empty();
    }
};

// 2nd sub
class Solution {
public:
    bool isMatchChar(char c1, char c2) {
        // !order
        return c1 == '[' && c2 == ']' || c1 == '(' && c2 == ')' || c1 == '{' && c2 == '}';
    }
    bool isValid(string s) {
        stack<char> stk;
        for (auto& c : s) {
            if (c == ']' || c == '}' || c == ')') {
                if (stk.empty() || !isMatchChar(stk.top(), c)) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
