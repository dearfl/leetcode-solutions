// Given a string s. Return all the words vertically in the same order in which they appear in s.
// Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
// Each word would be put on only one column and that in one column there will be only one word.
//

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans, vec;
        int len = 0;
        for (int i = 0, last = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                vec.push_back(s.substr(last, i - last));
                len = max(len, i - last);
                last = i + 1;
            }
        }
        ans = vector<string>(len);
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < len; j++) {
                ans[j] += j >= vec[i].length() ? ' ' : vec[i][j];
            }
        }
        for (int i = 0; i < len; i++) {
            int last = ans[i].length() - 1;
            while (ans[i][last] == ' ') {
                last--;
            }
            ans[i] = ans[i].substr(0, last + 1);
        }
        return ans;
    }
};
