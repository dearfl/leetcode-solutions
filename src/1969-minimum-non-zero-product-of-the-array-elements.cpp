// You are given a positive integer p. Consider an array nums (1-indexed) that consists of the integers in the inclusive range [1, 2p - 1] in their binary representations. You are allowed to do the following operation any number of times:
//
// Choose two elements x and y from nums.
// Choose a bit in x and swap it with its corresponding bit in y. Corresponding bit refers to the bit that is in the same position in the other integer.
// For example, if x = 1101 and y = 0011, after swapping the 2nd bit from the right, we have x = 1111 and y = 0001.
//
// Find the minimum non-zero product of nums after performing the above operation any number of times. Return this product modulo 10^9 + 7.
//
// Note: The answer should be the minimum product before the modulo operation is done.
//

class Solution {
public:
    const int mod = 1e9 + 7;
    long long helper(long long b, long long k) {
        if (k == 0) {
            return 1;
        }
        unsigned long long x = helper(b, k / 2) % mod;
        return x * x % mod * (k % 2 == 1 ? b % mod : 1) % mod;
    }
    int minNonZeroProduct(int p) {
        long long ans = 1;
        long long k = (1ll << p) - 2;
        return helper(k, k / 2) % mod * ((k + 1) % mod) % mod;
    }
};
