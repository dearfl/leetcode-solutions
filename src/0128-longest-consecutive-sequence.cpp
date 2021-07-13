// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//
// You must write an algorithm that runs in O(n) time.
//

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ns(nums.begin(), nums.end());
        int ans = 0;
        for (const auto n : nums) {
            if (ns.find(n) == ns.end()) {
                continue;
            }
            ns.erase(n);
            int pre = n - 1, next = n + 1;
            while (ns.find(pre) != ns.end()) {
                ns.erase(pre);
                pre--;
            }
            while (ns.find(next) != ns.end()) {
                ns.erase(next);
                next++;
            }
            ans = max(ans, next - pre - 1);
        }
        return ans;
    }
};
