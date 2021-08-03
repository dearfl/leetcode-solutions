// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
//
// You may return the answer in any order.
//
//

class Solution {
public:
    int cnt(unsigned s) {
        int ans = 0;
        while (s) {
            ans++;
            s &= s - 1;
        }
        return ans;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        unsigned int s = 0;
        while (s < (1 << n)) {
            if (cnt(s) == k) {
                ans.push_back(vector<int>());
                int tmp = 1;
                for (int i = 0; i < n; i++) {
                    if (tmp & s) {
                        ans.back().push_back(i + 1);
                    }
                    tmp <<= 1;
                }
            }
            s++;
        }
        return ans;
    }
};
