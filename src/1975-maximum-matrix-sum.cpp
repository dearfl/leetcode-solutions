// You are given an n x n integer matrix. You can do the following operation any number of times:
//
// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.
//
// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
//
//

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long cnt = 0, ans = 0, minv = 1e6;
        for (const auto v : matrix) {
            for (const auto n : v) {
                if (n < 0) {
                    cnt++;
                }
                if (minv > abs(n)) {
                    minv = abs(n);
                }
                ans += abs(n);
            }
        }
        return ans - (cnt % 2 ? 2 * minv : 0);
    }
};
