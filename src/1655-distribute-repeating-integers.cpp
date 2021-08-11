// You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:
//
// The ith customer gets exactly quantity[i] integers,
// The integers the ith customer gets are all equal, and
// Every customer is satisfied.
// Return true if it is possible to distribute nums according to the above conditions.
//

class Solution {
public:
    bool helper(vector<int> &c, vector<int> &q) {
        function<bool(int)> bt;
        bt = [&](int i) {
            if (i == q.size()) {
                return true;
            }
            int k = q[i];
            for (int j = 0; j < c.size(); j++) {
                if (c[j] >= k) {
                    c[j] -= k;
                    if (bt(i + 1)) {
                        return true;
                    }
                    c[j] += k;
                }
            }
            return false;
        };
        return bt(0);
    }

    bool canDistribute(vector<int>& n, vector<int>& q) {
        int cnt[1001] = { 0 };
        for (const auto i : n) {
            cnt[i]++;
        }
        vector<int> count;
        sort(begin(cnt), end(cnt), greater<int>());
        sort(q.begin(), q.end(), greater<int>());
        for (int i = 0; i < 1001; i++) {
            if (cnt[i] > 0) {
                count.push_back(cnt[i]);
            }
        }
        return helper(count, q);
    }
};
