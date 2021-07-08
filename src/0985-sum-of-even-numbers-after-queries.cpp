// We have an array nums of integers, and an array queries of queries.
//
// For the i-th query val = queries[i][0], index = queries[i][1], we add val to nums[index].  Then, the answer to the i-th query is the sum of the even values of A.
//
// (Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array nums.)
//
// Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int s = 0;
        for (const auto n : nums) {
            if (n % 2 == 0) {
                s += n;
            }
        }
        for (const auto query : queries) {
            int val = query[0], idx = query[1];
            int v1 = nums[idx], v2 = v1 + val;
            s -= v1 % 2 == 0 ? v1 : 0;
            s += v2 % 2 == 0 ? v2 : 0;
            nums[idx] += val;
            ans.push_back(s);
        }
        return ans;
    }
};
