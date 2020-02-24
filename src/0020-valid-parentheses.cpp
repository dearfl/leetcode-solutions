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
