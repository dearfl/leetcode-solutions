// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// 
 // Example:
 // Given nums = [2, 7, 11, 15], target = 9,
 // Because nums[0] + nums[1] = 2 + 7 = 9,
 // return [0, 1].
//
//

// naive O(n^2) solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            for (auto it2 = it + 1; it2 != nums.end(); ++it2) {
                if (*it + *it2 == target) {
                    res.push_back(it - nums.begin());
                    res.push_back(it2 - nums.begin());
                }
            }
        }
        return res;
    }
};

// O(n) solution use hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> indices;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            indices[*it] = it - nums.begin();
        }
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (indices.find(target - *it) != indices.end() && it - nums.begin() != indices[target - *it]) {
                res.push_back(it - nums.begin());
                res.push_back(indices[target - *it]);
                break;
            }
        }
        return res;
    }
};

// optimized O(n) solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> indices;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (indices.find(target - *it) != indices.end()) {
                res.push_back(indices[target - *it]);
                res.push_back(it - nums.begin());
                break;
            }
            indices[*it] = it - nums.begin();
        }
        return res;
    }
};
