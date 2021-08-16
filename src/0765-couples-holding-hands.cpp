// There are n couples sitting in 2n seats arranged in a row and want to hold hands.
//
// The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).
//
// Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.
//

class Solution {
public:
    int minSwapsCouples(vector<int>& r) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < r.size(); i++) {
            m[r[i]] = i;
        }
        for (int i = 0; i < r.size(); i += 2) {
            if ((r[i] + r[i+1]) % 2 == 1 && r[i] / 2 == r[i+1] / 2) {
                continue;
            }
            int k = 1 - r[i] % 2 + r[i] / 2 * 2, val = r[i + 1];
            swap(r[i + 1], r[m[k]]);
            m[val] = m[k];
            m[k] = i + 1;
            ans++;
        }
        return ans;
    }
};
