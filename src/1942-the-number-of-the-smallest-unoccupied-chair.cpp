// There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.
//
// For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
// When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.
//
// You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.
//
// Return the chair number that the friend numbered targetFriend will sit on.
//
//

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        vector<int> ss(20001);
        for (int i = 0; i < ss.size(); i++) {
            ss[i] = i;
        }
        priority_queue<int, vector<int>, greater<int>> sit(ss.begin(), ss.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> arr, lea;
        for (int i = 0; i < times.size(); i++) {
            arr.emplace(times[i][0], times[i][1]);
        }
        while (!arr.empty()) {
            auto [at, af] = arr.top();
            while (!lea.empty() && lea.top().first <= at) {
                auto [lt, ch] = lea.top();
                lea.pop();
                sit.emplace(ch);
            }
            auto pos = sit.top();
            sit.pop();
            if (at == times[t][0]) {
                return pos;
            }
            lea.emplace(af, pos);
            arr.pop();
        }
        return -1;
    }
};
