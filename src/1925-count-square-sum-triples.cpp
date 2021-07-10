// A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
//
// Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
//

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = i + 1; k <= n; k++) {
                    if (i * i + j * j == k * k) {
                        ans += 2;
                    }
                }
            }
        }
        return ans;
    }
};
