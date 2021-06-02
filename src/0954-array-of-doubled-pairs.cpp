// Given an array of integers arr of even length, return true if and only if it
// is possible to reorder it such that arr[2 * i + 1] = 2 * arr[2 * i] for
// every 0 <= i < len(arr) / 2.

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, int> m;
        for (const auto &e: arr) {
            m[e]++;
        }
        for (const auto &e : arr) {
            if (m[e] > 0) {
                m[e]--;
                if (e < 0) {
                    if (e % 2 || m[e/2] == 0) {
                        return false;
                    }
                    m[e/2]--;
                } else {
                    if (m[e*2] == 0) {
                        return false;
                    }
                    m[e*2]--;
                }
            }
        }
        return true;
    }
};
