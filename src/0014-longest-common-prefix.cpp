// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Note: All given inputs are in lowercase letters a-z.
//
//
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size() ? INT_MAX : 0;
        for (auto& str : strs) {
            len = len > str.length() ? str.length() : len;
        }
        for (int i = 0; i < len; i++) {
            for (auto& str : strs) {
                if (str[i] != strs[0][i]) {
                    len = i;
                    break;
                }
            }
        }
        if (strs.size() == 0) {
            return "";
        }
        return strs[0].substr(0, len);
    }
};

//2nd sub
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        int len = INT_MAX;
        for (auto& str : strs) {
            len = len > str.length() ? str.length() : len;
        }
        for (int i = 0; i < len; i++) {
            for (auto& str : strs) {
                if (str[i] != strs[0][i]) {
                    len = i;
                    break;
                }
            }
        }
        return strs[0].substr(0, len);
    }
};
 
