// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:
 // [
 //  "((()))",
 //  "(()())",
 //  "(())()",
 //  "()(())",
 //  "()()()"
 // ]
 
//my stupid recursive solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) {
            ans = {};
        }
        else if (n == 1) {
            ans = {"()"};
        } else {
            for (int i = 1; i < n; i++) {
                for (auto& s1 : generateParenthesis(i)) {
                    for (auto& s2 : generateParenthesis(n - i)) {
                        ans.push_back(s1 + s2);
                    }
                }
            }
            for (auto& s : generateParenthesis(n - 1)) {
                ans.push_back("(" + s + ")");
            }
            set<string> ss(ans.begin(), ans.end());
            ans.clear();
            for (auto& s : ss) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};


// backtrace solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) {
            ans = {""};
        } else {
            for (int i = 0; i < n; i++) {
                for (auto& s1 : generateParenthesis(i)) {
                    for (auto& s2 : generateParenthesis(n - i - 1)) {
                        ans.push_back("(" + s1 + ")" + s2);
                    }
                }
            }
        }
        return ans;
    }
};

// another solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};
