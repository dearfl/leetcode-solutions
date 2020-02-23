// didnt meet 32-bit signed integer requirement
class Solution {
public:
    int reverse(int x) {
        long long res = x < 0 ? -1 : 1;
        long long sum = 0, tmp = labs(x);
        if (x == 0) return 0;
        while (tmp) {
            sum *= 10;
            sum += tmp % 10;
            tmp /= 10;
        }
        if (INT_MIN <= res * sum && res * sum <= INT_MAX)
        return res * sum;
        return 0;
    }
};

// 32-bit signed integer
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
