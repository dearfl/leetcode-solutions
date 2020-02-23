// 1st sub
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> digits;
        if (x < 0) return false;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0, j = digits.size() - 1; i < digits.size() / 2; i++, j--) {
            if (digits[i] != digits[j]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) { return false; } //special case such as -1 / 110
        int reverse = 0;
        while (reverse < x) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return x == reverse || reverse / 10 == x; // 1221 -> 12,12  121 -> 12,1
    }
};
