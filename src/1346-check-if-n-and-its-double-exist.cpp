// Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
//
// More formally check if there exists two indices i and j such that :
//
// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]
//

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (const auto &i : arr) {
            if (s.find(i * 2) != s.end() || i % 2 == 0 && s.find(i / 2) != s.end()) {
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};
