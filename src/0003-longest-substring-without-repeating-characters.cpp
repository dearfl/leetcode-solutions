// Given a string, find the length of the longest substring without repeating characters.
 // Example 1:
 // Input: "abcabcbb"
 // Output: 3
 // Explanation: The answer is "abc", with the length of 3.
 // Example 2:
 // Input: "bbbbb"
 // Output: 1
 // Explanation: The answer is "b", with the length of 1.
 // Example 3:
 // Input: "pwwkew"
 // Output: 3
 // Explanation: The answer is "wke", with the length of 3.
 // Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//

// naive O(n^2) solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for (int first = 0, last = 0; last < s.length(); last++) {
            for (int i = last - 1; i >= first; i--) {
                if (s[i] == s[last]) {
                    first = i + 1;
                    break;
                }
            }
            ans = max(res, last - first + 1);
        }
        return ans;
    }
};


// O(n) solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, index[256] = {0};
        for (int first = 0, last = 0; last < s.length(); last++) {
            first = max(index[s[last]], first);
            ans = max(ans, last - first + 1);
            index[s[last]] = last + 1; //index + 1, because index[] is init'd to all 0.
        }
        return ans;
    }
};
