// Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
//
// Return the sorted array.
//

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](auto i1, auto i2) {
            bitset<32> b1(i1), b2(i2);
            return b1.count() < b2.count() || b1.count() == b2.count() && i1 < i2;
        });
        return arr;
    }
};
