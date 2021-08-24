// A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
//
// Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
//
//

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto v1, auto v2) {
            return abs(v1[0] - v1[1]) > abs(v2[0] - v2[1]);
        });
        int ans = 0, cnt1 = 0, cnt2 = 0, n = costs.size() / 2;
        for (const auto &v : costs) {
            if (cnt1 < n && cnt2 < n) {
                if (v[0] < v[1]) {
                    cnt1++;
                    ans += v[0];
                } else {
                    cnt2++;
                    ans += v[1];
                }
            } else if (cnt1 == n) {
                ans += v[1];
            } else {
                ans += v[0];
            }
        }
        return ans;
    }
};
