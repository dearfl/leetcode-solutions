/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

Example 1:
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5
Example 2:
    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4

Constraints:
    1 <= k <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
*/

// quick select by hand
class Solution {
public:
    int randint(int l, int r) {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist(l, r);
        return dist(rng);
    }
    
    int part(vector<int> &nums, int l, int r) {
        int p = randint(l, r);
        int pivot = nums[p];
        // cout << "part " << l << " " << r << " choose " << p << "->" << pivot << " ";
        swap(nums[l], nums[p]);
        while (l < r) {
            while (l < r && nums[r] < pivot) { r--; }
            nums[l] = nums[r];
            while (l < r && nums[l] >= pivot) { l++; }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        // cout << "return " << l << endl;
        return l;
    }
    
    int helper(vector<int> &nums, int l, int r, int k) {
        if (l >= r) {
            return nums[l];
        }
        int idx = part(nums, l, r);
        if (idx == k) {
            return nums[k];
        } else if (k < idx) {
            return helper(nums, l, idx - 1, k);
        } else {
            return helper(nums, idx + 1, r, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size() - 1, k - 1);
    }
};

// quick select by STL
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// priority queue Solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 1; i < k; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
