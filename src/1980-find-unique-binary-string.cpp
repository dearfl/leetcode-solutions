// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

class Solution {
public:
    string i2s(int n, int l) {
        string ans(l, '0');
        int i = ans.size() - 1;
        while (n) {
            if (n % 2) {
                ans[i] = '1';
            }
            n /= 2;
            i--;
        }
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> kk(nums.begin(), nums.end());
        vector<string> ss(kk.begin(), kk.end());
        sort(ss.begin(), ss.end());
        int idx = 0;
        for (int i = 0; i <= ss.size(); i++) {
            if (i == ss.size() || i2s(idx, nums.size()) != ss[i]) {
                return i2s(idx, nums.size());
            }
            idx++;
        }
        return "";
    }
};
