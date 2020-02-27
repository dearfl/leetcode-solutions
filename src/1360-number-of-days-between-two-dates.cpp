// Write a program to count the number of days between two dates.
// The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.
//
 // Example 1:
 // Input: date1 = "2019-06-29", date2 = "2019-06-30"
 // Output: 1
 //
 // Example 2:
 // Input: date1 = "2020-01-15", date2 = "2019-12-31"
 // Output: 15
 //
 // Constraints: The given dates are valid dates between the years 1971 and 2100.

//记住2月平年28天，闰年29天！！！
class Solution {
public:
    int daysAfter(string date) {
        vector<int> month{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int y, m, d, ans = 0;
        sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
        for (int i = 1971; i < y; i++) {
            if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
                ans += 366;
            } else {
                ans += 365;
            }
        }
        for (int i = 1; i < m; i++) {
            ans += month[i - 1];
        }
        if (m > 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)) {
            ans += 1;
        }
        ans += d;
        return ans;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(daysAfter(date1) - daysAfter(date2));
    }
};
