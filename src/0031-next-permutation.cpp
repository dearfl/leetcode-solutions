// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
//
// The replacement must be in place and use only constant extra memory.


// 第一个版本，思路
// 假设区间[1,n]
// 1. 找到使得[i, n]非严格单调递减的最大下标i
// 2. 反转[i,n]区间
// 3. 如果i等于1，算法结束
// 4. 找到[i,n]区间中第一个大于A_{i-1}的数A_k，即upper_bound
// 5. 交换A_k和A_{i-1}

class Solution {
public:
    void helper(vector<int>::iterator first, vector<int>::iterator last) {
        auto it = last - 1;
        while (it != first && *(it - 1) >= *it) {
            it--;
        }
        sort(it, last);
        if (it != first) {
            auto k = it - 1;
            while (it != last - 1 && *k >= *it) {
                it++;
            }
            swap(*k, *it);
        }
    }

    void nextPermutation(vector<int>& nums) {
        helper(nums.begin(), nums.end());
    }
};

// 第二个版本，加入了一些简单的优化
class Solution {
public:
    void helper(vector<int>::iterator first, vector<int>::iterator last) {
        auto it = last - 1;
        while (it != first && *(it - 1) >= *it) {
            it--;
        }
        reverse(it, last);
        if (it != first) {
            auto iter = upper_bound(it, last, *(it - 1));
            swap(*(it - 1), *iter);
        }
    }

    void nextPermutation(vector<int>& nums) {
        helper(nums.begin(), nums.end());
    }
};
