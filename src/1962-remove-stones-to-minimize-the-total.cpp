// You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k. You should apply the following operation exactly k times:
//
// Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
// Notice that you can apply the operation on the same pile more than once.
//
// Return the minimum possible total number of stones remaining after applying the k operations.
//
// floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).
//

ass Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans = accumulate(piles.begin(), piles.end(), 0);
        for (const auto p : piles) {
            pq.push(p);
        }
        for (int i = 0; i < k; i++) {
            int n = pq.top();
            ans -= n / 2;
            pq.pop();
            pq.push(n - n / 2);
        }
        return ans;
    }
};
