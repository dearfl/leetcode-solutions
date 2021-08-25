// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vec;
        int ans = INT_MAX;
        for (const auto s : timePoints) {
            int h = stoi(s.substr(0, 2)), m = stoi(s.substr(3));
            vec.push_back(h * 60 + m);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++) {
            int k = vec[i], f = i != vec.size() - 1 ? vec[i + 1] : vec[0] + 24 * 60;
            ans = min(ans, f - k);
        }
        return ans;
    }
};
