// We have two integer sequences nums1 and nums2 of the same non-zero length.
//
// We are allowed to swap elements nums1[i] and nums2[i]. Note that both
// elements are in the same index position in their respective
// sequences.
//
// At the end of some number of swaps, nums1 and nums2 are both strictly
// increasing. (An array A is strictly increasing if and only if A[0] < A[1] <
// A[2] < ... < A[A.length - 1].)
//
// Given nums1 and nums2, return the minimum number of swaps to make both
// sequences strictly increasing. It is guaranteed that the given input always
// makes it possible.

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp1(n, n), dp0(n, n);
        dp1[0] = 1;
        dp0[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i] && nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i]) {
                dp1[i] = min(dp0[i - 1], dp1[i - 1]) + 1;
                dp0[i] = min(dp0[i - 1], dp1[i - 1]);
            } else if (nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]) {
                dp1[i] = dp1[i - 1] + 1;
                dp0[i] = dp0[i - 1];
            } else {
                dp1[i] = dp0[i - 1] + 1;
                dp0[i] = dp1[i - 1];
            }
        }
        return min(dp0[n - 1], dp1[n - 1]);
    }
};
