// You are given two 0-indexed integer arrays servers and tasks of lengths n and
// m respectively. servers[i] is the weight of the ith server, and tasks[j] is 
// the time needed to process the jth task in seconds.
//
// You are running a simulation system that will shut down after all tasks
// are processed. Each server can only process one task at a time. You will be
// able to process the jth task starting from the jth second beginning with the
// 0th task at second 0. To process task j, you assign it to the server with
// the smallest weight that is free, and in case of a tie, choose the server
// with the smallest index. If a free server gets assigned task j at second
// t, it will be free again at the second t + tasks[j].
//
// If there are no free servers, you must wait until one is free and execute
// the free tasks as soon as possible. If multiple tasks need to be assigned,
// assign them in order of increasing index.
//
// You may assign multiple tasks at the same second if there are multiple free
// servers.
//
// Build an array ans of length m, where ans[j] is the index of the server the
// jth task will be assigned to.
//
// Return the array ans.

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        auto cmp = [](auto p1, auto p2) { return p1.second > p2.second; };
        // same weight lower index
        auto cmpw = [](auto p1, auto p2) { return p1.first + p1.second * 200000ll > p2.first + p2.second * 200000ll; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmpw)> fs(cmpw);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> bs(cmp);
        for (int i = 0; i < servers.size(); i++) {
            // add free server at beginning
            fs.push({i, servers[i]});
        }
        int ct = 0, tIdx = 0;
        vector<int> ans(tasks.size(), -1);
        while (tIdx < tasks.size()) {
            while (!fs.empty() && tIdx <= ct && tIdx < tasks.size()) {
                // if there is any free server
                int sIdx = fs.top().first;
                ans[tIdx] = sIdx;
                bs.push({sIdx, ct + tasks[tIdx]});
                fs.pop();
                tIdx++;
            }
            // if no free server available, we skip as much second as possible
            // to avoid exceeding time limit.
            ct = fs.empty() ? bs.top().second : ct + 1;
            while (!bs.empty() && bs.top().second <= ct) {
                // free server from task
                int sIdx = bs.top().first;
                fs.push({sIdx, servers[sIdx]});
                bs.pop();
            }
        }
        return ans;
    }
};
