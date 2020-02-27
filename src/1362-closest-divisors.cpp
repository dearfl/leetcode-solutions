// Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
// Return the two integers in any order.
 
 // Example 1:
 // Input: num = 8
 // Output: [3,3]
 // Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
 //
 // Example 2:
 // Input: num = 123
 // Output: [5,25]
 //
 // Example 3:
 // Input: num = 999
 // Output: [40,25]
 // Constraints: 1 <= num <= 10^9

// 1st sub
class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans;
        int n1 = 1, n2 = num + 2;
        for (int i = 1; i * i <= num + 2; i++) {
            if ((num + 1) % i == 0) {
                if ((num + 1) / i - i < n2 - n1) {
                    n1 = i, n2 = (num + 1) / i;
                }
            }
            if ((num + 2) % i == 0) {
                if ((num + 2) / i - i < n2 - n1) {
                    n1 = i, n2 = (num + 2) / i;
                }
            }
        }
        ans.push_back(n1);
        ans.push_back(n2);
        return ans;
    }
};

// others' solution
class Solution {
public:
    int closestDivisor(int num) {
        int i = sqrt(num);
        while (num % i) { i--; }
        return i;
    }
    vector<int> closestDivisors(int num) {
        int n1 = closestDivisor(num + 1), n2 = closestDivisor(num + 2);
        if ((num + 1) / n1 - n1 < (num + 2) / n2 - n2) {
            return vector<int>{n1, (num + 1) / n1};
        }
        return vector<int>{n2, (num + 2) / n2};
    }
};
