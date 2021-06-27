// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
//

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        bool neg = n < 0;
        n = abs(n);
        double tmp = myPow(x, n / 2);
        tmp = tmp * tmp * myPow(x, n % 2);
        return neg ? 1.0 / tmp : tmp;
    }
};
