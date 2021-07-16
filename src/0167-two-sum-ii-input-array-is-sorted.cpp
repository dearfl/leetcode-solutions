// Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
//
// Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
//
// The tests are generated such that there is exactly one solution. You may not use the same element twice.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < numbers.size(); i++) {
            if (index.find(numbers[i]) != index.end()) {
                return {index[numbers[i]] + 1, i + 1};
            }
            index[target - numbers[i]] = i;
        }
        return {-1, -1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int l = 0, r = n.size() - 1;
        while (n[l] + n[r] != target) {
            if (n[l] + n[r] > target) {
                r--;
            } else {
                l++;
            }
        }
        return {l + 1, r + 1};
    }
};
