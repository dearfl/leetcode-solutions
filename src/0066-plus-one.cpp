// Given a non-empty array of decimal digits representing a non-negative
// integer, increment one to the integer.
//
// The digits are stored such that the most significant digit is at the head of
// the list, and each element in the array contains a single digit.
//
// You may assume the integer does not contain any leading zero, except the
// number 0 itself.
//

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            *it += carry;
            carry = (*it) / 10;
            *it %= 10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
