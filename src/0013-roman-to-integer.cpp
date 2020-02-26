// // Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:
// Input: "III"
// Output: 3

// Example 2:
// Input: "IV"
// Output: 4

// Example 3:
// Input: "IX"
// Output: 9

// Example 4:
// Input: "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.

// Example 5:
// Input: "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
//
//

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        char pc = 0;
        int val[256] = {0};
        val['M'] = 1000;
        val['D'] = 500;
        val['C'] = 100;
        val['L'] = 50;
        val['X'] = 10;
        val['V'] = 5;
        val['I'] = 1;
        for (auto& c : s) {
            switch (c) {
                case 'M':
                case 'D':
                    ans += val[c]; 
                    if (pc == 'C') {
                        ans -= 200;
                    }
                    break;
                case 'C':
                case 'L':
                    ans += val[c];
                    if (pc == 'X') {
                        ans -= 20;
                    }
                    break;
                case 'X':
                case 'V':
                    ans += val[c];
                    if (pc == 'I') {
                        ans -= 2;
                    }
                    break;
                case 'I':
                    ans += val[c];
                    break;
            }
            pc = c;
        }
        return ans;
    }
};

// ! hashmap solution
int romanToInt(string s) {
    unordered_map<char,int>mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int ans = 0;
    for(int i = 0;i<size(s);i++){
        if(i >0 && mp[s[i-1]] < mp[s[i]]){
            ans -= mp[s[i-1]];  // if the previous char value is less than the current one we remove it and then current my previous char value is added
            ans += mp[s[i]] - mp[s[i-1]];
        }else{
            ans += mp[s[i]];
        }
    }
    return ans;
}

// inspired by hashmap solution
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        char pc = 0;
        int val[256] = {0};
        val['M'] = 1000;
        val['D'] = 500;
        val['C'] = 100;
        val['L'] = 50;
        val['X'] = 10;
        val['V'] = 5;
        val['I'] = 1;
        for (auto& c : s) {
            if (val[pc] < val[c]) {
                ans += val[c] - (val[pc] << 1);
            } else {
                ans += val[c];
            }
            pc = c;
        }
        return ans;
    }
};
