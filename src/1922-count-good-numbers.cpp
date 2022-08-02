// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
//
// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.
//
// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

const int mod = 1000000007;

class Solution {
public:
    long long helper(long long n, int k) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return k;
        }
        long long tmp = helper(n / 2, k) % mod;
        long long s = n % 2 ? k : 1;
        return tmp * tmp % mod * s % mod;
    }

    int countGoodNumbers(long long n) {
        if (n == 1) {
            return 5;
        }
        long long tmp1 = helper(n / 2, 5) % mod;
        long long tmp2 = helper(n / 2, 4) % mod;
        int tmp3 = n % 2 ? 5 : 1;
        return tmp1 * tmp2 % mod * tmp3 % mod;
    }
};
