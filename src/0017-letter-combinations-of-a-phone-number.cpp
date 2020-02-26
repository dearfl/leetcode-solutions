// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example:
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

// Note: Although the above answer is in lexicographical order, your answer could be in any order you want.
//
//

// recursive solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> map{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty()) {
            return {};
        } else if (digits.length() == 1) {
            for (int i = 0; i < map[digits[0] - '2'].length(); i++) {
                ans.push_back(map[digits[0] - '2'].substr(i, 1));
            }
            return ans;
        } else {
            for (int i = 0; i < map[digits[0] - '2'].length(); i++) {
                for (auto& s : letterCombinations(digits.substr(1))) {
                    ans.push_back(map[digits[0] - '2'][i] + s);
                }
            }
            return ans;
        }
    }
};


// queue solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> map{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        queue<string> q;
        q.push("");
        string tmp;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp.length() == digits.length()) {
                if (tmp.length() != 0) {
                    ans.push_back(tmp);
                }
            } else {
                for (int i = 0; i < map[digits[tmp.length()] - '2'].length(); i++) {
                    q.push(tmp + map[digits[tmp.length()] - '2'].substr(i, 1));
                }
            }
        }
        return ans;
    }
};
