// An n-bit gray code sequence is a sequence of 2n integers where:
//
// - Every integer is in the inclusive range [0, 2n - 1],
// - The first integer is 0,
// - An integer appears no more than once in the sequence,
// - The binary representation of every pair of adjacent integers differs
//   by exactly one bit, and
// - The binary representation of the first and last integers differs by exactly
//   one bit.
// Given an integer n, return any valid n-bit gray code sequence.
//

// 本质是类似回溯递归的做法，只是这里写成了循环的方式
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n, 0);
        for (int i = 0, k = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                res[k + j] = res[k - j - 1] | k;
            }
            k = k << 1;
        }
        return res;
    }
};

// elegant solution by zhaotian
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n);
        for (int i = 0; i < (1 << n); i++) {
            ans[i] = i ^ (i >> 1);
        }
        return ans;
    }
};
