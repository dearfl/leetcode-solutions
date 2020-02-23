// O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), max_len = 0, first = 0;
        for (int i = 0; i < len; i++) {
            //odd length
            for (int j = i, k = i; j < len && k >= 0 && s[j] == s[k]; j++, k--) {
                if (j - k + 1 > max_len) {
                    max_len = j - k + 1;
                    first = k;
                }
            }
            //even length
            for (int j = i + 1, k = i; j < len && k >= 0 && s[j] == s[k]; j++, k--) {
                if (j - k + 1 > max_len) {
                    max_len = j - k + 1;
                    first = k;
                }
            }
        }
        return s.substr(first, max_len);
    }
};
