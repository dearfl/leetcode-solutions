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

