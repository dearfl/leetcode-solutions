// Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
//
// Every house can be warmed, as long as the house is within the heater's warm radius range. 
//
// Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
//
// Notice that all the heaters follow your radius standard, and the warm radius will the same.
//

class Solution {
public:
    bool helper(vector<int>& houses, vector<int>& heaters, int dis) {
        int idx = 0;
        for (auto h : houses) {
            if (abs(heaters[idx] - h) <= dis) {
                continue;
            }
            while (idx < heaters.size() && abs(heaters[idx] - h) > dis) {
                idx++;
            }
            if (idx == heaters.size()) {
                return true;
            }
        }
        return false;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 1e9 + 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (helper(houses, heaters, mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
