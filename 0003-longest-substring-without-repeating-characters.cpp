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
